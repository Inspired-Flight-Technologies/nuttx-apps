/****************************************************************************
 * nxp_bms/BMS_v1/inc/UAVCAN/multibms.h
 *
 * BSD 3-Clause License
 *
 * Copyright 2022 NXP
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ** ###################################################################
 **     Filename    : multibms.h
 **     Project     : SmartBattery_RDDRONE_BMS772
 **     Processor   : S32K144
 **     Version     : 1.00
 **     Date   		: 2022-03-22
 **     Abstract    :
 **        multibms module.
 **
 ** ###################################################################*/
/*!
 ** @file multibms.h
 **
 ** @version 01.00
 **
 ** @brief
 **        multibms module. this module implements the CAN communication for multiple bms's
 **
 */

#ifndef CAN_MULTIBMS_H_
#define CAN_MULTIBMS_H_

#include <canard.h>

#include "safetydomain.h"

#define UAVCAN_MULTIBMS_ERROR_SERIALIZATION 1


int32_t uavcan_multibms_init(CanardInstance* ins);

// Handler for all PortID registration related messages
int32_t uavcan_multibms_process(CanardInstance* ins, CanardTransfer* transfer);

int32_t uavcan_multibms_send_notification(
    uint8_t value, uint64_t battery_id, uint64_t context_battery_id, sd_context_entry* context, uint8_t len);
int32_t uavcan_multibms_send_distributedstatus(
    uint64_t battery_id, uint8_t battery_state, uint8_t switch_status);

#endif// CAN_MULTIBMS_H_
