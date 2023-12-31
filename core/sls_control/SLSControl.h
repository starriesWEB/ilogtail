/*
 * Copyright 2022 iLogtail Authors
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
#include "sdk/Client.h"

namespace logtail {

class SLSControl {
private:
    SLSControl();
    SLSControl(const SLSControl&);
    std::string GetRunningEnvironment();
    bool TryCurlEndpoint(const std::string& endpoint);
    std::string mUserAgent;

public:
    static SLSControl* Instance();
    void SetSlsSendClientCommonParam(sdk::Client* sendClient);
    bool
    SetSlsSendClientAuth(const std::string aliuid, const bool init, sdk::Client* sendClient, int32_t& lastUpdateTime);
    ~SLSControl();
};

} // namespace logtail
