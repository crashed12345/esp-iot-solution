// Copyright 2015-2016 Espressif Systems (Shanghai) PTE LTD
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "freertos/semphr.h"
#include "esp_log.h"
#include "iot_ir.h"
#include "unity.h"

TEST_CASE("IR nec test", "[rmt_nec][iot]")
{
	printf("ir test...\n");
	CIrNecSender tx_test(RMT_CHANNEL_0, GPIO_NUM_18, false);
    CIrNecRecv rx_test(RMT_CHANNEL_1, GPIO_NUM_19, 1);

	tx_test.send(0x1, 0x1);
	tx_test.send(0x1, 0x2);
	tx_test.send(0x1, 0x3);
	tx_test.send(0x1, 0x4);

    uint16_t addr, cmd;
    rx_test.recv(&addr, &cmd, 1000/ portTICK_RATE_MS);
    printf("RMT RCV --- addr: 0x%04x cmd: 0x%04x\n", addr, cmd);
    rx_test.recv(&addr, &cmd, 1000/ portTICK_RATE_MS);
    printf("RMT RCV --- addr: 0x%04x cmd: 0x%04x\n", addr, cmd);
    rx_test.recv(&addr, &cmd, 1000/ portTICK_RATE_MS);
    printf("RMT RCV --- addr: 0x%04x cmd: 0x%04x\n", addr, cmd);
    rx_test.recv(&addr, &cmd, 1000/ portTICK_RATE_MS);
    printf("RMT RCV --- addr: 0x%04x cmd: 0x%04x\n", addr, cmd);
}
