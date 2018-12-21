
_systemInit:

;Click_Color6_PIC.c,41 :: 		void systemInit()
;Click_Color6_PIC.c,43 :: 		mikrobus_i2cInit( _MIKROBUS1, &_COLOR6_I2C_CFG[0] );
	CLRF        FARG_mikrobus_i2cInit_bus+0 
	MOVLW       __COLOR6_I2C_CFG+0
	MOVWF       FARG_mikrobus_i2cInit_cfg+0 
	MOVLW       hi_addr(__COLOR6_I2C_CFG+0)
	MOVWF       FARG_mikrobus_i2cInit_cfg+1 
	MOVLW       higher_addr(__COLOR6_I2C_CFG+0)
	MOVWF       FARG_mikrobus_i2cInit_cfg+2 
	CALL        _mikrobus_i2cInit+0, 0
;Click_Color6_PIC.c,44 :: 		mikrobus_logInit( _LOG_USBUART, 9600 );
	MOVLW       16
	MOVWF       FARG_mikrobus_logInit_port+0 
	MOVLW       128
	MOVWF       FARG_mikrobus_logInit_baud+0 
	MOVLW       37
	MOVWF       FARG_mikrobus_logInit_baud+1 
	MOVLW       0
	MOVWF       FARG_mikrobus_logInit_baud+2 
	MOVWF       FARG_mikrobus_logInit_baud+3 
	CALL        _mikrobus_logInit+0, 0
;Click_Color6_PIC.c,45 :: 		mikrobus_logWrite(" --- System Init --- ",_LOG_LINE);
	MOVLW       ?lstr1_Click_Color6_PIC+0
	MOVWF       FARG_mikrobus_logWrite_data_+0 
	MOVLW       hi_addr(?lstr1_Click_Color6_PIC+0)
	MOVWF       FARG_mikrobus_logWrite_data_+1 
	MOVLW       2
	MOVWF       FARG_mikrobus_logWrite_format+0 
	CALL        _mikrobus_logWrite+0, 0
;Click_Color6_PIC.c,46 :: 		Delay_ms( 100 );
	MOVLW       9
	MOVWF       R11, 0
	MOVLW       30
	MOVWF       R12, 0
	MOVLW       228
	MOVWF       R13, 0
L_systemInit0:
	DECFSZ      R13, 1, 1
	BRA         L_systemInit0
	DECFSZ      R12, 1, 1
	BRA         L_systemInit0
	DECFSZ      R11, 1, 1
	BRA         L_systemInit0
	NOP
;Click_Color6_PIC.c,47 :: 		}
L_end_systemInit:
	RETURN      0
; end of _systemInit

_applicationInit:

;Click_Color6_PIC.c,49 :: 		void applicationInit()
;Click_Color6_PIC.c,51 :: 		color6_i2cDriverInit( (T_COLOR6_P)&_MIKROBUS1_GPIO, (T_COLOR6_P)&_MIKROBUS1_I2C, 0x74 );
	MOVLW       __MIKROBUS1_GPIO+0
	MOVWF       FARG_color6_i2cDriverInit_gpioObj+0 
	MOVLW       hi_addr(__MIKROBUS1_GPIO+0)
	MOVWF       FARG_color6_i2cDriverInit_gpioObj+1 
	MOVLW       higher_addr(__MIKROBUS1_GPIO+0)
	MOVWF       FARG_color6_i2cDriverInit_gpioObj+2 
	MOVLW       __MIKROBUS1_I2C+0
	MOVWF       FARG_color6_i2cDriverInit_i2cObj+0 
	MOVLW       hi_addr(__MIKROBUS1_I2C+0)
	MOVWF       FARG_color6_i2cDriverInit_i2cObj+1 
	MOVLW       higher_addr(__MIKROBUS1_I2C+0)
	MOVWF       FARG_color6_i2cDriverInit_i2cObj+2 
	MOVLW       116
	MOVWF       FARG_color6_i2cDriverInit_slave+0 
	CALL        _color6_i2cDriverInit+0, 0
;Click_Color6_PIC.c,53 :: 		color6_softwareReser();
	CALL        _color6_softwareReser+0, 0
