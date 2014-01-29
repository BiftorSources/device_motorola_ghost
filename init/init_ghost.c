/*
   Copyright (c) 2013, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

#include "init_msm.h"

void init_msm_properties(unsigned long msm_id, unsigned long msm_ver, char *board_type)
{
    char platform[PROP_VALUE_MAX];
    char radio[PROP_VALUE_MAX];
    int rc;

    UNUSED(msm_id);
    UNUSED(msm_ver);
    UNUSED(board_type);

    rc = property_get("ro.board.platform", platform);
    if (!rc || !ISMATCH(platform, ANDROID_TARGET))
        return;

    property_get("ro.boot.radio", radio);
    if (ISMATCH(radio, "0x1")) {
            /* xt1058 */
            property_set("ro.product.device", "ghost_att");
            property_set("ro.product.model", "XT1058");
            property_set("ro.build.description", "ghost_retail-user 4.4 13.11.1Q2.X-69-3 51 release-keys");
            property_set("ro.build.fingerprint", "motorola/ghost_retail/ghost:4.4/13.11.1Q2.X-69-3/51:user/release-keys");
            property_set("telephony.lteOnGsmDevice", "1");
    } else if (ISMATCH(radio, "0x2")) {
            /* xt1060 */
            property_set("ro.product.device", "ghost_verizon");
            property_set("ro.product.model", "XT1060");
            property_set("ro.build.description", "ghost_verizon-user 4.4 13.11.1Q2.X-69-3 5 release-keys");
            property_set("ro.build.fingerprint", "motorola/ghost_verizon/ghost:4.4/13.11.1Q2.X-69-3/5:user/release-keys");
            property_set("ro.cdma.nbpcd", "1");
            property_set("ro.cdma.home.operator.isnan", "1");
            property_set("ro.telephony.gsm-routes-us-smsc", "1");
            property_set("ro.cdma.otaspnumschema","SELC,1,80,99");
            property_set("ro.cdma.data_retry_config", "max_retries=infinite,0,0,10000,10000,100000,10000,10000,10000,10000,140000,540000,960000");
            property_set("ro.gsm.data_retry_config", "default_randomization=2000,max_retries=infinite,1000,1000,80000,125000,485000,905000");
            property_set("ro.gsm.2nd_data_retry_config", "max_retries=1,15000");
            property_set("persist.radio.vrte_logic", "2");
            property_set("persist.radio.0x9e_not_callname", "1");
            property_set("persist.ril.max.crit.qmi.fails", "4");
            property_set("ro.cdma.homesystem", "64,65,76,77,78,79,80,81,82,83");
            property_set("ro.mot.ignore_csim_appid", "true");
            property_set("telephony.rilV7NeedCDMALTEPhone", "true");
    } else if (ISMATCH(radio, "0x6")) {
            /* xt1053 */
            property_set("ro.product.device", "ghost_retail");
            property_set("ro.product.model", "XT1053");
            property_set("ro.build.description", "ghost_retail-user 4.4 13.11.1Q2.X-69-3 51 release-keys");
            property_set("ro.build.fingerprint", "motorola/ghost_retail/ghost:4.4/13.11.1Q2.X-69-3/51:user/release-keys");
            property_set("telephony.lteOnGsmDevice", "1");
    }
    ERROR("Found radio=%s setting build properties\n", radio);
}