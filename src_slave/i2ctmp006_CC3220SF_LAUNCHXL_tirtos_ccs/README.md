---
# i2ctmp006

---

## Example Summary

Sample application to read temperature value from a TMP006 I2C temperature
sensor.

## Peripherals Exercised

* `Board_GPIO_LED0` - Indicator LED
* `Board_I2C_TMP` - I2C used to communicate with TMP006 sensor.

## Resources & Jumper Settings

> If you're using an IDE (such as CCS or IAR), please refer to Board.html in
your project directory for resources used and board-specific jumper settings.
Otherwise, you can find Board.html in the directory
&lt;SDK_INSTALL_DIR&gt;/source/ti/boards/&lt;BOARD&gt;.


## Example Usage

* Example output is generated through use of Display driver APIs. Refer to the
Display driver documentation found in the SimpleLink MCU SDK User's Guide.

* Connect the TMP006 Booster Pack, if required, before powering the hardware.

* Open a serial session (e.g. [`PuTTY`](http://www.putty.org/ "PuTTY's
Homepage"), etc.) to the appropriate COM port.
    * The COM port can be determined via Device Manager in Windows or via
`ls /dev/tty*` in Linux.

The connection will have the following settings:
```
    Baud-rate:     115200
    Data bits:          8
    Stop bits:          1
    Parity:          None
    Flow Control:    None
```

* Run the example. `Board_GPIO_LED0` turns ON to indicate driver
initialization is complete.

* The example will request temperature samples from the TMP006 and prints them
via UART. A total of 20 temperature samples are read/printed before the
example exits.

Console output should resemble:
```
        I2C Initialized!
        Sample 0: 24 (C)
        Sample 1: 24 (C)
        Sample 2: 24 (C)
        Sample 3: 24 (C)
```

## Application Design Details

This application uses one thread:

`mainThread` - performs the following actions:

1. Opens and initializes an I2C driver object.

2. Uses the I2C driver to get data from the TMP006 sensor.

3. Extracts the temperature (in Celsius) and prints the value onto the console.

4. The thread sleeps for 1 second.

5. After 20 temperature samples are recovered, the I2C peripheral is closed
and the example exits.

TI-RTOS:

* When building in Code Composer Studio, the kernel configuration project will
be imported along with the example. The kernel configuration project is
referenced by the example, so it will be built first. The "release" kernel
configuration is the default project used. It has many debug features disabled.
These feature include assert checking, logging and runtime stack checks. For a
detailed difference between the "release" and "debug" kernel configurations and
how to switch between them, please refer to the SimpleLink MCU SDK User's
Guide. The "release" and "debug" kernel configuration projects can be found
under &lt;SDK_INSTALL_DIR&gt;/kernel/tirtos/builds/&lt;BOARD&gt;/(release|debug)/(ccs|gcc).

FreeRTOS:

* Please view the `FreeRTOSConfig.h` header file for example configuration
information.
