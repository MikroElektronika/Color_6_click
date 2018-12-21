/*
    __color6_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __color6_driver.h
@brief    Color6 Driver
@mainpage Color6 Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   COLOR6
@brief      Color6 Click Driver
@{

| Global Library Prefix | **COLOR6** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **maj 2018.**      |
| Developer             | **Katarina Perendic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _COLOR6_H_
#define _COLOR6_H_

/** 
 * @macro T_COLOR6_P
 * @brief Driver Abstract type 
 */
#define T_COLOR6_P    const uint8_t*

/** @defgroup COLOR6_COMPILE Compilation Config */              /** @{ */

//  #define   __COLOR6_DRV_SPI__                            /**<     @macro __COLOR6_DRV_SPI__  @brief SPI driver selector */
   #define   __COLOR6_DRV_I2C__                            /**<     @macro __COLOR6_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __COLOR6_DRV_UART__                           /**<     @macro __COLOR6_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup COLOR6_VAR Variables */                           /** @{ */

/* Register */
extern const uint8_t _COLOR6_REG_OPERATIONAL_STATE;
extern const uint8_t _COLOR6_REG_API_GENERATION;
extern const uint8_t _COLOR6_REG_CONFIGURATION_REGISTER_1;
extern const uint8_t _COLOR6_REG_CONFIGURATION_REGISTER_2;
extern const uint8_t _COLOR6_REG_CONFIGURATION_REGISTER_3;
extern const uint8_t _COLOR6_REG_BREAK_TIME;
extern const uint8_t _COLOR6_REG_EDGE_COUNT_VALUE;
extern const uint8_t _COLOR6_REG_OPTIONS_REGISTER;

/* Operational State Register – OSR */
extern const uint8_t _COLOR6_OSR_STOP_MEASUREMENT;
extern const uint8_t _COLOR6_OSR_START_MEASUREMENT;
extern const uint8_t _COLOR6_OSR_POWER_DOWN_SWITCHED_OFF;
extern const uint8_t _COLOR6_OSR_POWER_DOWN_SWITCHED_ON;
extern const uint8_t _COLOR6_OSR_SOFTWARE_RESET;
extern const uint8_t _COLOR6_OSR_DOS_CONFIGURATION;
extern const uint8_t _COLOR6_OSR_DOS_MEASUREMENT;

/* API Generation Register (AGEN) */
extern const uint8_t _COLOR6_AGEN_DEVICE_ID;
extern const uint8_t _COLOR6_AGEN_MUTATION_NUMBER;

/* Configuration Register - CREG1 */
/* GAIN */
extern const uint8_t _COLOR6_CREG1_GAIN_XYZ_2048;
extern const uint8_t _COLOR6_CREG1_GAIN_XYZ_1024;
extern const uint8_t _COLOR6_CREG1_GAIN_XYZ_512;
extern const uint8_t _COLOR6_CREG1_GAIN_XYZ_256;
extern const uint8_t _COLOR6_CREG1_GAIN_XYZ_128;
extern const uint8_t _COLOR6_CREG1_GAIN_XYZ_64;
extern const uint8_t _COLOR6_CREG1_GAIN_XYZ_32;
extern const uint8_t _COLOR6_CREG1_GAIN_XYZ_16;
extern const uint8_t _COLOR6_CREG1_GAIN_XYZ_8;
extern const uint8_t _COLOR6_CREG1_GAIN_XYZ_4;
extern const uint8_t _COLOR6_CREG1_GAIN_XYZ_2;
extern const uint8_t _COLOR6_CREG1_GAIN_XYZ_1;
/* TIME */
extern const uint8_t _COLOR6_CREG1_TIME_1ms;
extern const uint8_t _COLOR6_CREG1_TIME_2ms;
extern const uint8_t _COLOR6_CREG1_TIME_4ms;
extern const uint8_t _COLOR6_CREG1_TIME_8ms;
extern const uint8_t _COLOR6_CREG1_TIME_16ms;
extern const uint8_t _COLOR6_CREG1_TIME_32ms;
extern const uint8_t _COLOR6_CREG1_TIME_64ms;
extern const uint8_t _COLOR6_CREG1_TIME_128ms;
extern const uint8_t _COLOR6_CREG1_TIME_256ms;
extern const uint8_t _COLOR6_CREG1_TIME_512ms;
extern const uint8_t _COLOR6_CREG1_TIME_1024ms;
extern const uint8_t _COLOR6_CREG1_TIME_2048ms;
extern const uint8_t _COLOR6_CREG1_TIME_4096ms;
extern const uint8_t _COLOR6_CREG1_TIME_8192ms;
extern const uint8_t _COLOR6_CREG1_TIME_16384ms;

