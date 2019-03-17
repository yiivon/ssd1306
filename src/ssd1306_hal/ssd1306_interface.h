/*
    MIT License

    Copyright (c) 2017-2018, Alexey Dynda

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
*/
/**
 * @file ssd1306_interface.h SSD1306 interface functions.
 */

#ifndef _SSD1306_INTERFACE_H_
#define _SSD1306_INTERFACE_H_

#include <stdint.h>

/**
 * @defgroup LCD_HW_INTERFACE_API I2C/SPI: physical interface functions
 * @{
 *
 * @brief i2c/spi initialization functions for different platforms
 *
 * @details This group of API functions serves to prepare the library to work via specific hardware
 *          interface. There are a bunch of functions for different platforms. In general display
 *          initialization goes in two steps: hardware interface initialization, and then display
 *          driver initialization. But there are functions, which combine 2 steps in single call:
 *          ssd1306_128x64_i2c_initEx(), ssd1351_128x128_spi_init(), etc.
 */

/**
 * Abstract class for system specific interface, used to control oled
 */
class IWireInterface
{
public:
    /**
     * Initializes interface
     */
    virtual void begin() = 0;

    /**
     * Deinitializes interface
     */
    virtual void end() = 0;

    /**
     * Starts communication with SSD1306 display.
     */
    virtual void start() = 0;

    /**
     * Ends communication with SSD1306 display.
     */
    virtual void stop() = 0;

    /**
     * Sends byte to SSD1306 device
     * @param data - byte to send
     */
    virtual void send(uint8_t data) = 0;

    /**
     * @brief Sends bytes to SSD1306 device
     *
     * Sends bytes to SSD1306 device. This functions gives
     * ~ 30% performance increase than ssd1306_intf.send.
     *
     * @param buffer - bytes to send
     * @param size - number of bytes to send
     */
    virtual void sendBuffer(const uint8_t *buffer, uint16_t size) = 0;
};

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C" void ssd1306_resetController(int8_t rstPin, uint8_t delayMs);
#endif

/**
 * @}
 */

// ----------------------------------------------------------------------------
#endif // _SSD1306_INTERFACE_H_