;Click_Color6_PIC.c,54 :: 		color6_writeByte(_COLOR6_REG_CONFIGURATION_REGISTER_1, _COLOR6_CREG1_GAIN_XYZ_2 | _COLOR6_CREG1_TIME_512ms);
	MOVLW       __COLOR6_REG_CONFIGURATION_REGISTER_1
	MOVWF       FARG_color6_writeByte_reg+0 
	MOVLW       __COLOR6_CREG1_GAIN_XYZ_2
	MOVWF       R0 
	MOVLW       __COLOR6_CREG1_TIME_512ms
	IORWF       R0, 0 
	MOVWF       FARG_color6_writeByte__data+0 
	CALL        _color6_writeByte+0, 0
;Click_Color6_PIC.c,55 :: 		color6_writeByte(_COLOR6_REG_CONFIGURATION_REGISTER_2, 0x80 | _COLOR6_CREG2_EN_TM_ENABLE | _COLOR6_CREG2_DIGITAL_DIVIDER_ENABLE | _COLOR6_CREG2_DIVIDER_16);
	MOVLW       __COLOR6_REG_CONFIGURATION_REGISTER_2
	MOVWF       FARG_color6_writeByte_reg+0 
	MOVLW       __COLOR6_CREG2_EN_TM_ENABLE
	MOVWF       R0 
	MOVLW       128
	IORWF       R0, 0 
	MOVWF       FARG_color6_writeByte__data+0 
	MOVLW       __COLOR6_CREG2_DIGITAL_DIVIDER_ENABLE
	IORWF       FARG_color6_writeByte__data+0, 1 
	MOVLW       __COLOR6_CREG2_DIVIDER_16
	IORWF       FARG_color6_writeByte__data+0, 1 
	CALL        _color6_writeByte+0, 0
;Click_Color6_PIC.c,56 :: 		color6_writeByte(_COLOR6_REG_CONFIGURATION_REGISTER_3, _COLOR6_CREG3_SB_STANDBY_SWITCHED_ON);
	MOVLW       __COLOR6_REG_CONFIGURATION_REGISTER_3
	MOVWF       FARG_color6_writeByte_reg+0 
	MOVLW       __COLOR6_CREG3_SB_STANDBY_SWITCHED_ON
	MOVWF       FARG_color6_writeByte__data+0 
	CALL        _color6_writeByte+0, 0
;Click_Color6_PIC.c,57 :: 		color6_writeByte(_COLOR6_REG_BREAK_TIME, 0x52);
	MOVLW       __COLOR6_REG_BREAK_TIME
	MOVWF       FARG_color6_writeByte_reg+0 
	MOVLW       82
	MOVWF       FARG_color6_writeByte__data+0 
	CALL        _color6_writeByte+0, 0
;Click_Color6_PIC.c,58 :: 		color6_writeByte(_COLOR6_REG_EDGE_COUNT_VALUE, 0x01);
	MOVLW       __COLOR6_REG_EDGE_COUNT_VALUE
	MOVWF       FARG_color6_writeByte_reg+0 
	MOVLW       1
	MOVWF       FARG_color6_writeByte__data+0 
	CALL        _color6_writeByte+0, 0
;Click_Color6_PIC.c,59 :: 		color6_goToMeasurementMode();
	CALL        _color6_goToMeasurementMode+0, 0
;Click_Color6_PIC.c,60 :: 		}
L_end_applicationInit:
	RETURN      0
; end of _applicationInit

_applicationTask:

;Click_Color6_PIC.c,62 :: 		void applicationTask()
;Click_Color6_PIC.c,64 :: 		mikrobus_logWrite(" Channel X :  ",_LOG_TEXT);
	MOVLW       ?lstr2_Click_Color6_PIC+0
	MOVWF       FARG_mikrobus_logWrite_data_+0 
	MOVLW       hi_addr(?lstr2_Click_Color6_PIC+0)
	MOVWF       FARG_mikrobus_logWrite_data_+1 
	MOVLW       1
	MOVWF       FARG_mikrobus_logWrite_format+0 
	CALL        _mikrobus_logWrite+0, 0
;Click_Color6_PIC.c,65 :: 		X_data = color6_readData(_COLOR6_MREG_MEASUREMENT_X_CHANNEL );
	MOVLW       __COLOR6_MREG_MEASUREMENT_X_CHANNEL
	MOVWF       FARG_color6_readData_reg+0 
	CALL        _color6_readData+0, 0
	MOVF        R0, 0 
	MOVWF       _X_data+0 
	MOVF        R1, 0 
	MOVWF       _X_data+1 
