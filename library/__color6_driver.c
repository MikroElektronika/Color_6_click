/*
    __color6_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__color6_driver.h"
#include "__color6_hal.c"

/* ------------------------------------------------------------------- MACROS */

/* Register */
const uint8_t _COLOR6_REG_OPERATIONAL_STATE        = 0x00;
const uint8_t _COLOR6_REG_API_GENERATION           = 0x02;
const uint8_t _COLOR6_REG_CONFIGURATION_REGISTER_1 = 0x06;
const uint8_t _COLOR6_REG_CONFIGURATION_REGISTER_2 = 0x07;
const uint8_t _COLOR6_REG_CONFIGURATION_REGISTER_3 = 0x08;
const uint8_t _COLOR6_REG_BREAK_TIME               = 0x09;
const uint8_t _COLOR6_REG_EDGE_COUNT_VALUE         = 0x0A;
const uint8_t _COLOR6_REG_OPTIONS_REGISTER         = 0x0B;

/* Operational State Register – OSR */
const uint8_t _COLOR6_OSR_STOP_MEASUREMENT  = 0x00;
const uint8_t _COLOR6_OSR_START_MEASUREMENT = 0x80;
const uint8_t _COLOR6_OSR_POWER_DOWN_SWITCHED_OFF = 0x00;
const uint8_t _COLOR6_OSR_POWER_DOWN_SWITCHED_ON  = 0x40;
const uint8_t _COLOR6_OSR_SOFTWARE_RESET          = 0x08;
const uint8_t _COLOR6_OSR_DOS_CONFIGURATION       = 0x02;
const uint8_t _COLOR6_OSR_DOS_MEASUREMENT         = 0x03;

/* API Generation Register (AGEN) */
const uint8_t _COLOR6_AGEN_DEVICE_ID       = 0x01;
const uint8_t _COLOR6_AGEN_MUTATION_NUMBER = 0x02;

/* Configuration Register - CREG1 */
/* GAIN */
const uint8_t _COLOR6_CREG1_GAIN_XYZ_2048 = 0x00;
const uint8_t _COLOR6_CREG1_GAIN_XYZ_1024 = 0x10;
const uint8_t _COLOR6_CREG1_GAIN_XYZ_512  = 0x20;
const uint8_t _COLOR6_CREG1_GAIN_XYZ_256  = 0x30;
const uint8_t _COLOR6_CREG1_GAIN_XYZ_128  = 0x40;
const uint8_t _COLOR6_CREG1_GAIN_XYZ_64   = 0x50;
const uint8_t _COLOR6_CREG1_GAIN_XYZ_32   = 0x60;
const uint8_t _COLOR6_CREG1_GAIN_XYZ_16   = 0x70;
const uint8_t _COLOR6_CREG1_GAIN_XYZ_8    = 0x80;
const uint8_t _COLOR6_CREG1_GAIN_XYZ_4    = 0x90;
const uint8_t _COLOR6_CREG1_GAIN_XYZ_2    = 0xA0;
const uint8_t _COLOR6_CREG1_GAIN_XYZ_1    = 0xB0;
/* TIME */
const uint8_t _COLOR6_CREG1_TIME_1ms      = 0x00;
const uint8_t _COLOR6_CREG1_TIME_2ms      = 0x01;
const uint8_t _COLOR6_CREG1_TIME_4ms      = 0x02;
const uint8_t _COLOR6_CREG1_TIME_8ms      = 0x03;
const uint8_t _COLOR6_CREG1_TIME_16ms     = 0x04;
const uint8_t _COLOR6_CREG1_TIME_32ms     = 0x05;
const uint8_t _COLOR6_CREG1_TIME_64ms     = 0x06;
const uint8_t _COLOR6_CREG1_TIME_128ms    = 0x07;
const uint8_t _COLOR6_CREG1_TIME_256ms    = 0x08;
const uint8_t _COLOR6_CREG1_TIME_512ms    = 0x09;
const uint8_t _COLOR6_CREG1_TIME_1024ms   = 0x0A;
const uint8_t _COLOR6_CREG1_TIME_2048ms   = 0x0B;
const uint8_t _COLOR6_CREG1_TIME_4096ms   = 0x0C;
const uint8_t _COLOR6_CREG1_TIME_8192ms   = 0x0D;
const uint8_t _COLOR6_CREG1_TIME_16384ms  = 0x0E;