/* Configuration Register - CREG2 */
extern const uint8_t _COLOR6_CREG2_EN_TM_DISABLE;
extern const uint8_t _COLOR6_CREG2_EN_TM_ENABLE;
extern const uint8_t _COLOR6_CREG2_DIGITAL_DIVIDER_DISABLE;
extern const uint8_t _COLOR6_CREG2_DIGITAL_DIVIDER_ENABLE;
extern const uint8_t _COLOR6_CREG2_DIVIDER_2;
extern const uint8_t _COLOR6_CREG2_DIVIDER_4;
extern const uint8_t _COLOR6_CREG2_DIVIDER_8;
extern const uint8_t _COLOR6_CREG2_DIVIDER_16;
extern const uint8_t _COLOR6_CREG2_DIVIDER_32;
extern const uint8_t _COLOR6_CREG2_DIVIDER_64;
extern const uint8_t _COLOR6_CREG2_DIVIDER_128;
extern const uint8_t _COLOR6_CREG2_DIVIDER_256;

/* Configuration Register - CREG3 */
extern const uint8_t _COLOR6_CREG3_MMODE_CONT_MODE;
extern const uint8_t _COLOR6_CREG3_MMODE_CMD_MODE;
extern const uint8_t _COLOR6_CREG3_MMODE_SYNS_MODE;
extern const uint8_t _COLOR6_CREG3_MMODE_SIND_MODE;
extern const uint8_t _COLOR6_CREG3_SB_STANDBY_SWITCHED_OFF;
extern const uint8_t _COLOR6_CREG3_SB_STANDBY_SWITCHED_ON;
extern const uint8_t _COLOR6_CREG3_READY_PUSH_PULL_OUT;
extern const uint8_t _COLOR6_CREG3_READY_OPEN_DRAIN_OUT;
extern const uint8_t _COLOR6_CREG3_INTERNAL_CLOCK_1024MHZ;
extern const uint8_t _COLOR6_CREG3_INTERNAL_CLOCK_2048MHZ;
extern const uint8_t _COLOR6_CREG3_INTERNAL_CLOCK_4096MHZ;
extern const uint8_t _COLOR6_CREG3_INTERNAL_CLOCK_8192MHZ;

/* Output Result Register Bank */
extern const uint8_t _COLOR6_MREG_STATUS_REGISTER;
extern const uint8_t _COLOR6_MREG_TEMPERATURE_MEASUREMENT;
extern const uint8_t _COLOR6_MREG_MEASUREMENT_X_CHANNEL;
extern const uint8_t _COLOR6_MREG_MEASUREMENT_Y_CHANNEL;
extern const uint8_t _COLOR6_MREG_MEASUREMENT_Z_CHANNEL;
extern const uint8_t _COLOR6_MREG_OUT_CONVERSION_LSB;
extern const uint8_t _COLOR6_MREG_OUT_CONVERSION_MSB;

/* Status Register */
extern const uint8_t _COLOR6_STATUS_OUTCONVOF;
extern const uint8_t _COLOR6_STATUS_MRESOF;
extern const uint8_t _COLOR6_STATUS_ADCOF;
extern const uint8_t _COLOR6_STATUS_LDATA;
extern const uint8_t _COLOR6_STATUS_NDATA;
extern const uint8_t _COLOR6_STATUS_NOTREADY;
extern const uint8_t _COLOR6_STATUS_STANDBY;
extern const uint8_t _COLOR6_STATUS_POWER;