;Click_Color6_PIC.c,66 :: 		IntToStr(X_data, dataText);
	MOVF        R0, 0 
	MOVWF       FARG_IntToStr_input+0 
	MOVF        R1, 0 
	MOVWF       FARG_IntToStr_input+1 
	MOVLW       _dataText+0
	MOVWF       FARG_IntToStr_output+0 
	MOVLW       hi_addr(_dataText+0)
	MOVWF       FARG_IntToStr_output+1 
	CALL        _IntToStr+0, 0
;Click_Color6_PIC.c,67 :: 		mikrobus_logWrite(dataText, _LOG_LINE);
	MOVLW       _dataText+0
	MOVWF       FARG_mikrobus_logWrite_data_+0 
	MOVLW       hi_addr(_dataText+0)
	MOVWF       FARG_mikrobus_logWrite_data_+1 
	MOVLW       2
	MOVWF       FARG_mikrobus_logWrite_format+0 
	CALL        _mikrobus_logWrite+0, 0
;Click_Color6_PIC.c,69 :: 		mikrobus_logWrite(" Ee X channel data:   ",_LOG_TEXT);
	MOVLW       ?lstr3_Click_Color6_PIC+0
	MOVWF       FARG_mikrobus_logWrite_data_+0 
	MOVLW       hi_addr(?lstr3_Click_Color6_PIC+0)
	MOVWF       FARG_mikrobus_logWrite_data_+1 
	MOVLW       1
	MOVWF       FARG_mikrobus_logWrite_format+0 
	CALL        _mikrobus_logWrite+0, 0
;Click_Color6_PIC.c,70 :: 		Ee_data = color6_convertingToEe(_COLOR6_MREG_MEASUREMENT_X_CHANNEL, X_data);
	MOVLW       __COLOR6_MREG_MEASUREMENT_X_CHANNEL
	MOVWF       FARG_color6_convertingToEe_channel+0 
	MOVF        _X_data+0, 0 
	MOVWF       FARG_color6_convertingToEe_MRES_data+0 
	MOVF        _X_data+1, 0 
	MOVWF       FARG_color6_convertingToEe_MRES_data+1 
	CALL        _color6_convertingToEe+0, 0
	MOVF        R0, 0 
	MOVWF       _Ee_data+0 
	MOVF        R1, 0 
	MOVWF       _Ee_data+1 
	MOVF        R2, 0 
	MOVWF       _Ee_data+2 
	MOVF        R3, 0 
	MOVWF       _Ee_data+3 
;Click_Color6_PIC.c,71 :: 		FloatToStr(Ee_data, dataText);
	MOVF        R0, 0 
	MOVWF       FARG_FloatToStr_fnum+0 
	MOVF        R1, 0 
	MOVWF       FARG_FloatToStr_fnum+1 
	MOVF        R2, 0 
	MOVWF       FARG_FloatToStr_fnum+2 
	MOVF        R3, 0 
	MOVWF       FARG_FloatToStr_fnum+3 
	MOVLW       _dataText+0
	MOVWF       FARG_FloatToStr_str+0 
	MOVLW       hi_addr(_dataText+0)
	MOVWF       FARG_FloatToStr_str+1 
	CALL        _FloatToStr+0, 0
;Click_Color6_PIC.c,72 :: 		mikrobus_logWrite(dataText, _LOG_LINE);
	MOVLW       _dataText+0
	MOVWF       FARG_mikrobus_logWrite_data_+0 
	MOVLW       hi_addr(_dataText+0)
	MOVWF       FARG_mikrobus_logWrite_data_+1 
	MOVLW       2
	MOVWF       FARG_mikrobus_logWrite_format+0 
	CALL        _mikrobus_logWrite+0, 0
;Click_Color6_PIC.c,74 :: 		mikrobus_logWrite(" Channel Y :  ",_LOG_TEXT);
	MOVLW       ?lstr4_Click_Color6_PIC+0
	MOVWF       FARG_mikrobus_logWrite_data_+0 
	MOVLW       hi_addr(?lstr4_Click_Color6_PIC+0)
	MOVWF       FARG_mikrobus_logWrite_data_+1 
	MOVLW       1
	MOVWF       FARG_mikrobus_logWrite_format+0 
	CALL        _mikrobus_logWrite+0, 0