/* Configuration Register - CREG2 */
const uint8_t _COLOR6_CREG2_EN_TM_DISABLE = 0x00;
const uint8_t _COLOR6_CREG2_EN_TM_ENABLE  = 0x40;
const uint8_t _COLOR6_CREG2_DIGITAL_DIVIDER_DISABLE = 0x00;
const uint8_t _COLOR6_CREG2_DIGITAL_DIVIDER_ENABLE  = 0x08;
const uint8_t _COLOR6_CREG2_DIVIDER_2   = 0x00;
const uint8_t _COLOR6_CREG2_DIVIDER_4   = 0x01;
const uint8_t _COLOR6_CREG2_DIVIDER_8   = 0x02;
const uint8_t _COLOR6_CREG2_DIVIDER_16  = 0x03;
const uint8_t _COLOR6_CREG2_DIVIDER_32  = 0x04;
const uint8_t _COLOR6_CREG2_DIVIDER_64  = 0x05;
const uint8_t _COLOR6_CREG2_DIVIDER_128 = 0x06;
const uint8_t _COLOR6_CREG2_DIVIDER_256 = 0x07;

/* Configuration Register - CREG3 */
const uint8_t _COLOR6_CREG3_MMODE_CONT_MODE = 0x00;
const uint8_t _COLOR6_CREG3_MMODE_CMD_MODE  = 0x40;
const uint8_t _COLOR6_CREG3_MMODE_SYNS_MODE = 0x80;
const uint8_t _COLOR6_CREG3_MMODE_SIND_MODE = 0xC0;
const uint8_t _COLOR6_CREG3_SB_STANDBY_SWITCHED_OFF = 0x00;
const uint8_t _COLOR6_CREG3_SB_STANDBY_SWITCHED_ON  = 0x10;
const uint8_t _COLOR6_CREG3_READY_PUSH_PULL_OUT     = 0x00;
const uint8_t _COLOR6_CREG3_READY_OPEN_DRAIN_OUT    = 0x08;
const uint8_t _COLOR6_CREG3_INTERNAL_CLOCK_1024MHZ  = 0x00;
const uint8_t _COLOR6_CREG3_INTERNAL_CLOCK_2048MHZ  = 0x01;
const uint8_t _COLOR6_CREG3_INTERNAL_CLOCK_4096MHZ  = 0x02;
const uint8_t _COLOR6_CREG3_INTERNAL_CLOCK_8192MHZ  = 0x03;

/* Output Result Register Bank */
const uint8_t _COLOR6_MREG_STATUS_REGISTER         = 0x00;
const uint8_t _COLOR6_MREG_TEMPERATURE_MEASUREMENT = 0x01;
const uint8_t _COLOR6_MREG_MEASUREMENT_X_CHANNEL   = 0x02;
const uint8_t _COLOR6_MREG_MEASUREMENT_Y_CHANNEL   = 0x03;
const uint8_t _COLOR6_MREG_MEASUREMENT_Z_CHANNEL   = 0x04;
const uint8_t _COLOR6_MREG_OUT_CONVERSION_LSB      = 0x05;
const uint8_t _COLOR6_MREG_OUT_CONVERSION_MSB      = 0x06;

/* Status Register */
const uint8_t _COLOR6_STATUS_OUTCONVOF = 0x80;
const uint8_t _COLOR6_STATUS_MRESOF    = 0x40;
const uint8_t _COLOR6_STATUS_ADCOF     = 0x20;
const uint8_t _COLOR6_STATUS_LDATA     = 0x10;
const uint8_t _COLOR6_STATUS_NDATA     = 0x08;
const uint8_t _COLOR6_STATUS_NOTREADY  = 0x04;
const uint8_t _COLOR6_STATUS_STANDBY   = 0x02;
const uint8_t _COLOR6_STATUS_POWER     = 0x01;

