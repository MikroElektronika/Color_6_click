_systemInit:
;Click_Color6_STM.c,38 :: 		void systemInit()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_Color6_STM.c,40 :: 		mikrobus_i2cInit( _MIKROBUS1, &_COLOR6_I2C_CFG[0] );
MOVW	R0, #lo_addr(__COLOR6_I2C_CFG+0)
MOVT	R0, #hi_addr(__COLOR6_I2C_CFG+0)
MOV	R1, R0
MOVS	R0, #0
BL	_mikrobus_i2cInit+0
;Click_Color6_STM.c,41 :: 		mikrobus_logInit( _LOG_USBUART_A, 9600 );
MOVW	R1, #9600
MOVS	R0, #32
BL	_mikrobus_logInit+0
;Click_Color6_STM.c,42 :: 		mikrobus_logWrite(" --- System Init --- ",_LOG_LINE);
MOVW	R0, #lo_addr(?lstr1_Click_Color6_STM+0)
MOVT	R0, #hi_addr(?lstr1_Click_Color6_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_Color6_STM.c,43 :: 		Delay_ms( 100 );
MOVW	R7, #20351
MOVT	R7, #18
NOP
NOP
L_systemInit0:
SUBS	R7, R7, #1
BNE	L_systemInit0
NOP
NOP
NOP
;Click_Color6_STM.c,44 :: 		}
L_end_systemInit:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _systemInit
_applicationInit:
;Click_Color6_STM.c,46 :: 		void applicationInit()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_Color6_STM.c,48 :: 		color6_i2cDriverInit( (T_COLOR6_P)&_MIKROBUS1_GPIO, (T_COLOR6_P)&_MIKROBUS1_I2C, 0x74 );
MOVS	R2, #116
MOVW	R1, #lo_addr(__MIKROBUS1_I2C+0)
MOVT	R1, #hi_addr(__MIKROBUS1_I2C+0)
MOVW	R0, #lo_addr(__MIKROBUS1_GPIO+0)
MOVT	R0, #hi_addr(__MIKROBUS1_GPIO+0)
BL	_color6_i2cDriverInit+0
;Click_Color6_STM.c,50 :: 		color6_softwareReser();
BL	_color6_softwareReser+0
;Click_Color6_STM.c,51 :: 		color6_writeByte(_COLOR6_REG_CONFIGURATION_REGISTER_1, _COLOR6_CREG1_GAIN_XYZ_2 | _COLOR6_CREG1_TIME_512ms);
MOVS	R0, __COLOR6_CREG1_GAIN_XYZ_2
ORR	R0, R0, __COLOR6_CREG1_TIME_512ms
UXTB	R1, R0
MOVS	R0, __COLOR6_REG_CONFIGURATION_REGISTER_1
BL	_color6_writeByte+0
;Click_Color6_STM.c,52 :: 		color6_writeByte(_COLOR6_REG_CONFIGURATION_REGISTER_2, 0x80 | _COLOR6_CREG2_EN_TM_ENABLE | _COLOR6_CREG2_DIGITAL_DIVIDER_ENABLE | _COLOR6_CREG2_DIVIDER_16);
MOVS	R0, #128
ORR	R0, R0, __COLOR6_CREG2_EN_TM_ENABLE
UXTB	R0, R0
ORR	R0, R0, __COLOR6_CREG2_DIGITAL_DIVIDER_ENABLE
UXTB	R0, R0
ORR	R0, R0, __COLOR6_CREG2_DIVIDER_16
UXTB	R1, R0
MOVS	R0, __COLOR6_REG_CONFIGURATION_REGISTER_2
BL	_color6_writeByte+0
;Click_Color6_STM.c,53 :: 		color6_writeByte(_COLOR6_REG_CONFIGURATION_REGISTER_3, _COLOR6_CREG3_SB_STANDBY_SWITCHED_ON);
MOVS	R1, __COLOR6_CREG3_SB_STANDBY_SWITCHED_ON
MOVS	R0, __COLOR6_REG_CONFIGURATION_REGISTER_3
BL	_color6_writeByte+0
;Click_Color6_STM.c,54 :: 		color6_writeByte(_COLOR6_REG_BREAK_TIME, 0x52);
MOVS	R1, #82
MOVS	R0, __COLOR6_REG_BREAK_TIME
BL	_color6_writeByte+0
;Click_Color6_STM.c,55 :: 		color6_writeByte(_COLOR6_REG_EDGE_COUNT_VALUE, 0x01);
MOVS	R1, #1
MOVS	R0, __COLOR6_REG_EDGE_COUNT_VALUE
BL	_color6_writeByte+0
;Click_Color6_STM.c,56 :: 		color6_goToMeasurementMode();
BL	_color6_goToMeasurementMode+0
;Click_Color6_STM.c,57 :: 		}
L_end_applicationInit:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _applicationInit
_applicationTask:
;Click_Color6_STM.c,59 :: 		void applicationTask()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_Color6_STM.c,61 :: 		mikrobus_logWrite(" Channel X :  ",_LOG_TEXT);
MOVW	R0, #lo_addr(?lstr2_Click_Color6_STM+0)
MOVT	R0, #hi_addr(?lstr2_Click_Color6_STM+0)
MOVS	R1, #1
BL	_mikrobus_logWrite+0
;Click_Color6_STM.c,62 :: 		X_data = color6_readData(_COLOR6_MREG_MEASUREMENT_X_CHANNEL );
MOVS	R0, __COLOR6_MREG_MEASUREMENT_X_CHANNEL
BL	_color6_readData+0
MOVW	R1, #lo_addr(_X_data+0)
MOVT	R1, #hi_addr(_X_data+0)
STRH	R0, [R1, #0]
;Click_Color6_STM.c,63 :: 		IntToStr(X_data, dataText);
SXTH	R0, R0
MOVW	R1, #lo_addr(_dataText+0)
MOVT	R1, #hi_addr(_dataText+0)
BL	_IntToStr+0
;Click_Color6_STM.c,64 :: 		mikrobus_logWrite(dataText, _LOG_LINE);
MOVS	R1, #2
MOVW	R0, #lo_addr(_dataText+0)
MOVT	R0, #hi_addr(_dataText+0)
BL	_mikrobus_logWrite+0
;Click_Color6_STM.c,66 :: 		mikrobus_logWrite(" Ee X channel data:   ",_LOG_TEXT);
MOVW	R0, #lo_addr(?lstr3_Click_Color6_STM+0)
MOVT	R0, #hi_addr(?lstr3_Click_Color6_STM+0)
MOVS	R1, #1
BL	_mikrobus_logWrite+0
;Click_Color6_STM.c,67 :: 		Ee_data = color6_convertingToEe(_COLOR6_MREG_MEASUREMENT_X_CHANNEL, X_data);
MOVW	R0, #lo_addr(_X_data+0)
MOVT	R0, #hi_addr(_X_data+0)
LDRH	R0, [R0, #0]
UXTH	R1, R0
MOVS	R0, __COLOR6_MREG_MEASUREMENT_X_CHANNEL
BL	_color6_convertingToEe+0
MOVW	R1, #lo_addr(_Ee_data+0)
MOVT	R1, #hi_addr(_Ee_data+0)
STR	R0, [R1, #0]
;Click_Color6_STM.c,68 :: 		FloatToStr(Ee_data, dataText);
MOVW	R1, #lo_addr(_dataText+0)
MOVT	R1, #hi_addr(_dataText+0)
BL	_FloatToStr+0
;Click_Color6_STM.c,69 :: 		mikrobus_logWrite(dataText, _LOG_LINE);
MOVS	R1, #2
MOVW	R0, #lo_addr(_dataText+0)
MOVT	R0, #hi_addr(_dataText+0)
BL	_mikrobus_logWrite+0
;Click_Color6_STM.c,71 :: 		mikrobus_logWrite(" Channel Y :  ",_LOG_TEXT);
MOVW	R0, #lo_addr(?lstr4_Click_Color6_STM+0)
MOVT	R0, #hi_addr(?lstr4_Click_Color6_STM+0)
MOVS	R1, #1
BL	_mikrobus_logWrite+0
;Click_Color6_STM.c,72 :: 		Y_data = color6_readData(_COLOR6_MREG_MEASUREMENT_Y_CHANNEL );
MOVS	R0, __COLOR6_MREG_MEASUREMENT_Y_CHANNEL
BL	_color6_readData+0
MOVW	R1, #lo_addr(_Y_data+0)
MOVT	R1, #hi_addr(_Y_data+0)
STRH	R0, [R1, #0]
;Click_Color6_STM.c,73 :: 		IntToStr(Y_data, dataText);
SXTH	R0, R0
MOVW	R1, #lo_addr(_dataText+0)
MOVT	R1, #hi_addr(_dataText+0)
BL	_IntToStr+0
;Click_Color6_STM.c,74 :: 		mikrobus_logWrite(dataText, _LOG_LINE);
MOVS	R1, #2
MOVW	R0, #lo_addr(_dataText+0)
MOVT	R0, #hi_addr(_dataText+0)
BL	_mikrobus_logWrite+0
;Click_Color6_STM.c,76 :: 		mikrobus_logWrite(" Ee Y channel data:   ",_LOG_TEXT);
MOVW	R0, #lo_addr(?lstr5_Click_Color6_STM+0)
MOVT	R0, #hi_addr(?lstr5_Click_Color6_STM+0)
MOVS	R1, #1
BL	_mikrobus_logWrite+0
;Click_Color6_STM.c,77 :: 		Ee_data = color6_convertingToEe(_COLOR6_MREG_MEASUREMENT_Y_CHANNEL, Y_data);
MOVW	R0, #lo_addr(_Y_data+0)
MOVT	R0, #hi_addr(_Y_data+0)
LDRH	R0, [R0, #0]
UXTH	R1, R0
MOVS	R0, __COLOR6_MREG_MEASUREMENT_Y_CHANNEL
BL	_color6_convertingToEe+0
MOVW	R1, #lo_addr(_Ee_data+0)
MOVT	R1, #hi_addr(_Ee_data+0)
STR	R0, [R1, #0]
;Click_Color6_STM.c,78 :: 		FloatToStr(Ee_data, dataText);
MOVW	R1, #lo_addr(_dataText+0)
MOVT	R1, #hi_addr(_dataText+0)
BL	_FloatToStr+0
;Click_Color6_STM.c,79 :: 		mikrobus_logWrite(dataText, _LOG_LINE);
MOVS	R1, #2
MOVW	R0, #lo_addr(_dataText+0)
MOVT	R0, #hi_addr(_dataText+0)
BL	_mikrobus_logWrite+0
;Click_Color6_STM.c,81 :: 		mikrobus_logWrite(" Channel Z :  ",_LOG_TEXT);
MOVW	R0, #lo_addr(?lstr6_Click_Color6_STM+0)
MOVT	R0, #hi_addr(?lstr6_Click_Color6_STM+0)
MOVS	R1, #1
BL	_mikrobus_logWrite+0
;Click_Color6_STM.c,82 :: 		Z_data = color6_readData(_COLOR6_MREG_MEASUREMENT_Z_CHANNEL );
MOVS	R0, __COLOR6_MREG_MEASUREMENT_Z_CHANNEL
BL	_color6_readData+0
MOVW	R1, #lo_addr(_Z_data+0)
MOVT	R1, #hi_addr(_Z_data+0)
STRH	R0, [R1, #0]
;Click_Color6_STM.c,83 :: 		IntToStr(Z_data, dataText);
SXTH	R0, R0
MOVW	R1, #lo_addr(_dataText+0)
MOVT	R1, #hi_addr(_dataText+0)
BL	_IntToStr+0
;Click_Color6_STM.c,84 :: 		mikrobus_logWrite(dataText, _LOG_LINE);
MOVS	R1, #2
MOVW	R0, #lo_addr(_dataText+0)
MOVT	R0, #hi_addr(_dataText+0)
BL	_mikrobus_logWrite+0
;Click_Color6_STM.c,86 :: 		mikrobus_logWrite(" Ee Z channel data:   ",_LOG_TEXT);
MOVW	R0, #lo_addr(?lstr7_Click_Color6_STM+0)
MOVT	R0, #hi_addr(?lstr7_Click_Color6_STM+0)
MOVS	R1, #1
BL	_mikrobus_logWrite+0
;Click_Color6_STM.c,87 :: 		Ee_data = color6_convertingToEe(_COLOR6_MREG_MEASUREMENT_Z_CHANNEL, Z_data);
MOVW	R0, #lo_addr(_Z_data+0)
MOVT	R0, #hi_addr(_Z_data+0)
LDRH	R0, [R0, #0]
UXTH	R1, R0
MOVS	R0, __COLOR6_MREG_MEASUREMENT_Z_CHANNEL
BL	_color6_convertingToEe+0
MOVW	R1, #lo_addr(_Ee_data+0)
MOVT	R1, #hi_addr(_Ee_data+0)
STR	R0, [R1, #0]
;Click_Color6_STM.c,88 :: 		FloatToStr(Ee_data, dataText);
MOVW	R1, #lo_addr(_dataText+0)
MOVT	R1, #hi_addr(_dataText+0)
BL	_FloatToStr+0
;Click_Color6_STM.c,89 :: 		mikrobus_logWrite(dataText, _LOG_LINE);
MOVS	R1, #2
MOVW	R0, #lo_addr(_dataText+0)
MOVT	R0, #hi_addr(_dataText+0)
BL	_mikrobus_logWrite+0
;Click_Color6_STM.c,91 :: 		mikrobus_logWrite(" Temperature :  ",_LOG_TEXT);
MOVW	R0, #lo_addr(?lstr8_Click_Color6_STM+0)
MOVT	R0, #hi_addr(?lstr8_Click_Color6_STM+0)
MOVS	R1, #1
BL	_mikrobus_logWrite+0
;Click_Color6_STM.c,92 :: 		temperature = color6_getTemperature();
BL	_color6_getTemperature+0
MOVW	R1, #lo_addr(_temperature+0)
MOVT	R1, #hi_addr(_temperature+0)
STR	R0, [R1, #0]
;Click_Color6_STM.c,93 :: 		FloatToStr(temperature, dataText);
MOVW	R1, #lo_addr(_dataText+0)
MOVT	R1, #hi_addr(_dataText+0)
BL	_FloatToStr+0
;Click_Color6_STM.c,94 :: 		mikrobus_logWrite(dataText, _LOG_LINE);
MOVS	R1, #2
MOVW	R0, #lo_addr(_dataText+0)
MOVT	R0, #hi_addr(_dataText+0)
BL	_mikrobus_logWrite+0
;Click_Color6_STM.c,96 :: 		mikrobus_logWrite("\r\n",_LOG_LINE);
MOVW	R0, #lo_addr(?lstr9_Click_Color6_STM+0)
MOVT	R0, #hi_addr(?lstr9_Click_Color6_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_Color6_STM.c,97 :: 		Delay_ms( 2000 );
MOVW	R7, #13823
MOVT	R7, #366
NOP
NOP
L_applicationTask2:
SUBS	R7, R7, #1
BNE	L_applicationTask2
NOP
NOP
NOP
;Click_Color6_STM.c,98 :: 		}
L_end_applicationTask:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _applicationTask
_main:
;Click_Color6_STM.c,100 :: 		void main()
;Click_Color6_STM.c,102 :: 		systemInit();
BL	_systemInit+0
;Click_Color6_STM.c,103 :: 		applicationInit();
BL	_applicationInit+0
;Click_Color6_STM.c,105 :: 		while (1)
L_main4:
;Click_Color6_STM.c,107 :: 		applicationTask();
BL	_applicationTask+0
;Click_Color6_STM.c,108 :: 		}
IT	AL
BAL	L_main4
;Click_Color6_STM.c,109 :: 		}
L_end_main:
L__main_end_loop:
B	L__main_end_loop
; end of _main