;Click_Color6_PIC.c,75 :: 		Y_data = color6_readData(_COLOR6_MREG_MEASUREMENT_Y_CHANNEL );
	MOVLW       __COLOR6_MREG_MEASUREMENT_Y_CHANNEL
	MOVWF       FARG_color6_readData_reg+0 
	CALL        _color6_readData+0, 0
	MOVF        R0, 0 
	MOVWF       _Y_data+0 
	MOVF        R1, 0 
	MOVWF       _Y_data+1 
;Click_Color6_PIC.c,76 :: 		IntToStr(Y_data, dataText);
	MOVF        R0, 0 
	MOVWF       FARG_IntToStr_input+0 
	MOVF        R1, 0 
	MOVWF       FARG_IntToStr_input+1 
	MOVLW       _dataText+0
	MOVWF       FARG_IntToStr_output+0 
	MOVLW       hi_addr(_dataText+0)
	MOVWF       FARG_IntToStr_output+1 
	CALL        _IntToStr+0, 0
;Click_Color6_PIC.c,77 :: 		mikrobus_logWrite(dataText, _LOG_LINE);
	MOVLW       _dataText+0
	MOVWF       FARG_mikrobus_logWrite_data_+0 
	MOVLW       hi_addr(_dataText+0)
	MOVWF       FARG_mikrobus_logWrite_data_+1 
	MOVLW       2
	MOVWF       FARG_mikrobus_logWrite_format+0 
	CALL        _mikrobus_logWrite+0, 0
;Click_Color6_PIC.c,79 :: 		mikrobus_logWrite(" Ee Y channel data:   ",_LOG_TEXT);
	MOVLW       ?lstr5_Click_Color6_PIC+0
	MOVWF       FARG_mikrobus_logWrite_data_+0 
	MOVLW       hi_addr(?lstr5_Click_Color6_PIC+0)
	MOVWF       FARG_mikrobus_logWrite_data_+1 
	MOVLW       1
	MOVWF       FARG_mikrobus_logWrite_format+0 
	CALL        _mikrobus_logWrite+0, 0
;Click_Color6_PIC.c,80 :: 		Ee_data = color6_convertingToEe(_COLOR6_MREG_MEASUREMENT_Y_CHANNEL, Y_data);
	MOVLW       __COLOR6_MREG_MEASUREMENT_Y_CHANNEL
	MOVWF       FARG_color6_convertingToEe_channel+0 
	MOVF        _Y_data+0, 0 
	MOVWF       FARG_color6_convertingToEe_MRES_data+0 
	MOVF        _Y_data+1, 0 
	MOVWF       FARG_color6_convertingToEe_MRES_data+1 
	CALL        _color6_convertingToEe+0, 0
	MOVF        R0, 0 
	MOVWF       _Ee_data+0 
	MOVF        R1, 0 
	MOVWF       _Ee_data+1 
	MOVF        R2, 0 
	MOVWF       _Ee_data+2 
	MOVF        R3, 0 
	MOVWF       _Ee_data+3 
;Click_Color6_PIC.c,81 :: 		FloatToStr(Ee_data, dataText);
	MOVF        R0, 0 
	MOVWF       FARG_FloatToStr_fnum+0 
	MOVF        R1, 0 
	MOVWF       FARG_FloatToStr_fnum+1 
	MOVF        R2, 0 
	MOVWF       FARG_FloatToStr_fnum+2 
	MOVF        R3, 0 
	MOVWF       FARG_FloatToStr_fnum+3 
	MOVLW       _dataText+0
	MOVWF       FARG_FloatToStr_str+0 
	MOVLW       hi_addr(_dataText+0)
	MOVWF       FARG_FloatToStr_str+1 
	CALL        _FloatToStr+0, 0
;Click_Color6_PIC.c,82 :: 		mikrobus_logWrite(dataText, _LOG_LINE);
	MOVLW       _dataText+0
	MOVWF       FARG_mikrobus_logWrite_data_+0 
	MOVLW       hi_addr(_dataText+0)
	MOVWF       FARG_mikrobus_logWrite_data_+1 
	MOVLW       2
	MOVWF       FARG_mikrobus_logWrite_format+0 
	CALL        _mikrobus_logWrite+0, 0
