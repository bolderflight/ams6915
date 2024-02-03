/*
* Brian R Taylor
* brian.taylor@bolderflight.com
* 
* Copyright (c) 2024 Bolder Flight Systems Inc
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the “Software”), to
* deal in the Software without restriction, including without limitation the
* rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
* sell copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
* FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
* IN THE SOFTWARE.
*/

#include "ams6915.h"  // NOLINT
#if defined(ARDUINO)
#include "Arduino.h"
#include "Wire.h"
#else
#include "core/core.h"
#endif

namespace bfs {

Ams6915::Ams6915(TwoWire *bus, const uint8_t addr, const Transducer type) {
  bus_ = bus;
  addr_ = addr;
  switch (type) {
    case AMS6915_0005_D: {
      min_pres_mbar_ = 0.0f;
      max_pres_mbar_ = 5.0f;
      break;
    }
    case AMS6915_0010_D: {
      min_pres_mbar_ = 0.0f;
      max_pres_mbar_ = 10.0f;
      break;
    }
    case AMS6915_0025_D: {
      min_pres_mbar_ = 0.0f;
      max_pres_mbar_ = 25.0f;
      break;
    }
    case AMS6915_0050_D: {
      min_pres_mbar_ = 0.0f;
      max_pres_mbar_ = 50.0f;
      break;
    }
    case AMS6915_0100_D: {
      min_pres_mbar_ = 0.0f;
      max_pres_mbar_ = 100.0f;
      break;
    }
    case AMS6915_0200_D: {
      min_pres_mbar_ = 0.0f;
      max_pres_mbar_ = 200.0f;
      break;
    }
    case AMS6915_0350_D: {
      min_pres_mbar_ = 0.0f;
      max_pres_mbar_ = 350.0f;
      break;
    }
    case AMS6915_1000_D: {
      min_pres_mbar_ = 0.0f;
      max_pres_mbar_ = 1000.0f;
      break;
    }
    case AMS6915_2000_D: {
      min_pres_mbar_ = 0.0f;
      max_pres_mbar_ = 2000.0f;
      break;
    }
    case AMS6915_2500_D: {
      min_pres_mbar_ = 0.0f;
      max_pres_mbar_ = 2500.0f;
      break;
    }
    case AMS6915_0200_G: {
      min_pres_mbar_ = 0.0f;
      max_pres_mbar_ = 200.0f;
      break;
    }
    case AMS6915_0350_G: {
      min_pres_mbar_ = 0.0f;
      max_pres_mbar_ = 350.0f;
      break;
    }
    case AMS6915_1000_G: {
      min_pres_mbar_ = 0.0f;
      max_pres_mbar_ = 1000.0f;
      break;
    }
    case AMS6915_2000_G: {
      min_pres_mbar_ = 0.0f;
      max_pres_mbar_ = 2000.0f;
      break;
    }
    case AMS6915_0002_D_B: {
      min_pres_mbar_ = -2.5f;
      max_pres_mbar_ = 2.5f;
      break;
    }
    case AMS6915_0005_D_B: {
      min_pres_mbar_ = -5.0f;
      max_pres_mbar_ = 5.0f;
      break;
    }
    case AMS6915_0010_D_B: {
      min_pres_mbar_ = -10.0f;
      max_pres_mbar_ = 10.0f;
      break;
    }
    case AMS6915_0025_D_B: {
      min_pres_mbar_ = -25.0f;
      max_pres_mbar_ = 25.0f;
      break;
    }
    case AMS6915_0050_D_B: {
      min_pres_mbar_ = -50.0f;
      max_pres_mbar_ = 50.0f;
      break;
    }
    case AMS6915_0100_D_B: {
      min_pres_mbar_ = -100.0f;
      max_pres_mbar_ = 100.0f;
      break;
    }
    case AMS6915_0200_D_B: {
      min_pres_mbar_ = -200.0f;
      max_pres_mbar_ = 200.0f;
      break;
    }
    case AMS6915_0350_D_B: {
      min_pres_mbar_ = -350.0f;
      max_pres_mbar_ = 350.0f;
      break;
    }
    case AMS6915_1000_D_B: {
      min_pres_mbar_ = -1000.0f;
      max_pres_mbar_ = 1000.0f;
      break;
    }
    case AMS6915_0500_A: {
      min_pres_mbar_ = 0.0f;
      max_pres_mbar_ = 500.0f;
      break;
    }
    case AMS6915_1000_A: {
      min_pres_mbar_ = 0.0f;
      max_pres_mbar_ = 1000.0f;
      break;
    }
    case AMS6915_2000_A: {
      min_pres_mbar_ = 0.0f;
      max_pres_mbar_ = 2000.0f;
      break;
    }
    case AMS6915_1200_B: {
      min_pres_mbar_ = 700.0f;
      max_pres_mbar_ = 1200.0f;
      break;
    }
  }
  pres_range_mbar_ = max_pres_mbar_ - min_pres_mbar_;
}
void Ams6915::Config(TwoWire *bus, const uint8_t addr, const Transducer type) {
  bus_ = bus;
  addr_ = addr;
  switch (type) {
    case AMS6915_0005_D: {
      min_pres_mbar_ = 0.0f;
      max_pres_mbar_ = 5.0f;
      break;
    }
    case AMS6915_0010_D: {
      min_pres_mbar_ = 0.0f;
      max_pres_mbar_ = 10.0f;
      break;
    }
    case AMS6915_0025_D: {
      min_pres_mbar_ = 0.0f;
      max_pres_mbar_ = 25.0f;
      break;
    }
    case AMS6915_0050_D: {
      min_pres_mbar_ = 0.0f;
      max_pres_mbar_ = 50.0f;
      break;
    }
    case AMS6915_0100_D: {
      min_pres_mbar_ = 0.0f;
      max_pres_mbar_ = 100.0f;
      break;
    }
    case AMS6915_0200_D: {
      min_pres_mbar_ = 0.0f;
      max_pres_mbar_ = 200.0f;
      break;
    }
    case AMS6915_0350_D: {
      min_pres_mbar_ = 0.0f;
      max_pres_mbar_ = 350.0f;
      break;
    }
    case AMS6915_1000_D: {
      min_pres_mbar_ = 0.0f;
      max_pres_mbar_ = 1000.0f;
      break;
    }
    case AMS6915_2000_D: {
      min_pres_mbar_ = 0.0f;
      max_pres_mbar_ = 2000.0f;
      break;
    }
    case AMS6915_2500_D: {
      min_pres_mbar_ = 0.0f;
      max_pres_mbar_ = 2500.0f;
      break;
    }
    case AMS6915_0200_G: {
      min_pres_mbar_ = 0.0f;
      max_pres_mbar_ = 200.0f;
      break;
    }
    case AMS6915_0350_G: {
      min_pres_mbar_ = 0.0f;
      max_pres_mbar_ = 350.0f;
      break;
    }
    case AMS6915_1000_G: {
      min_pres_mbar_ = 0.0f;
      max_pres_mbar_ = 1000.0f;
      break;
    }
    case AMS6915_2000_G: {
      min_pres_mbar_ = 0.0f;
      max_pres_mbar_ = 2000.0f;
      break;
    }
    case AMS6915_0002_D_B: {
      min_pres_mbar_ = -2.5f;
      max_pres_mbar_ = 2.5f;
      break;
    }
    case AMS6915_0005_D_B: {
      min_pres_mbar_ = -5.0f;
      max_pres_mbar_ = 5.0f;
      break;
    }
    case AMS6915_0010_D_B: {
      min_pres_mbar_ = -10.0f;
      max_pres_mbar_ = 10.0f;
      break;
    }
    case AMS6915_0025_D_B: {
      min_pres_mbar_ = -25.0f;
      max_pres_mbar_ = 25.0f;
      break;
    }
    case AMS6915_0050_D_B: {
      min_pres_mbar_ = -50.0f;
      max_pres_mbar_ = 50.0f;
      break;
    }
    case AMS6915_0100_D_B: {
      min_pres_mbar_ = -100.0f;
      max_pres_mbar_ = 100.0f;
      break;
    }
    case AMS6915_0200_D_B: {
      min_pres_mbar_ = -200.0f;
      max_pres_mbar_ = 200.0f;
      break;
    }
    case AMS6915_0350_D_B: {
      min_pres_mbar_ = -350.0f;
      max_pres_mbar_ = 350.0f;
      break;
    }
    case AMS6915_1000_D_B: {
      min_pres_mbar_ = -1000.0f;
      max_pres_mbar_ = 1000.0f;
      break;
    }
    case AMS6915_0500_A: {
      min_pres_mbar_ = 0.0f;
      max_pres_mbar_ = 500.0f;
      break;
    }
    case AMS6915_1000_A: {
      min_pres_mbar_ = 0.0f;
      max_pres_mbar_ = 1000.0f;
      break;
    }
    case AMS6915_2000_A: {
      min_pres_mbar_ = 0.0f;
      max_pres_mbar_ = 2000.0f;
      break;
    }
    case AMS6915_1200_B: {
      min_pres_mbar_ = 700.0f;
      max_pres_mbar_ = 1200.0f;
      break;
    }
  }
  pres_range_mbar_ = max_pres_mbar_ - min_pres_mbar_;
}
bool Ams6915::Begin() {
  /* Checking to see if we can communicate with sensor */
  for (int tries = 0; tries < MAX_TRIES_; tries++) {
    if (Read()) {
      return true;
    }
    delay(10);
  }
  return false;
}
bool Ams6915::Read() {
  bytes_rx_ = bus_->requestFrom(addr_, sizeof(buf_));
  if (bytes_rx_ != sizeof(buf_)) {
    return false;
  }
  for (size_t i = 0; i < bytes_rx_; i++) {
    buf_[i] = bus_->read();
  }
  pres_cnts_ = (static_cast<uint16_t>(buf_[0] & 0x3F) << 8) | buf_[1];
  temp_cnts_ = (static_cast<uint16_t>(buf_[2]) << 3) | (buf_[3] & 0xE0 >> 5);
  pres_mbar_ = static_cast<float>(pres_cnts_ - PMIN_) / PRANGE_ *
               pres_range_mbar_ + min_pres_mbar_;
  temp_ = static_cast<float>(temp_cnts_ * 200) / 2048.0f - 50.0f;
  if (temp_ > MAX_TEMPERATURE_) {return false;}
  pres_pa_ = pres_mbar_ * 100.0f;
  temp_c_ = temp_;
  return true;
}

}  // namespace bfs
