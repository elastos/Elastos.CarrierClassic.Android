/*
 * Copyright (c) 2020 Elastos Foundation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */


#include <alloca.h>
#include <string.h>

#include <ela_carrier.h>

#include "carrier_ext.h"
#include "extension.h"
#include "log.h"

typedef struct Extension {
    CarrierExtension base;

    void             *user_callback;
    void             *user_context;
} Extension;

static const char *extension_name = "carrier";

extern void *deref(void *);
typedef void (rc_mem_destructor)(void *data);
extern void *rc_zalloc(size_t size, rc_mem_destructor *destructor);

static
void on_friend_invite(ElaCarrier *carrier, const char *from, const char *bundle,
                      const void *data, size_t len, void *context)
{
    Extension *ext = (Extension *)context;
    ExtensionInviteCallback *callback = (ExtensionInviteCallback *)ext->user_callback;

    (void)bundle;

    logD("Extension: Extension request from %s with data: %s", from, (char *)data);

    callback(carrier, from, data, len, ext->user_context);
}

int extension_init(ElaCarrier *carrier, ExtensionInviteCallback *callback, void *context)
{
    Extension *ext;
    ElaCallbacks callbacks;
    int rc;

    if (!carrier) {
        ela_set_error(ELA_GENERAL_ERROR(ELAERR_INVALID_ARGS));
        return -1;
    }

    if (carrier_get_extension(carrier, extension_name)) {
        logD("Extension: Already initialized.");
        return 0;
    }

    ext = (Extension *)rc_zalloc(sizeof(Extension), NULL);
    if (!ext) {
        ela_set_error(ELA_GENERAL_ERROR(ELAERR_OUT_OF_MEMORY));
        return -1;
    }

    memset(&callbacks, 0, sizeof(callbacks));
    callbacks.friend_invite = on_friend_invite;

    ext->base.carrier = carrier;
    ext->user_callback = callback;
    ext->user_context = context;

    rc = carrier_register_extension(carrier, extension_name, &ext->base, &callbacks);
    if (rc != 0)
        deref(ext);

    logD("Extension: Initializing carrier extension %s.", !rc ? "success" : "failed");

    return 0;
}

void extension_cleanup(ElaCarrier *carrier)
{
    Extension *ext;

    if (!carrier)
        return;

    ext = (Extension *)carrier_get_extension(carrier, extension_name);
    if (!ext)
        return;

    carrier_unregister_extension(ext->base.carrier, extension_name);
    deref(ext);
}

static
void on_friend_invite_reply(ElaCarrier *carrier, const char *from,
                            const char *bundle, int status, const char *reason,
                            const void *data, size_t len, void *context)
{
    void **callback_ctx = (void *)context;
    ExtensionInviteReplyCallback *callback = (ExtensionInviteReplyCallback *)callback_ctx[0];
    void *user_ctx = (void *)callback_ctx[1];

    (void)bundle;

    deref(callback_ctx);

    logD("Extension: Extension response from %s with data: %s",
          from, (const char *)data);

    callback(carrier, from, status, reason, data, len, user_ctx);
}

int extension_invite_friend(ElaCarrier *carrier, const char *to,
                            const void *data, size_t len,
                            ExtensionInviteReplyCallback *callback,
                            void *context)
{
    Extension *ext;
    int rc;
    char *ext_to;
    void **callback_ctx;

    if (!carrier || !to || !*to || !ela_id_is_valid(to) ||
        !data || !len || len > ELA_MAX_INVITE_DATA_LEN || !callback) {
        ela_set_error(ELA_GENERAL_ERROR(ELAERR_INVALID_ARGS));
        return -1;
    }

    ext = (Extension *)carrier_get_extension(carrier, extension_name);
    if (!ext) {
        ela_set_error(ELA_GENERAL_ERROR(ELAERR_NOT_EXIST));
        return -1;
    }

    callback_ctx = rc_zalloc(sizeof(void *) << 1, NULL);
    if (!callback_ctx) {
        ela_set_error(ELA_GENERAL_ERROR(ELAERR_OUT_OF_MEMORY));
        return -1;
    }
    callback_ctx[0] = callback;
    callback_ctx[1] = context;

    ext_to = (char *)alloca(ELA_MAX_ID_LEN + strlen(extension_name) + 2);
    strcpy(ext_to, to);
    strcat(ext_to, ":");
    strcat(ext_to, extension_name);

    rc = ela_invite_friend(carrier, ext_to, NULL, data, len,
                           on_friend_invite_reply, callback_ctx);

    logD("Extension: Extension invitation to %s %s.", to,
          rc == 0 ? "success" : "failed");

    if (rc < 0)
        deref(callback_ctx);

    return rc;
}

int extension_reply_friend_invite(ElaCarrier *carrier, const char *to,
                                  int status, const char *reason,
                                  const void *data, size_t len)
{
    Extension *ext;
    char *ext_to;
    int rc;

    if (!carrier) {
        ela_set_error(ELA_GENERAL_ERROR(ELAERR_INVALID_ARGS));
        return -1;
    }

    ext = (Extension *)carrier_get_extension(carrier, extension_name);
    if (!ext) {
        ela_set_error(ELA_GENERAL_ERROR(ELAERR_NOT_EXIST));
        return -1;
    }

    if (status && (!reason || strlen(reason) > ELA_MAX_INVITE_REPLY_REASON_LEN
                   || data || len > 0)) {
        ela_set_error(ELA_GENERAL_ERROR(ELAERR_INVALID_ARGS));
        return -1;
    }

    if (!status && (reason || !data || !len || len > ELA_MAX_INVITE_DATA_LEN)) {
        ela_set_error(ELA_GENERAL_ERROR(ELAERR_INVALID_ARGS));
        return -1;
    }

    if (!to || !*to || !ela_id_is_valid(to)) {
        ela_set_error(ELA_GENERAL_ERROR(ELAERR_INVALID_ARGS));
        return -1;
    }

    ext_to = (char *)alloca(ELA_MAX_ID_LEN + strlen(extension_name) + 2);
    strcpy(ext_to, to);
    strcat(ext_to, ":");
    strcat(ext_to, extension_name);

    rc = ela_reply_friend_invite(carrier, ext_to, NULL, status, reason,
                                 data, len);

    logD("Extension: Extension reply to %s %s.", to,
          rc == 0 ? "success" : "failed");

    return rc;
}