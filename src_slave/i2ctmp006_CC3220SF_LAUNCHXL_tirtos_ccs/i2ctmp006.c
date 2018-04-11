/*
 * Copyright (c) 2015-2017, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *    ======== i2ctmp006.c ========
 */
#include <stdint.h>
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <ti/devices/cc32xx/driverlib/pin.h>
//
#include <ti/devices/cc32xx/driverlib/rom_map.h>
#include <ti/drivers/power/PowerCC32XX.h>
/* Driver Header files */
#include <ti/drivers/GPIO.h>
//#include <ti/drivers/I2C.h>
#include <ti/devices/cc32xx/driverlib/i2c.h>
#include <ti/devices/cc32xx/inc/hw_memmap.h>
#include <ti/drivers/Power.h>
#include <ti/drivers/dpl/ClockP.h>
#include <ti/display/Display.h>
#include <xdc/runtime/System.h>
#include <stdbool.h>
/* Example/Board Header files */
#include "Board.h"
//#define I2CCC32XX_PIN_01_I2C_SCL  0x100 /*!< PIN 1 is used for I2C_SCL */
//#define I2CCC32XX_PIN_02_I2C_SDA  0x101 /*!< PIN 2 is used for I2C_SDA */
#define I2CCC32XX_PIN_03_I2C_SCL  0x502 /*!< PIN 3 is used for I2C_SCL *///PIN 3 is used for I2C clock
#define I2CCC32XX_PIN_04_I2C_SDA  0x503 /*!< PIN 4 is used for I2C_SDA *///pin 4 is used for i2c sda

#define MY_SLAVE_ADDR 0x68

static Display_Handle display;

#define TMP006_DIE_TEMP     0x0001  /* Die Temp Result Register */
void InitI2C0(void)
{

     Power_setDependency(PowerCC32XX_PERIPH_I2CA0);

    uint16_t pin =   I2CCC32XX_PIN_03_I2C_SCL & 0xff;
    uint16_t mode = (I2CCC32XX_PIN_03_I2C_SCL >> 8) & 0xff;
    PinTypeI2C((unsigned long)pin, (unsigned long)mode);

     pin =   I2CCC32XX_PIN_04_I2C_SDA & 0xff;
     mode = (I2CCC32XX_PIN_04_I2C_SDA >> 8) & 0xff;
     PinTypeI2C((unsigned long)pin, (unsigned long)mode);

     I2CSlaveInit(I2CA0_BASE,MY_SLAVE_ADDR);
    // I2CSlaveAddressSet(I2CA0_BASE, 0, MY_SLAVE_ADDR);
     I2CSlaveIntClear(I2CA0_BASE);
     I2CSlaveIntEnable(I2CA0_BASE);

}
void I2CSend(uint8_t slave_addr, uint8_t num_of_args){
    uint8_t i;
    // Tell the master module what address it will place on the bus when
    // communicating with the slave.
    I2CMasterSlaveAddrSet(I2CA0_BASE, slave_addr, false);
    //stores list of variable number of arguments
    va_list vargs;
    //specifies the va_list to "open" and the last fixed argument
    //so vargs knows where to start looking
    va_start(vargs, num_of_args);
    //put data to be sent into FIFO
    I2CMasterDataPut(I2CA0_BASE, va_arg(vargs, uint32_t));

    //if there is only one argument, we only need to use the single send I2C function
    if(num_of_args == 1)
    {
        //Initiate send of data from the MCU
        I2CMasterControl(I2CA0_BASE, I2C_MASTER_CMD_SINGLE_SEND);
        // Wait until MCU is done transferring.
        while(I2CMasterBusy(I2CA0_BASE));
        //"close" variable argument list
        va_end(vargs);
    }

    //otherwise, we start transmission of multiple bytes on the I2C bus
    else{
        //Initiate send of data from the MCU
        I2CMasterControl(I2CA0_BASE, I2C_MASTER_CMD_BURST_SEND_START);
        // Wait until MCU is done transferring.
        while(I2CMasterBusy(I2CA0_BASE));
        //send num_of_args-2 pieces of data, using the
        //BURST_SEND_CONT command of the I2C module
        for(i = 1; i < (num_of_args - 1); i++)
        {
            //put next piece of data into I2C FIFO
            I2CMasterDataPut(I2CA0_BASE, va_arg(vargs, uint32_t));
            //send next data that was just placed into FIFO
            I2CMasterControl(I2CA0_BASE, I2C_MASTER_CMD_BURST_SEND_CONT);
            // Wait until MCU is done transferring.
            while (I2CMasterBusy(I2CA0_BASE));
        }
        //put last piece of data into I2C FIFO
        I2CMasterDataPut(I2CA0_BASE, va_arg(vargs, uint32_t));
        //send next data that was just placed into FIFO
        I2CMasterControl(I2CA0_BASE, I2C_MASTER_CMD_BURST_SEND_FINISH);
        // Wait until MCU is done transferring.
        while(I2CMasterBusy(I2CA0_BASE));
        //"close" variable args list
        va_end(vargs);
    }

    I2CMasterSlaveAddrSet(I2CA0_BASE, slave_addr, true);

    //specify data to be written to the above mentioned device_register
    I2CMasterDataPut(I2CA0_BASE, va_arg(vargs, uint32_t));

    //wait while checking for MCU to complete the transaction
    I2CMasterControl(I2CA0_BASE, I2C_MASTER_CMD_BURST_RECEIVE_FINISH);

    //wait for MCU & device to complete transaction
    while(I2CMasterBusy(I2CA0_BASE));
}
uint8_t readI2C0(uint16_t device_address, uint16_t device_register)
{
    //specify that we want to communicate to device address with an intended write to bus
    I2CMasterSlaveAddrSet(I2CA0_BASE, device_address, false);

    //the register to be read
    I2CMasterDataPut(I2CA0_BASE, device_register);

    //send control byte and register address byte to slave device
    I2CMasterControl(I2CA0_BASE, I2C_MASTER_CMD_SINGLE_SEND);

    //wait for MCU to complete send transaction
    while(I2CMasterBusy(I2CA0_BASE));

    //read from the specified slave device
    I2CMasterSlaveAddrSet(I2CA0_BASE, device_address, true);

    //send control byte and read from the register from the MCU
    I2CMasterControl(I2CA0_BASE, I2C_MASTER_CMD_SINGLE_RECEIVE);

    //wait while checking for MCU to complete the transaction
    while(I2CMasterBusy(I2CA0_BASE));

    //Get the data from the MCU register and return to caller
    return( I2CMasterDataGet(I2CA0_BASE));
}
/*/
 * the slave rec function to send the ACK states
 */
