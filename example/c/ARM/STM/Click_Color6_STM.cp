#line 1 "D:/Clicks_git/Color_6_click/SW/example/c/ARM/STM/Click_Color6_STM.c"
#line 1 "d:/clicks_git/color_6_click/sw/example/c/arm/stm/click_color6_types.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdint.h"





typedef signed char int8_t;
typedef signed int int16_t;
typedef signed long int int32_t;
typedef signed long long int64_t;


typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long int uint32_t;
typedef unsigned long long uint64_t;


typedef signed char int_least8_t;
typedef signed int int_least16_t;
typedef signed long int int_least32_t;
typedef signed long long int_least64_t;


typedef unsigned char uint_least8_t;
typedef unsigned int uint_least16_t;
typedef unsigned long int uint_least32_t;
typedef unsigned long long uint_least64_t;



typedef signed long int int_fast8_t;
typedef signed long int int_fast16_t;
typedef signed long int int_fast32_t;
typedef signed long long int_fast64_t;


typedef unsigned long int uint_fast8_t;
typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long long uint_fast64_t;


typedef signed long int intptr_t;
typedef unsigned long int uintptr_t;


typedef signed long long intmax_t;
typedef unsigned long long uintmax_t;
#line 1 "d:/clicks_git/color_6_click/sw/example/c/arm/stm/click_color6_config.h"
#line 1 "d:/clicks_git/color_6_click/sw/example/c/arm/stm/click_color6_types.h"
#line 3 "d:/clicks_git/color_6_click/sw/example/c/arm/stm/click_color6_config.h"
const uint32_t _COLOR6_I2C_CFG[ 1 ] =
{
 400000
};
#line 1 "d:/clicks_git/color_6_click/sw/library/__color6_driver.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdint.h"
#line 58 "d:/clicks_git/color_6_click/sw/library/__color6_driver.h"
extern const uint8_t _COLOR6_REG_OPERATIONAL_STATE;
extern const uint8_t _COLOR6_REG_API_GENERATION;
extern const uint8_t _COLOR6_REG_CONFIGURATION_REGISTER_1;
extern const uint8_t _COLOR6_REG_CONFIGURATION_REGISTER_2;
extern const uint8_t _COLOR6_REG_CONFIGURATION_REGISTER_3;
extern const uint8_t _COLOR6_REG_BREAK_TIME;
extern const uint8_t _COLOR6_REG_EDGE_COUNT_VALUE;
extern const uint8_t _COLOR6_REG_OPTIONS_REGISTER;


extern const uint8_t _COLOR6_OSR_STOP_MEASUREMENT;
extern const uint8_t _COLOR6_OSR_START_MEASUREMENT;
extern const uint8_t _COLOR6_OSR_POWER_DOWN_SWITCHED_OFF;
extern const uint8_t _COLOR6_OSR_POWER_DOWN_SWITCHED_ON;
extern const uint8_t _COLOR6_OSR_SOFTWARE_RESET;
extern const uint8_t _COLOR6_OSR_DOS_CONFIGURATION;
extern const uint8_t _COLOR6_OSR_DOS_MEASUREMENT;


extern const uint8_t _COLOR6_AGEN_DEVICE_ID;
extern const uint8_t _COLOR6_AGEN_MUTATION_NUMBER;



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


extern const uint8_t _COLOR6_MREG_STATUS_REGISTER;
extern const uint8_t _COLOR6_MREG_TEMPERATURE_MEASUREMENT;
extern const uint8_t _COLOR6_MREG_MEASUREMENT_X_CHANNEL;
extern const uint8_t _COLOR6_MREG_MEASUREMENT_Y_CHANNEL;
extern const uint8_t _COLOR6_MREG_MEASUREMENT_Z_CHANNEL;
extern const uint8_t _COLOR6_MREG_OUT_CONVERSION_LSB;
extern const uint8_t _COLOR6_MREG_OUT_CONVERSION_MSB;


extern const uint8_t _COLOR6_STATUS_OUTCONVOF;
extern const uint8_t _COLOR6_STATUS_MRESOF;
extern const uint8_t _COLOR6_STATUS_ADCOF;
extern const uint8_t _COLOR6_STATUS_LDATA;
extern const uint8_t _COLOR6_STATUS_NDATA;
extern const uint8_t _COLOR6_STATUS_NOTREADY;
extern const uint8_t _COLOR6_STATUS_STANDBY;
extern const uint8_t _COLOR6_STATUS_POWER;


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
#line 225 "d:/clicks_git/color_6_click/sw/library/__color6_driver.h"
void color6_i2cDriverInit( const uint8_t*  gpioObj,  const uint8_t*  i2cObj, uint8_t slave);
#line 232 "d:/clicks_git/color_6_click/sw/library/__color6_driver.h"
void color6_gpioDriverInit( const uint8_t*  gpioObj);