/* Full Scale Range of detectable irradiance Ee [uW/cm2] */
const float _COLOR6_X_FSR_OF_GAIN_2048 = 0.866;
const float _COLOR6_Y_FSR_OF_GAIN_2048 = 0.932;
const float _COLOR6_Z_FSR_OF_GAIN_2048 = 0.501;
const float _COLOR6_X_FSR_OF_GAIN_1024 = 1.732;
const float _COLOR6_Y_FSR_OF_GAIN_1024 = 1.865;
const float _COLOR6_Z_FSR_OF_GAIN_1024 = 1.002;
const float _COLOR6_X_FSR_OF_GAIN_512 = 3.463;
const float _COLOR6_Y_FSR_OF_GAIN_512 = 3.730;
const float _COLOR6_Z_FSR_OF_GAIN_512 = 2.003;
const float _COLOR6_X_FSR_OF_GAIN_256 = 6.927;
const float _COLOR6_Y_FSR_OF_GAIN_256 = 7.460;
const float _COLOR6_Z_FSR_OF_GAIN_256 = 4.006;
const float _COLOR6_X_FSR_OF_GAIN_128 = 13.854;
const float _COLOR6_Y_FSR_OF_GAIN_128 = 14.919;
const float _COLOR6_Z_FSR_OF_GAIN_128 = 8.012;
const float _COLOR6_X_FSR_OF_GAIN_64 = 27.707;
const float _COLOR6_Y_FSR_OF_GAIN_64 = 29.838;
const float _COLOR6_Z_FSR_OF_GAIN_64 = 16.024;
const float _COLOR6_X_FSR_OF_GAIN_32 = 55.414;
const float _COLOR6_Y_FSR_OF_GAIN_32 = 59.677;
const float _COLOR6_Z_FSR_OF_GAIN_32 = 32.048;
const float _COLOR6_X_FSR_OF_GAIN_16 = 110.828;
const float _COLOR6_Y_FSR_OF_GAIN_16 = 119.354;
const float _COLOR6_Z_FSR_OF_GAIN_16 = 64.097;
const float _COLOR6_X_FSR_OF_GAIN_8 = 221.657;
const float _COLOR6_Y_FSR_OF_GAIN_8 = 238.707;
const float _COLOR6_Z_FSR_OF_GAIN_8 = 128.194;
const float _COLOR6_X_FSR_OF_GAIN_4 = 443.314;
const float _COLOR6_Y_FSR_OF_GAIN_4 = 477.415;
const float _COLOR6_Z_FSR_OF_GAIN_4 = 256.387;
const float _COLOR6_X_FSR_OF_GAIN_2 = 886.628;
const float _COLOR6_Y_FSR_OF_GAIN_2 = 954.830;
const float _COLOR6_Z_FSR_OF_GAIN_2 = 512.774;
const float _COLOR6_X_FSR_OF_GAIN_1 = 1773.255;
const float _COLOR6_Y_FSR_OF_GAIN_1 = 1909.659;
const float _COLOR6_Z_FSR_OF_GAIN_1 = 1025.548;

/* Number of clocks */
const uint32_t _COLOR6_NUMBER_OF_CLK_TIME_1ms     = 1024;
const uint32_t _COLOR6_NUMBER_OF_CLK_TIME_2ms     = 2048;
const uint32_t _COLOR6_NUMBER_OF_CLK_TIME_4ms     = 4096;
const uint32_t _COLOR6_NUMBER_OF_CLK_TIME_8ms     = 8192;
const uint32_t _COLOR6_NUMBER_OF_CLK_TIME_16ms    = 16384;
const uint32_t _COLOR6_NUMBER_OF_CLK_TIME_32ms    = 32768;
const uint32_t _COLOR6_NUMBER_OF_CLK_TIME_64ms    = 65536;
const uint32_t _COLOR6_NUMBER_OF_CLK_TIME_128ms   = 131072;
const uint32_t _COLOR6_NUMBER_OF_CLK_TIME_256ms   = 262144;
const uint32_t _COLOR6_NUMBER_OF_CLK_TIME_512ms   = 524288;
const uint32_t _COLOR6_NUMBER_OF_CLK_TIME_1024ms  = 1048576;
const uint32_t _COLOR6_NUMBER_OF_CLK_TIME_2048ms  = 2097152;
const uint32_t _COLOR6_NUMBER_OF_CLK_TIME_4096ms  = 4194304;
const uint32_t _COLOR6_NUMBER_OF_CLK_TIME_8192ms  = 8388608;
const uint32_t _COLOR6_NUMBER_OF_CLK_TIME_16384ms = 16777216;

/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __COLOR6_DRV_I2C__
static uint8_t _slaveAddress;
#endif

static uint8_t _setGain;
static uint8_t _setTime;
static float   _FSR;
static uint32_t _numOfClk;