/* Full Scale Range of detectable irradiance Ee [uW/cm2] */
extern const float _COLOR6_X_FSR_OF_GAIN_2048;
extern const float _COLOR6_Y_FSR_OF_GAIN_2048;
extern const float _COLOR6_Z_FSR_OF_GAIN_2048;
extern const float _COLOR6_X_FSR_OF_GAIN_1024;
extern const float _COLOR6_Y_FSR_OF_GAIN_1024;
extern const float _COLOR6_Z_FSR_OF_GAIN_1024;
extern const float _COLOR6_X_FSR_OF_GAIN_512;
extern const float _COLOR6_Y_FSR_OF_GAIN_512;
extern const float _COLOR6_Z_FSR_OF_GAIN_512;
extern const float _COLOR6_X_FSR_OF_GAIN_256;
extern const float _COLOR6_Y_FSR_OF_GAIN_256;
extern const float _COLOR6_Z_FSR_OF_GAIN_256;
extern const float _COLOR6_X_FSR_OF_GAIN_128;
extern const float _COLOR6_Y_FSR_OF_GAIN_128;
extern const float _COLOR6_Z_FSR_OF_GAIN_128;
extern const float _COLOR6_X_FSR_OF_GAIN_64;
extern const float _COLOR6_Y_FSR_OF_GAIN_64;
extern const float _COLOR6_Z_FSR_OF_GAIN_64;
extern const float _COLOR6_X_FSR_OF_GAIN_32;
extern const float _COLOR6_Y_FSR_OF_GAIN_32;
extern const float _COLOR6_Z_FSR_OF_GAIN_32;
extern const float _COLOR6_X_FSR_OF_GAIN_16;
extern const float _COLOR6_Y_FSR_OF_GAIN_16;
extern const float _COLOR6_Z_FSR_OF_GAIN_16;
extern const float _COLOR6_X_FSR_OF_GAIN_8;
extern const float _COLOR6_Y_FSR_OF_GAIN_8;
extern const float _COLOR6_Z_FSR_OF_GAIN_8;
extern const float _COLOR6_X_FSR_OF_GAIN_4;
extern const float _COLOR6_Y_FSR_OF_GAIN_4;
extern const float _COLOR6_Z_FSR_OF_GAIN_4;
extern const float _COLOR6_X_FSR_OF_GAIN_2;
extern const float _COLOR6_Y_FSR_OF_GAIN_2;
extern const float _COLOR6_Z_FSR_OF_GAIN_2;
extern const float _COLOR6_X_FSR_OF_GAIN_1;
extern const float _COLOR6_Y_FSR_OF_GAIN_1;
extern const float _COLOR6_Z_FSR_OF_GAIN_1;

/* Number of clocks */
extern const uint32_t _COLOR6_NUMBER_OF_CLK_TIME_1ms;
extern const uint32_t _COLOR6_NUMBER_OF_CLK_TIME_2ms;
extern const uint32_t _COLOR6_NUMBER_OF_CLK_TIME_4ms;
extern const uint32_t _COLOR6_NUMBER_OF_CLK_TIME_8ms;
extern const uint32_t _COLOR6_NUMBER_OF_CLK_TIME_16ms;
extern const uint32_t _COLOR6_NUMBER_OF_CLK_TIME_32ms;
extern const uint32_t _COLOR6_NUMBER_OF_CLK_TIME_64ms;
extern const uint32_t _COLOR6_NUMBER_OF_CLK_TIME_128ms;
extern const uint32_t _COLOR6_NUMBER_OF_CLK_TIME_256ms;
extern const uint32_t _COLOR6_NUMBER_OF_CLK_TIME_512ms;
extern const uint32_t _COLOR6_NUMBER_OF_CLK_TIME_1024ms;
extern const uint32_t _COLOR6_NUMBER_OF_CLK_TIME_2048ms;
extern const uint32_t _COLOR6_NUMBER_OF_CLK_TIME_4096ms;
extern const uint32_t _COLOR6_NUMBER_OF_CLK_TIME_8192ms;
extern const uint32_t _COLOR6_NUMBER_OF_CLK_TIME_16384ms;


                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup COLOR6_INIT Driver Initialization */              /** @{ */

