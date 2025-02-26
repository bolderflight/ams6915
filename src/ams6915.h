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

#ifndef AMS6915_SRC_AMS6915_H_  // NOLINT
#define AMS6915_SRC_AMS6915_H_

#if defined(ARDUINO)
#include "Arduino.h"
#include "Wire.h"
#else
#include "core/core.h"
#endif

namespace bfs {

class Ams6915 {
 public:
  enum Transducer : int8_t {
    AMS6915_0005_D,
    AMS6915_0010_D,
    AMS6915_0025_D,
    AMS6915_0050_D,
    AMS6915_0100_D,
    AMS6915_0200_D,
    AMS6915_0350_D,
    AMS6915_1000_D,
    AMS6915_2000_D,
    AMS6915_2500_D,
    AMS6915_0200_G,
    AMS6915_0350_G,
    AMS6915_1000_G,
    AMS6915_2000_G,
    AMS6915_0002_D_B,
    AMS6915_0005_D_B,
    AMS6915_0010_D_B,
    AMS6915_0025_D_B,
    AMS6915_0050_D_B,
    AMS6915_0100_D_B,
    AMS6915_0200_D_B,
    AMS6915_0350_D_B,
    AMS6915_1000_D_B,
    AMS6915_0500_A,
    AMS6915_1000_A,
    AMS6915_2000_A,
    AMS6915_1200_B
  };
  Ams6915() {}
  Ams6915(TwoWire *bus, const uint8_t addr, const Transducer type);
  void Config(TwoWire *bus, const uint8_t addr, const Transducer type);
  bool Begin();
  bool Read();
  inline float pres_pa() const {return pres_pa_;}
  inline float die_temp_c() const {return temp_c_;}

 private:
  /* Communication interface */
  TwoWire *bus_;
  uint8_t addr_;
  static constexpr int MAX_TRIES_ = 10;
  /* Min and max pressure, millibar */
  float min_pres_mbar_, max_pres_mbar_, pres_range_mbar_;
  /* Digital output at min and max pressure */
  static constexpr uint16_t PMIN_ = 1638;
  static constexpr uint16_t PMAX_ = 14745;
  static constexpr float PRANGE_ = static_cast<float>(PMAX_ - PMIN_);
  /* Maximum temperature */
  static constexpr float MAX_TEMPERATURE_ = 85.0f;
  /* Data */
  uint8_t buf_[4];
  uint8_t bytes_rx_;
  uint16_t pres_cnts_, temp_cnts_;
  float pres_mbar_, temp_;
  float pres_pa_, temp_c_;
};

}  // namespace bfs

#endif  // AMS6915_SRC_AMS6915_H_ NOLINT
