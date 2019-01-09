![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# Color6 Click

- **CIC Prefix**  : COLOR6
- **Author**      : Katarina Perendic
- **Verison**     : 1.0.0
- **Date**        : maj 2018.

---

### Software Support

We provide a library for the Color6 Click on our [LibStock](https://libstock.mikroe.com/projects/view/2416/color-6-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

The library initializes and defines the I2C bus driver and drivers that offer a choice for writing data in register.
The library includes function for configuration chip for measurement, functions for read temperature, channel (X or Y or Z) data.
The user also has the function ```float color6_convertingToEe(uint8_t channel, uint16_t MRES_data)``` which converts channel data to Ee 
(Input light irradiance regarding to the photodiode’s area within the conversion time interval) data. 

Key functions :

- ``` uint16_t color6_readData(uint8_t reg) ``` - Functions for read data from register
- ``` float color6_convertingToEe(uint8_t channel, uint16_t MRES_data) ``` - Functions for converting channel data to Ee data
- ``` void color6_goToMeasurementMode() ``` - Functions for go to measurement mode
- ``` float color6_getTemperature() ``` - Functions for read temperature in C

**Examples Description**

The application is composed of three sections :

- System Initialization - Initializes I2C module
- Application Initialization - Initializes driver init and configuration chip for measurement
- Application Task - (code snippet) - Reads values from the X / Y / Z channel and 
                                      converts to Ee (input light irradiance regarding to the photodiode’s area
                                      within the conversion time interval) data. 
                                      This data logs on USB UART every 2 seconds.


```.c
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
```

The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/2416/color-6-click) page.

Other mikroE Libraries used in the example:

- Conversions
- I2C
- UART

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