static uint8_t _channel_time[15] =
{
    _COLOR6_CREG1_TIME_1ms,
    _COLOR6_CREG1_TIME_2ms,
    _COLOR6_CREG1_TIME_4ms,
    _COLOR6_CREG1_TIME_8ms,
    _COLOR6_CREG1_TIME_16ms,
    _COLOR6_CREG1_TIME_32ms,
    _COLOR6_CREG1_TIME_64ms,
    _COLOR6_CREG1_TIME_128ms,
    _COLOR6_CREG1_TIME_256ms,
    _COLOR6_CREG1_TIME_512ms,
    _COLOR6_CREG1_TIME_1024ms,
    _COLOR6_CREG1_TIME_2048ms,
    _COLOR6_CREG1_TIME_4096ms,
    _COLOR6_CREG1_TIME_8192ms,
    _COLOR6_CREG1_TIME_16384ms
};
static uint32_t _number_of_clock[15] =
{
    _COLOR6_NUMBER_OF_CLK_TIME_1ms,
    _COLOR6_NUMBER_OF_CLK_TIME_2ms,
    _COLOR6_NUMBER_OF_CLK_TIME_4ms,
    _COLOR6_NUMBER_OF_CLK_TIME_8ms,
    _COLOR6_NUMBER_OF_CLK_TIME_16ms,
    _COLOR6_NUMBER_OF_CLK_TIME_32ms,
    _COLOR6_NUMBER_OF_CLK_TIME_64ms,
    _COLOR6_NUMBER_OF_CLK_TIME_128ms,
    _COLOR6_NUMBER_OF_CLK_TIME_256ms,
    _COLOR6_NUMBER_OF_CLK_TIME_512ms,
    _COLOR6_NUMBER_OF_CLK_TIME_1024ms,
    _COLOR6_NUMBER_OF_CLK_TIME_2048ms,
    _COLOR6_NUMBER_OF_CLK_TIME_4096ms,
    _COLOR6_NUMBER_OF_CLK_TIME_8192ms,
    _COLOR6_NUMBER_OF_CLK_TIME_16384ms
};

static uint8_t _channel_gain[12] =
{
    _COLOR6_CREG1_GAIN_XYZ_2048,
    _COLOR6_CREG1_GAIN_XYZ_1024,
    _COLOR6_CREG1_GAIN_XYZ_512,
    _COLOR6_CREG1_GAIN_XYZ_256,
    _COLOR6_CREG1_GAIN_XYZ_128,
    _COLOR6_CREG1_GAIN_XYZ_64,
    _COLOR6_CREG1_GAIN_XYZ_32,
    _COLOR6_CREG1_GAIN_XYZ_16,
    _COLOR6_CREG1_GAIN_XYZ_8,
    _COLOR6_CREG1_GAIN_XYZ_4,
    _COLOR6_CREG1_GAIN_XYZ_2,
    _COLOR6_CREG1_GAIN_XYZ_1
};

static float _X_channel_FSR[12] =
{
    _COLOR6_X_FSR_OF_GAIN_2048,
    _COLOR6_X_FSR_OF_GAIN_1024,
    _COLOR6_X_FSR_OF_GAIN_512,
    _COLOR6_X_FSR_OF_GAIN_256,
    _COLOR6_X_FSR_OF_GAIN_128,
    _COLOR6_X_FSR_OF_GAIN_64,
    _COLOR6_X_FSR_OF_GAIN_32,
    _COLOR6_X_FSR_OF_GAIN_16,
    _COLOR6_X_FSR_OF_GAIN_8,
    _COLOR6_X_FSR_OF_GAIN_4,
    _COLOR6_X_FSR_OF_GAIN_2,
    _COLOR6_X_FSR_OF_GAIN_1
};
static float _Y_channel_FSR[12] =
{
    _COLOR6_Y_FSR_OF_GAIN_2048,
    _COLOR6_Y_FSR_OF_GAIN_1024,
    _COLOR6_Y_FSR_OF_GAIN_512,
    _COLOR6_Y_FSR_OF_GAIN_256,
    _COLOR6_Y_FSR_OF_GAIN_128,
    _COLOR6_Y_FSR_OF_GAIN_64,
    _COLOR6_Y_FSR_OF_GAIN_32,
    _COLOR6_Y_FSR_OF_GAIN_16,
    _COLOR6_Y_FSR_OF_GAIN_8,
    _COLOR6_Y_FSR_OF_GAIN_4,
    _COLOR6_Y_FSR_OF_GAIN_2,
    _COLOR6_Y_FSR_OF_GAIN_1
};

