/*
 * Copyright (C) 2014 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef NETD_INCLUDE_NETD_CLIENT_H
#define NETD_INCLUDE_NETD_CLIENT_H

#include <stdbool.h>
#include <sys/cdefs.h>
#include <sys/types.h>

__BEGIN_DECLS

// All functions below that return an int return 0 on success or a negative errno value on failure.

int getNetworkForSocket(unsigned* netId, int socketFd);
int setNetworkForSocket(unsigned netId, int socketFd);

unsigned getNetworkForProcess(void);

int setNetworkForProcess(unsigned netId);

int setNetworkForResolv(unsigned netId);

int protectFromVpn(int socketFd);

int setNetworkForUser(uid_t uid, int socketFd);

int queryUserAccess(uid_t uid, unsigned netId);

void setAllowNetworkingForProcess(int uid, bool allowNetworking);

int tagSocket(int socketFd, uint32_t tag, uid_t uid);

int untagSocket(int socketFd);

int setCounterSet(uint32_t counterSet, uid_t uid);

int deleteTagData(uint32_t tag, uid_t uid);

int resNetworkQuery(unsigned netId, const char* dname, int ns_class, int ns_type, uint32_t flags);

int resNetworkResult(int query_fd, int* rcode, uint8_t* answer, size_t anslen);

int resNetworkSend(unsigned netId, const uint8_t* msg, size_t msglen, uint32_t flags);

void resNetworkCancel(int nsend_fd);

int getNetworkForDns(unsigned* dnsNetId);
__END_DECLS

#endif  // NETD_INCLUDE_NETD_CLIENT_H