void color6_writeByte(uint8_t reg, uint8_t _data);
uint8_t color6_readByte(uint8_t reg);
uint16_t color6_readData(uint8_t reg);
float color6_getTemperature();
void color6_softwareReser();
void color6_goToMeasurementMode();
float color6_convertingToEe(uint8_t channel, uint16_t MRES_data);
#line 31 "D:/Clicks_git/Color_6_click/SW/example/c/ARM/STM/Click_Color6_STM.c"
char dataText[ 50 ] = {0};
uint16_t X_data = 0;
uint16_t Y_data = 0;
uint16_t Z_data = 0;
float Ee_data;
float temperature;

void systemInit()
{
 mikrobus_i2cInit( _MIKROBUS1, &_COLOR6_I2C_CFG[0] );
 mikrobus_logInit( _LOG_USBUART_A, 9600 );
 mikrobus_logWrite(" --- System Init --- ",_LOG_LINE);
 Delay_ms( 100 );
}

void applicationInit()
{
 color6_i2cDriverInit( ( const uint8_t* )&_MIKROBUS1_GPIO, ( const uint8_t* )&_MIKROBUS1_I2C, 0x74 );

 color6_softwareReser();
 color6_writeByte(_COLOR6_REG_CONFIGURATION_REGISTER_1, _COLOR6_CREG1_GAIN_XYZ_2 | _COLOR6_CREG1_TIME_512ms);
 color6_writeByte(_COLOR6_REG_CONFIGURATION_REGISTER_2, 0x80 | _COLOR6_CREG2_EN_TM_ENABLE | _COLOR6_CREG2_DIGITAL_DIVIDER_ENABLE | _COLOR6_CREG2_DIVIDER_16);
 color6_writeByte(_COLOR6_REG_CONFIGURATION_REGISTER_3, _COLOR6_CREG3_SB_STANDBY_SWITCHED_ON);
 color6_writeByte(_COLOR6_REG_BREAK_TIME, 0x52);
 color6_writeByte(_COLOR6_REG_EDGE_COUNT_VALUE, 0x01);
 color6_goToMeasurementMode();
}

void applicationTask()
{
 mikrobus_logWrite(" Channel X :  ",_LOG_TEXT);
 X_data = color6_readData(_COLOR6_MREG_MEASUREMENT_X_CHANNEL );
 IntToStr(X_data, dataText);
 mikrobus_logWrite(dataText, _LOG_LINE);

 mikrobus_logWrite(" Ee X channel data:   ",_LOG_TEXT);
 Ee_data = color6_convertingToEe(_COLOR6_MREG_MEASUREMENT_X_CHANNEL, X_data);
 FloatToStr(Ee_data, dataText);
 mikrobus_logWrite(dataText, _LOG_LINE);

 mikrobus_logWrite(" Channel Y :  ",_LOG_TEXT);
 Y_data = color6_readData(_COLOR6_MREG_MEASUREMENT_Y_CHANNEL );
 IntToStr(Y_data, dataText);
 mikrobus_logWrite(dataText, _LOG_LINE);

 mikrobus_logWrite(" Ee Y channel data:   ",_LOG_TEXT);
 Ee_data = color6_convertingToEe(_COLOR6_MREG_MEASUREMENT_Y_CHANNEL, Y_data);
 FloatToStr(Ee_data, dataText);
 mikrobus_logWrite(dataText, _LOG_LINE);

 mikrobus_logWrite(" Channel Z :  ",_LOG_TEXT);
 Z_data = color6_readData(_COLOR6_MREG_MEASUREMENT_Z_CHANNEL );
 IntToStr(Z_data, dataText);
 mikrobus_logWrite(dataText, _LOG_LINE);

 mikrobus_logWrite(" Ee Z channel data:   ",_LOG_TEXT);
 Ee_data = color6_convertingToEe(_COLOR6_MREG_MEASUREMENT_Z_CHANNEL, Z_data);
 FloatToStr(Ee_data, dataText);
 mikrobus_logWrite(dataText, _LOG_LINE);

 mikrobus_logWrite(" Temperature :  ",_LOG_TEXT);
 temperature = color6_getTemperature();
 FloatToStr(temperature, dataText);
 mikrobus_logWrite(dataText, _LOG_LINE);

 mikrobus_logWrite("\r\n",_LOG_LINE);
 Delay_ms( 2000 );
}

void main()
{
 systemInit();
 applicationInit();

 while (1)
 {
 applicationTask();
 }
}
