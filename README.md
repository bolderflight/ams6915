[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

![Bolder Flight Systems Logo](img/logo-words_75.png) &nbsp; &nbsp; ![Arduino Logo](img/arduino_logo_75.png)

# Ams6915
This library communicates with [AMS-6915](https://www.analog-micro.com/en/products/pressure-sensors/board-mount-pressure-sensors/ams6915/) pressure transducers and is compatible with Arduino and CMake build systems.
   * [License](LICENSE.md)
   * [Changelog](CHANGELOG.md)
   * [Contributing guide](CONTRIBUTING.md)

# Description
The Analog Microelectronics AMS-6915 pressure transducers are fully signal conditioned, amplified, and temperature compensated over a temperature range of -25 to +85 C. These sensors generate data with high precision, high stability and low drift. Digital measurements are sampled with a 14 bit resolution. The AMS-6915 sensors are available in a wide variety of pressure ranges and in configurations suited for barometric, differential, and bidirectional differential measurement.

# Usage
This library communicates with the AMS 6915 sensors using an I2C interface. The default I2C address for the AMS-6915 is 0x28; however, a USB starter kit may be purchased to enable programming additional addresses. Pressure and temperature data can be provided at rates of up to 2 kHz.

# Installation

## Arduino

Simply clone or download and extract the zipped library into your Arduino/libraries folder. The library is added as:

```C++
#include "ams6915.h"
```

An example Arduino executable is located in: *examples/arduino/ams6915_example/ams6915_example.ino*. Teensy 3.x, 4.x, and LC devices are used for testing under Arduino and this library should be compatible with other Arduino devices.

## CMake
CMake is used to build this library, which is exported as a library target called *ams6915*. The header is added as:

```C++
#include "ams6915.h"
```

The library can be also be compiled stand-alone using the CMake idiom of creating a *build* directory and then, from within that directory issuing:

```
cmake .. -DMCU=MK66FX1M0
make
```

This will build the library and an example executable called *ams5915_example*. The example executable source file is located at *examples/cmake/ams6915_example.cc*. Notice that the *cmake* command includes a define specifying the microcontroller the code is being compiled for. This is required to correctly configure the code, CPU frequency, and compile/linker options. The available MCUs are:
   * MK20DX128
   * MK20DX256
   * MK64FX512
   * MK66FX1M0
   * MKL26Z64
   * IMXRT1062_T40
   * IMXRT1062_T41
   * IMXRT1062_MMOD

These are known to work with the same packages used in Teensy products. Also switching packages is known to work well, as long as it's only a package change.

Each target also has a *_hex*, for creating the hex file to upload to the microcontroller, and an *_upload* for using the [Teensy CLI Uploader](https://www.pjrc.com/teensy/loader_cli.html) to flash the Teensy. Please note that the CMake build tooling is expected to be run under Linux or WSL, instructions for setting up your build environment can be found in our [build-tools repo](https://github.com/bolderflight/build-tools).

# Namespace
This library is within the namespace *bfs*.

# Ams6915

**Ams6915()** Default constructor, requires calling the Config method to setup the I2C bus, I2C address, and transducer type.

**Ams6915(i2c_t3 &ast;bus, const uint8_t addr, const Transducer type)** Creates an Ams6915 object. A pointer to the I2C bus object is passed along with the I2C address of the sensor and the AMS-6915 transducer type. The enumerated transducer types are:

| Sensor Name       | Enumerated Type  | Pressure Type              | Pressure Range       |
| -----------       | ---------------  | ---------------            | ---------------      |
| AMS 6915-0005-D   | AMS6915_0005_D   | differential / relative    | 0...500 Pa           |
| AMS 6915-0010-D   | AMS6915_0010_D   | differential / relative    | 0...1000 Pa          |
| AMS 6915-0025-D   | AMS6915_0025_D   | differential / relative    | 0...2500 Pa          |
| AMS 6915-0050-D   | AMS6915_0050_D   | differential / relative    | 0...5000 Pa          |
| AMS 6915-0100-D   | AMS6915_0100_D   | differential / relative    | 0...10000 Pa         |
| AMS 6915-0200-D   | AMS6915_0200_D   | differential / relative    | 0...20000 Pa         |
| AMS 6915-0350-D   | AMS6915_0350_D   | differential / relative    | 0...35000 Pa         |
| AMS 6915-1000-D   | AMS6915_1000_D   | differential / relative    | 0...100000 Pa        |
| AMS 6915-2000-D   | AMS6915_2000_D   | differential / relative    | 0...200000 Pa        |
| AMS 6915-2500-D   | AMS6915_2500_D   | differential / relative    | 0...250000 Pa        |
| AMS 6915-0200-G   | AMS6915_0200_G   | relative    | 0...20000 Pa         |
| AMS 6915-0350-G   | AMS6915_0350_G   | relative    | 0...35000 Pa         |
| AMS 6915-1000-G   | AMS6915_1000_G   | relative    | 0...100000 Pa        |
| AMS 6915-2000-G   | AMS6915_2000_G   | relative    | 0...200000 Pa        |
| AMS 6915-0002-D-B | AMS6915_0002_D_B | bidirectional differential | -250...+250 Pa       |
| AMS 6915-0005-D-B | AMS6915_0005_D_B | bidirectional differential | -500...+500 Pa       |
| AMS 6915-0010-D-B | AMS6915_0010_D_B | bidirectional differential | -1000...+1000 Pa     |
| AMS 6915-0025-D-B | AMS6915_0025_D_B | bidirectional differential | -2500...+2500 Pa     |
| AMS 6915-0050-D-B | AMS6915_0050_D_B | bidirectional differential | -5000...+5000 Pa     |
| AMS 6915-0100-D-B | AMS6915_0100_D_B | bidirectional differential | -10000...+10000 Pa   |
| AMS 6915-0200-D-B | AMS6915_0200_D_B | bidirectional differential | -20000...+20000 Pa   |
| AMS 6915-0350-D-B | AMS6915_0350_D_B | bidirectional differential | -35000...+35000 Pa   |
| AMS 6915-1000-D-B | AMS6915_1000_D_B | bidirectional differential | -100000...+100000 Pa |
| AMS 6915-0500-A   | AMS6915_0500_A   | absolute                   | 0...50000 Pa        |
| AMS 6915-1000-A   | AMS6915_1000_A   | absolute                   | 0...100000 Pa        |
| AMS 6915-2000-A   | AMS6915_2000_A   | absolute                   | 0...200000 Pa        |
| AMS 6915-1200-B   | AMS6915_1200_B   | barometric                 | 70000...120000 Pa    |

For example, the following code declares an AMS6915 object called *ams* with an AMS6915-1200-B sensor located on I2C bus 0 with an I2C address of 0x10:

```C++
bfs::Ams6915 ams(&Wire, 0x10, bfs::Ams6915::AMS6915_1200_B);
```

**void Config(TwoWire &ast;bus, const uint8_t addr, const Transducer type)** This is required when using the default constructor and sets up the I2C bus, I2C address, and transducer type.

**bool Begin()** Initializes communication with the sensor and configures the sensor driver for the specified transducer. True is returned if communication is able to be established with the sensor and configuration completes successfully, otherwise, false is returned. The communication bus is not initialized within this library and must be initialized seperately; this enhances compatibility with other sensors that may on the same bus.

```C++
Wire.begin();
Wire.setClock(400000);
bool status = ams.Begin();
if (!status) {
  // ERROR
}
```

**bool Read()** Reads data from the AMS-6915 and stores the data in the Ams6915 object. Returns true if data is successfully read, otherwise, returns false.

```C++
/* Read the sensor data */
if (ams.Read()) {
}
```

**float pres_pa()** Returns the pressure data from the Ams6915 object in units of Pa.

```C++
float pressure = ams.pres_pa();
```

**float die_temp_c** Returns the die temperature of the sensor from the Ams6915 object in units of degrees C.

```C++
float temperature = ams.die_temp_c();
```
