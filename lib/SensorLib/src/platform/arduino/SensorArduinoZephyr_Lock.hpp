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
 * @file      SensorArduinoZephyr_Lock.hpp
 * @author    Lewis He (lewishe@outlook.com)
 * @date      2025-02-10
 *
 */
#pragma once

#include "../SensorLockBase.hpp"

#if defined(ARDUINO_ARCH_ZEPHYR)

class ZephyrLock : public SensorLockBase
{
private:
    struct k_mutex mutex;
public:
    ZephyrLock()
    {
        k_mutex_init(&mutex);
    }
    void lock() override
    {
        k_mutex_lock(&mutex, K_FOREVER);
    }
    void unlock() override
    {
        k_mutex_unlock(&mutex);
    }
};

using HalLock = ZephyrLock;

#endif /*ARDUINO_ARCH_ZEPHYR*/