static float _Z_channel_FSR[12] =
{
    _COLOR6_Z_FSR_OF_GAIN_2048,
    _COLOR6_Z_FSR_OF_GAIN_1024,
    _COLOR6_Z_FSR_OF_GAIN_512,
    _COLOR6_Z_FSR_OF_GAIN_256,
    _COLOR6_Z_FSR_OF_GAIN_128,
    _COLOR6_Z_FSR_OF_GAIN_64,
    _COLOR6_Z_FSR_OF_GAIN_32,
    _COLOR6_Z_FSR_OF_GAIN_16,
    _COLOR6_Z_FSR_OF_GAIN_8,
    _COLOR6_Z_FSR_OF_GAIN_4,
    _COLOR6_Z_FSR_OF_GAIN_2,
    _COLOR6_Z_FSR_OF_GAIN_1
};

/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */



/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __COLOR6_DRV_SPI__

void color6_spiDriverInit(T_COLOR6_P gpioObj, T_COLOR6_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
}

#endif
#ifdef   __COLOR6_DRV_I2C__

void color6_i2cDriverInit(T_COLOR6_P gpioObj, T_COLOR6_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
}

#endif
#ifdef   __COLOR6_DRV_UART__

void color6_uartDriverInit(T_COLOR6_P gpioObj, T_COLOR6_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
}

#endif
/* ----------------------------------------------------------- IMPLEMENTATION */

void color6_writeByte(uint8_t reg, uint8_t _data)
{
    uint8_t writeReg[ 2 ];

    writeReg[ 0 ] = reg;
    writeReg[ 1 ] = _data;
    
    hal_i2cStart();
    hal_i2cWrite(_slaveAddress, writeReg, 2, END_MODE_STOP);
    
    if (reg == _COLOR6_REG_CONFIGURATION_REGISTER_1)
    {
        _setGain = (_data & 0xF0);
        _setTime = (_data & 0x0F);
    }
}

uint8_t color6_readByte(uint8_t reg)
{
    uint8_t writeReg[ 1 ];
    uint8_t readReg[ 1 ] = {0};
   
    writeReg[ 0 ] = reg;
    hal_i2cStart();
    hal_i2cWrite(_slaveAddress, writeReg, 1, END_MODE_RESTART);
    hal_i2cRead(_slaveAddress, readReg, 1, END_MODE_STOP);

    return readReg[ 0 ];
}

uint16_t color6_readData(uint8_t reg)
{
    uint8_t writeReg[ 1 ];
    uint8_t readReg[ 2 ] = {0};
    uint16_t readData = 0;

    writeReg[ 0 ] = reg;
    hal_i2cStart();
    hal_i2cWrite(_slaveAddress, writeReg, 1, END_MODE_RESTART);
    hal_i2cRead(_slaveAddress, readReg, 2, END_MODE_STOP);

    readData = readReg[ 1 ];
    readData = readData << 8;
    readData = readData | readreg[ 0 ];
    
    return readData;
}

float color6_getTemperature()
{
    uint16_t channelData;
    float floatData;
    
    channelData = color6_readData(_COLOR6_MREG_TEMPERATURE_MEASUREMENT);
    channelData = channelData & 0x0FFF;
    floatData = (channelData * 0.05) - 66.9;
    return floatData;
}

void color6_softwareReser()
{
    color6_writeByte(_COLOR6_REG_OPERATIONAL_STATE, 0x4A);
}

void color6_goToMeasurementMode()
{
    Delay_1sec();
    color6_writeByte(_COLOR6_REG_OPERATIONAL_STATE, 0x83);
    Delay_1sec();
}

float color6_convertingToEe(uint8_t channel, uint16_t MRES_data)
{
    float dataValue;
    uint8_t cnt;
    
    for (cnt = 0; cnt < 12; cnt++)
    {
        if (_channel_gain[ cnt ] == _setGain)
        {
             if (channel == _COLOR6_MREG_MEASUREMENT_X_CHANNEL)
             {
                 _FSR = _X_channel_FSR[ cnt ];
             }
             else if (channel == _COLOR6_MREG_MEASUREMENT_Y_CHANNEL)
             {
                 _FSR = _Y_channel_FSR[ cnt ];
             }
             else if (channel == _COLOR6_MREG_MEASUREMENT_Z_CHANNEL)
             {
                 _FSR = _Z_channel_FSR[ cnt ];
             }
        }
        if (_channel_time[ cnt ] == _setTime)
        {
             _numOfClk = _number_of_clock[ cnt ];
        }
    }
    
    dataValue = (float)(_FSR / _numOfClk) * (float)MRES_data;

    return dataValue;
}


/* -------------------------------------------------------------------------- */
/*
  __color6_driver.c

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