void I2CSlaveRec(void){
    uint32_t slaveStatus =I2CSlaveStatus(I2CA0_BASE);

    if( slaveStatus == I2C_SLAVE_ACT_RREQ)
    {
        I2CSlaveACKOverride(I2CA0_BASE,true);
        I2CSlaveACKValueSet(I2CA0_BASE, true);
        Display_printf(display, 0, 0, "ACK SENT\n");

    }

}
/*
 *  ======== mainThread ========
 */
void *mainThread(void *arg0)
{
    /* Call driver init functions */
    Display_init();
    GPIO_init();
    InitI2C0();
    I2CSlaveRec();
    //I2CSend(0x41,1);

    /* Configure the LED pin */
#if 0
    GPIO_setConfig(Board_GPIO_LED0, GPIO_CFG_OUT_STD | GPIO_CFG_OUT_LOW);

    /* Open the HOST display for output */
    display = Display_open(Display_Type_UART, NULL);
    if (display == NULL) {
        while (1);
    }

    /* Turn on user LED */
    GPIO_write(Board_GPIO_LED0, Board_GPIO_LED_ON);
    Display_printf(display, 0, 0, "Starting the i2ctmp006 example\n");
    uint16_t        temperature=readI2C0(0x41, TMP006_DIE_TEMP);
    Display_printf(display, 0, 0, "Sample %u: %d (C)\n", 0, temperature);

#endif

#if 0
    txBuffer[0] = TMP006_DIE_TEMP;
    i2cTransaction.slaveAddress = Board_TMP_ADDR;
    i2cTransaction.writeBuf = txBuffer;
    i2cTransaction.writeCount = 1;
    i2cTransaction.readBuf = rxBuffer;
    i2cTransaction.readCount = 2;

#endif

    /* Take 20 samples and print them out onto the console */
#if 0
    for (i = 0; i < 20; i++) {
       // if (I2C_transfer(i2c, &i2cTransaction))

        {
            /* Extract degrees C from the received data; see TMP102 datasheet */
            temperature = (rxBuffer[0] << 6) | (rxBuffer[1] >> 2);

            /*
             * If the MSB is set '1', then we have a 2's complement
             * negative value which needs to be sign extended
             */
            if (rxBuffer[0] & 0x80) {
                temperature |= 0xF000;
            }
           /*
            * For simplicity, divide the temperature value by 32 to get rid of
            * the decimal precision; see TI's TMP006 datasheet
            */
            temperature /= 32;

            Display_printf(display, 0, 0, "Sample %u: %d (C)\n", i, temperature);
        }
       // else
        {
            Display_printf(display, 0, 0, "I2C Bus fault\n");
        }

        /* Sleep for 1 second */
        sleep(1);
    }
#endif

    /* Deinitialized I2C */
  //  I2C_close(i2c);
    //Display_printf(display, 0, 0, "I2C closed!\n");

    return (0);
}
