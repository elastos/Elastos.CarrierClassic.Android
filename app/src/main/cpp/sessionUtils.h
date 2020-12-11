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

#ifndef __SESSION_UTILS_H__
#define __SESSION_UTILS_H__

#include <jni.h>
#include <carrier.h>
#include <carrier_session.h>

int newJavaStreamState(JNIEnv* env, CarrierStreamState state, jobject* jstate);

int getNativeStreamType(JNIEnv* env, jobject jjtype,  CarrierStreamType* type);

int newJavaSession(JNIEnv* env, CarrierSession* session, jobject jto, jobject* jsession);

int newJavaStream(JNIEnv* env, jobject jtype, jobject* jstream);

int newJavaCloseReason(JNIEnv* env, CloseReason reason, jobject* jreason);

int getNativeProtocol(JNIEnv* env, jobject jproto, PortForwardingProtocol* protocol);

int setJavaTransportInfo(JNIEnv *env, jobject jtransport, CarrierTransportInfo *info);

#endif //__SESSION_UTILS_H__