;Click_Color6_PIC.c,84 :: 		mikrobus_logWrite(" Channel Z :  ",_LOG_TEXT);
	MOVLW       ?lstr6_Click_Color6_PIC+0
	MOVWF       FARG_mikrobus_logWrite_data_+0 
	MOVLW       hi_addr(?lstr6_Click_Color6_PIC+0)
	MOVWF       FARG_mikrobus_logWrite_data_+1 
	MOVLW       1
	MOVWF       FARG_mikrobus_logWrite_format+0 
	CALL        _mikrobus_logWrite+0, 0
;Click_Color6_PIC.c,85 :: 		Z_data = color6_readData(_COLOR6_MREG_MEASUREMENT_Z_CHANNEL );
	MOVLW       __COLOR6_MREG_MEASUREMENT_Z_CHANNEL
	MOVWF       FARG_color6_readData_reg+0 
	CALL        _color6_readData+0, 0
	MOVF        R0, 0 
	MOVWF       _Z_data+0 
	MOVF        R1, 0 
	MOVWF       _Z_data+1 
;Click_Color6_PIC.c,86 :: 		IntToStr(Z_data, dataText);
	MOVF        R0, 0 
	MOVWF       FARG_IntToStr_input+0 
	MOVF        R1, 0 
	MOVWF       FARG_IntToStr_input+1 
	MOVLW       _dataText+0
	MOVWF       FARG_IntToStr_output+0 
	MOVLW       hi_addr(_dataText+0)
	MOVWF       FARG_IntToStr_output+1 
	CALL        _IntToStr+0, 0
;Click_Color6_PIC.c,87 :: 		mikrobus_logWrite(dataText, _LOG_LINE);
	MOVLW       _dataText+0
	MOVWF       FARG_mikrobus_logWrite_data_+0 
	MOVLW       hi_addr(_dataText+0)
	MOVWF       FARG_mikrobus_logWrite_data_+1 
	MOVLW       2
	MOVWF       FARG_mikrobus_logWrite_format+0 
	CALL        _mikrobus_logWrite+0, 0
;Click_Color6_PIC.c,89 :: 		mikrobus_logWrite(" Ee Z channel data:   ",_LOG_TEXT);
	MOVLW       ?lstr7_Click_Color6_PIC+0
	MOVWF       FARG_mikrobus_logWrite_data_+0 
	MOVLW       hi_addr(?lstr7_Click_Color6_PIC+0)
	MOVWF       FARG_mikrobus_logWrite_data_+1 
	MOVLW       1
	MOVWF       FARG_mikrobus_logWrite_format+0 
	CALL        _mikrobus_logWrite+0, 0
;Click_Color6_PIC.c,90 :: 		Ee_data = color6_convertingToEe(_COLOR6_MREG_MEASUREMENT_Z_CHANNEL, Z_data);
	MOVLW       __COLOR6_MREG_MEASUREMENT_Z_CHANNEL
	MOVWF       FARG_color6_convertingToEe_channel+0 
	MOVF        _Z_data+0, 0 
	MOVWF       FARG_color6_convertingToEe_MRES_data+0 
	MOVF        _Z_data+1, 0 
	MOVWF       FARG_color6_convertingToEe_MRES_data+1 
	CALL        _color6_convertingToEe+0, 0
	MOVF        R0, 0 
	MOVWF       _Ee_data+0 
	MOVF        R1, 0 
	MOVWF       _Ee_data+1 
	MOVF        R2, 0 
	MOVWF       _Ee_data+2 
	MOVF        R3, 0 
	MOVWF       _Ee_data+3 
;Click_Color6_PIC.c,91 :: 		FloatToStr(Ee_data, dataText);
	MOVF        R0, 0 
	MOVWF       FARG_FloatToStr_fnum+0 
	MOVF        R1, 0 
	MOVWF       FARG_FloatToStr_fnum+1 
	MOVF        R2, 0 
	MOVWF       FARG_FloatToStr_fnum+2 
	MOVF        R3, 0 
	MOVWF       FARG_FloatToStr_fnum+3 
	MOVLW       _dataText+0
	MOVWF       FARG_FloatToStr_str+0 
	MOVLW       hi_addr(_dataText+0)
	MOVWF       FARG_FloatToStr_str+1 
	CALL        _FloatToStr+0, 0
;Click_Color6_PIC.c,92 :: 		mikrobus_logWrite(dataText, _LOG_LINE);
	MOVLW       _dataText+0
	MOVWF       FARG_mikrobus_logWrite_data_+0 
	MOVLW       hi_addr(_dataText+0)
	MOVWF       FARG_mikrobus_logWrite_data_+1 
	MOVLW       2
	MOVWF       FARG_mikrobus_logWrite_format+0 
	CALL        _mikrobus_logWrite+0, 0
;Click_Color6_PIC.c,94 :: 		mikrobus_logWrite(" Temperature :  ",_LOG_TEXT);
	MOVLW       ?lstr8_Click_Color6_PIC+0
	MOVWF       FARG_mikrobus_logWrite_data_+0 
	MOVLW       hi_addr(?lstr8_Click_Color6_PIC+0)
	MOVWF       FARG_mikrobus_logWrite_data_+1 
	MOVLW       1
	MOVWF       FARG_mikrobus_logWrite_format+0 
	CALL        _mikrobus_logWrite+0, 0
;Click_Color6_PIC.c,95 :: 		temperature = color6_getTemperature();
	CALL        _color6_getTemperature+0, 0
	MOVF        R0, 0 
	MOVWF       _temperature+0 
	MOVF        R1, 0 
	MOVWF       _temperature+1 
	MOVF        R2, 0 
	MOVWF       _temperature+2 
	MOVF        R3, 0 
	MOVWF       _temperature+3 
;Click_Color6_PIC.c,96 :: 		FloatToStr(temperature, dataText);
	MOVF        R0, 0 
	MOVWF       FARG_FloatToStr_fnum+0 
	MOVF        R1, 0 
	MOVWF       FARG_FloatToStr_fnum+1 
	MOVF        R2, 0 
	MOVWF       FARG_FloatToStr_fnum+2 
	MOVF        R3, 0 
	MOVWF       FARG_FloatToStr_fnum+3 
	MOVLW       _dataText+0
	MOVWF       FARG_FloatToStr_str+0 
	MOVLW       hi_addr(_dataText+0)
	MOVWF       FARG_FloatToStr_str+1 
	CALL        _FloatToStr+0, 0
;Click_Color6_PIC.c,97 :: 		mikrobus_logWrite(dataText, _LOG_LINE);
	MOVLW       _dataText+0
	MOVWF       FARG_mikrobus_logWrite_data_+0 
	MOVLW       hi_addr(_dataText+0)
	MOVWF       FARG_mikrobus_logWrite_data_+1 
	MOVLW       2
	MOVWF       FARG_mikrobus_logWrite_format+0 
	CALL        _mikrobus_logWrite+0, 0
;Click_Color6_PIC.c,99 :: 		mikrobus_logWrite(" ",_LOG_LINE);
	MOVLW       ?lstr9_Click_Color6_PIC+0
	MOVWF       FARG_mikrobus_logWrite_data_+0 
	MOVLW       hi_addr(?lstr9_Click_Color6_PIC+0)
	MOVWF       FARG_mikrobus_logWrite_data_+1 
	MOVLW       2
	MOVWF       FARG_mikrobus_logWrite_format+0 
	CALL        _mikrobus_logWrite+0, 0
;Click_Color6_PIC.c,100 :: 		Delay_ms( 2000 );
	MOVLW       163
	MOVWF       R11, 0
	MOVLW       87
	MOVWF       R12, 0
	MOVLW       2
	MOVWF       R13, 0
L_applicationTask1:
	DECFSZ      R13, 1, 1
	BRA         L_applicationTask1
	DECFSZ      R12, 1, 1
	BRA         L_applicationTask1
	DECFSZ      R11, 1, 1
	BRA         L_applicationTask1
	NOP
;Click_Color6_PIC.c,101 :: 		}
L_end_applicationTask:
	RETURN      0
; end of _applicationTask

_main:

;Click_Color6_PIC.c,103 :: 		void main()
;Click_Color6_PIC.c,105 :: 		systemInit();
	CALL        _systemInit+0, 0
;Click_Color6_PIC.c,106 :: 		applicationInit();
	CALL        _applicationInit+0, 0
;Click_Color6_PIC.c,108 :: 		while (1)
L_main2:
;Click_Color6_PIC.c,110 :: 		applicationTask();
	CALL        _applicationTask+0, 0
;Click_Color6_PIC.c,111 :: 		}
	GOTO        L_main2
;Click_Color6_PIC.c,112 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
