/**
 *
 * @license MIT License
 *
 * Copyright (c) 2025 lewis he
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
 *
 * @file      SensorArduinoFreeRTOS_Lock.hpp
 * @author    Lewis He (lewishe@outlook.com)
 * @date      2025-02-10
 *
 */
#pragma once

#include "../SensorSmartLock.hpp"

#if defined(ARDUINO_ARCH_ESP32)

#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"

class FreeRTOSLock : public SensorLockBase
{
private:
    SemaphoreHandle_t mutex;
public:
    FreeRTOSLock()
    {
        mutex = xSemaphoreCreateMutex();
    }
    ~FreeRTOSLock()
    {
        vSemaphoreDelete(mutex);
    }
    void lock() override
    {
        xSemaphoreTake(mutex, portMAX_DELAY);
    }
    void unlock() override
    {
        xSemaphoreGive(mutex);
    }
};

using HalLock = FreeRTOSLock;

#endif /*ARDUINO_ARCH_ESP32*/