#ifdef   __COLOR6_DRV_SPI__
void color6_spiDriverInit(T_COLOR6_P gpioObj, T_COLOR6_P spiObj);
#endif
#ifdef   __COLOR6_DRV_I2C__
void color6_i2cDriverInit(T_COLOR6_P gpioObj, T_COLOR6_P i2cObj, uint8_t slave);
#endif
#ifdef   __COLOR6_DRV_UART__
void color6_uartDriverInit(T_COLOR6_P gpioObj, T_COLOR6_P uartObj);
#endif

// GPIO Only Drivers - remove in other cases
void color6_gpioDriverInit(T_COLOR6_P gpioObj);
                                                                       /** @} */
/** @defgroup COLOR6_FUNC Driver Functions */                   /** @{ */

/**
 * @brief Functions for write one byte in register
 *
 * @param[in] reg    Register in which the data will be written
 * @param[in] _data  Data which be written in the register
 */
void color6_writeByte(uint8_t reg, uint8_t _data);
/**
 * @brief Functions for read one byte data from register
 *
 * @param[in] reg    Register which be read
 * @retval one byte data which is read from the register
 */
uint8_t color6_readByte(uint8_t reg);
/**
 * @brief Functions for read data from register
 *
 * @param[in] reg    Register which be read
 * @retval two byte data which is read from the register
 */
uint16_t color6_readData(uint8_t reg);

/**
 * @brief Functions for converting channel data to Ee data
 *
 * @param[in] channel    channel from which the data will be converted
 * @param[in] MRES_data  data read from the channel
 *
 * @retval Ee channel data
 *
 * The conversion formula uses the formula:
         Ee = ( FSR / NCLK )* MRES
    - Ee -   Input light irradiance regarding to the photodiode’s area within the conversion time interval
    - FSR -  Full Scale Range of detectable input light irradiance Ee
    - NCLK - Number of clock cycles within the conversion time interval TCONV (conversion time interval)
    - MRES - Channel data ( X or Y or Z channel data)
 */
float color6_convertingToEe(uint8_t channel, uint16_t MRES_data);
/**
 * @brief Functions for read temperature
 *
 * @retval temperature in C
 *
 * The measurement result is available as TEMP of the output result registers.  
   The value of the chip temperature is in °C.
 */
float color6_getTemperature();
/**
 * @brief Functions for software reset
 *
 * This function should be called at the start of the program before the configuration of the chip.
 */
void color6_softwareReser();
/**
 * @brief Functions for go to measurement mode
 *
 * This function should be called before the start measurement.
 */
void color6_goToMeasurementMode();







                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_Color6_STM.c
    @example Click_Color6_TIVA.c
    @example Click_Color6_CEC.c
    @example Click_Color6_KINETIS.c
    @example Click_Color6_MSP.c
    @example Click_Color6_PIC.c
    @example Click_Color6_PIC32.c
    @example Click_Color6_DSPIC.c
    @example Click_Color6_AVR.c
    @example Click_Color6_FT90x.c
    @example Click_Color6_STM.mbas
    @example Click_Color6_TIVA.mbas
    @example Click_Color6_CEC.mbas
    @example Click_Color6_KINETIS.mbas
    @example Click_Color6_MSP.mbas
    @example Click_Color6_PIC.mbas
    @example Click_Color6_PIC32.mbas
    @example Click_Color6_DSPIC.mbas
    @example Click_Color6_AVR.mbas
    @example Click_Color6_FT90x.mbas
    @example Click_Color6_STM.mpas
    @example Click_Color6_TIVA.mpas
    @example Click_Color6_CEC.mpas
    @example Click_Color6_KINETIS.mpas
    @example Click_Color6_MSP.mpas
    @example Click_Color6_PIC.mpas
    @example Click_Color6_PIC32.mpas
    @example Click_Color6_DSPIC.mpas
    @example Click_Color6_AVR.mpas
    @example Click_Color6_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __color6_driver.h

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */