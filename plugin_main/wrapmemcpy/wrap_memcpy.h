/*
 * Copyright 2021 iLogtail Authors
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

#pragma once

#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

#if defined(__x86_64__) && defined(__GNUC__)
__asm__(".symver memcpy,memcpy@GLIBC_2.2.5");
void* __wrap_memcpy(void* dest, const void* src, size_t n) {
    return memcpy(dest, src, n);
}
#else
void* __wrap_memcpy(void* dest, const void* src, size_t n) {
    return memmove(dest, src, n);
}
#endif

#ifdef __cplusplus
}
#endif