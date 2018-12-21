/*
Example for Color6 Click

    Date          : maj 2018.
    Author        : Katarina Perendic

Test configuration KINETIS :
    
    MCU              : MK64
    Dev. Board       : HEXIWEAR
    ARM Compiler ver : v6.0.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes I2C module
- Application Initialization - Initializes driver init and configuration chip for measurement
- Application Task - (code snippet) - Reads values from the X / Y / Z channel and
                                      converts to Ee (input light irradiance regarding to the photodiode’s area
                                      within the conversion time interval) data.
                                      This data logs on USB UART every 2 seconds.

*/

#include "Click_Color6_types.h"
#include "Click_Color6_config.h"

char dataText[ 50 ] = {0};
uint16_t X_data = 0;
uint16_t Y_data = 0;
uint16_t Z_data = 0;
float Ee_data;
float temperature;

void systemInit()
{
    mikrobus_i2cInit( _MIKROBUS1, &_COLOR6_I2C_CFG[0] );
    mikrobus_logInit( _LOG_USBUART, 9600 );
    mikrobus_logWrite(" --- System Init --- ",_LOG_LINE);
    Delay_ms( 100 );
}

void applicationInit()
{
    color6_i2cDriverInit( (T_COLOR6_P)&_MIKROBUS1_GPIO, (T_COLOR6_P)&_MIKROBUS1_I2C, 0x74 );

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

    mikrobus_logWrite(" ",_LOG_LINE);
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