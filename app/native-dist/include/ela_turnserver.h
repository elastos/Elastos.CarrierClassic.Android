/*
 * Copyright (c) 2018 Elastos Foundation
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

#ifndef __ELA_TURNSERVER_H__
#define __ELA_TURNSERVER_H__

#include <stdbool.h>
#include <stdint.h>
#include <stdarg.h>
#include <stdlib.h>

#if defined(__APPLE__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdocumentation"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if defined(CARRIER_STATIC)
#define CARRIER_API
#elif defined(CARRIER_DYNAMIC)
#ifdef CARRIER_BUILD
    #if defined(_WIN32) || defined(_WIN64)
      #define CARRIER_API        __declspec(dllexport)
    #else
      #define CARRIER_API        __attribute__((visibility("default")))
    #endif
  #else
    #if defined(_WIN32) || defined(_WIN64)
      #define CARRIER_API        __declspec(dllimport)
    #else
      #define CARRIER_API        __attribute__((visibility("default")))
    #endif
  #endif
#else
#define CARRIER_API
#endif


#define ELA_MAX_TURN_SERVER_LEN         63

#define ELA_MAX_TURN_USERNAME_LEN       127

#define ELA_MAX_TURN_PASSWORD_LEN       63

#define ELA_MAX_TURN_REALM_LEN          127

typedef struct ElaTurnServer {
    char server[ELA_MAX_TURN_SERVER_LEN + 1];
    uint16_t port;
    char username[ELA_MAX_TURN_USERNAME_LEN + 1];
    char password[ELA_MAX_TURN_PASSWORD_LEN + 1];
    char realm[ELA_MAX_TURN_REALM_LEN + 1];
} ElaTurnServer;

CARRIER_API
int ela_get_turn_server(ElaCarrier *carrier, ElaTurnServer *turn_server);

#endif // __ELA_TURNSERVER_H__
