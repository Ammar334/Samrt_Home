#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/project.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/project.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=ECU_layer/Char_lCD/ecu_chr_lcd.c ECU_layer/DC_Motor/ecu_Dc_motor.c ECU_layer/ecu_relay/ecu_relay.c ECU_layer/key_pad/ecu_key_pad.c ECU_layer/LED/ecu_led.c ECU_layer/Pir_sensor/Pir_sensor.c ECU_layer/push_button/ecu_push_button.c ECU_layer/RealTimeClockDS1307/RealTimeClockDS1307.c ECU_layer/Servo_Motor/Servo_motor.c ECU_layer/seven_segment/ecu_seven_segment.c ECU_layer/TC74_TempSensor/TC74_TempSensor.c ECU_layer/ecu_initialize.c MCAL_layer/ADC/hal_ADC.c MCAL_layer/CCP/CCP1.c MCAL_layer/EEPROM/hal_eeprom.c MCAL_layer/GPIO/hal_gpio.c MCAL_layer/I2C/I2C.c MCAL_layer/Interrupt/mcal_external_Interrupt.c MCAL_layer/Interrupt/mcal_internal_Interrupt.c MCAL_layer/Interrupt/mcal_Interrupt_manger.c MCAL_layer/SPI/spi.c MCAL_layer/Timer0/Timer0.c MCAL_layer/Timer1/Timer1.c MCAL_layer/Timer2/Timer2.c MCAL_layer/Timer3/Timer3.c MCAL_layer/Uart/uart.c MCAL_layer/device_config.c MCAL_layer/Mcal_Initialize.c application.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/ECU_layer/Char_lCD/ecu_chr_lcd.p1 ${OBJECTDIR}/ECU_layer/DC_Motor/ecu_Dc_motor.p1 ${OBJECTDIR}/ECU_layer/ecu_relay/ecu_relay.p1 ${OBJECTDIR}/ECU_layer/key_pad/ecu_key_pad.p1 ${OBJECTDIR}/ECU_layer/LED/ecu_led.p1 ${OBJECTDIR}/ECU_layer/Pir_sensor/Pir_sensor.p1 ${OBJECTDIR}/ECU_layer/push_button/ecu_push_button.p1 ${OBJECTDIR}/ECU_layer/RealTimeClockDS1307/RealTimeClockDS1307.p1 ${OBJECTDIR}/ECU_layer/Servo_Motor/Servo_motor.p1 ${OBJECTDIR}/ECU_layer/seven_segment/ecu_seven_segment.p1 ${OBJECTDIR}/ECU_layer/TC74_TempSensor/TC74_TempSensor.p1 ${OBJECTDIR}/ECU_layer/ecu_initialize.p1 ${OBJECTDIR}/MCAL_layer/ADC/hal_ADC.p1 ${OBJECTDIR}/MCAL_layer/CCP/CCP1.p1 ${OBJECTDIR}/MCAL_layer/EEPROM/hal_eeprom.p1 ${OBJECTDIR}/MCAL_layer/GPIO/hal_gpio.p1 ${OBJECTDIR}/MCAL_layer/I2C/I2C.p1 ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_external_Interrupt.p1 ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_internal_Interrupt.p1 ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_Interrupt_manger.p1 ${OBJECTDIR}/MCAL_layer/SPI/spi.p1 ${OBJECTDIR}/MCAL_layer/Timer0/Timer0.p1 ${OBJECTDIR}/MCAL_layer/Timer1/Timer1.p1 ${OBJECTDIR}/MCAL_layer/Timer2/Timer2.p1 ${OBJECTDIR}/MCAL_layer/Timer3/Timer3.p1 ${OBJECTDIR}/MCAL_layer/Uart/uart.p1 ${OBJECTDIR}/MCAL_layer/device_config.p1 ${OBJECTDIR}/MCAL_layer/Mcal_Initialize.p1 ${OBJECTDIR}/application.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/ECU_layer/Char_lCD/ecu_chr_lcd.p1.d ${OBJECTDIR}/ECU_layer/DC_Motor/ecu_Dc_motor.p1.d ${OBJECTDIR}/ECU_layer/ecu_relay/ecu_relay.p1.d ${OBJECTDIR}/ECU_layer/key_pad/ecu_key_pad.p1.d ${OBJECTDIR}/ECU_layer/LED/ecu_led.p1.d ${OBJECTDIR}/ECU_layer/Pir_sensor/Pir_sensor.p1.d ${OBJECTDIR}/ECU_layer/push_button/ecu_push_button.p1.d ${OBJECTDIR}/ECU_layer/RealTimeClockDS1307/RealTimeClockDS1307.p1.d ${OBJECTDIR}/ECU_layer/Servo_Motor/Servo_motor.p1.d ${OBJECTDIR}/ECU_layer/seven_segment/ecu_seven_segment.p1.d ${OBJECTDIR}/ECU_layer/TC74_TempSensor/TC74_TempSensor.p1.d ${OBJECTDIR}/ECU_layer/ecu_initialize.p1.d ${OBJECTDIR}/MCAL_layer/ADC/hal_ADC.p1.d ${OBJECTDIR}/MCAL_layer/CCP/CCP1.p1.d ${OBJECTDIR}/MCAL_layer/EEPROM/hal_eeprom.p1.d ${OBJECTDIR}/MCAL_layer/GPIO/hal_gpio.p1.d ${OBJECTDIR}/MCAL_layer/I2C/I2C.p1.d ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_external_Interrupt.p1.d ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_internal_Interrupt.p1.d ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_Interrupt_manger.p1.d ${OBJECTDIR}/MCAL_layer/SPI/spi.p1.d ${OBJECTDIR}/MCAL_layer/Timer0/Timer0.p1.d ${OBJECTDIR}/MCAL_layer/Timer1/Timer1.p1.d ${OBJECTDIR}/MCAL_layer/Timer2/Timer2.p1.d ${OBJECTDIR}/MCAL_layer/Timer3/Timer3.p1.d ${OBJECTDIR}/MCAL_layer/Uart/uart.p1.d ${OBJECTDIR}/MCAL_layer/device_config.p1.d ${OBJECTDIR}/MCAL_layer/Mcal_Initialize.p1.d ${OBJECTDIR}/application.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/ECU_layer/Char_lCD/ecu_chr_lcd.p1 ${OBJECTDIR}/ECU_layer/DC_Motor/ecu_Dc_motor.p1 ${OBJECTDIR}/ECU_layer/ecu_relay/ecu_relay.p1 ${OBJECTDIR}/ECU_layer/key_pad/ecu_key_pad.p1 ${OBJECTDIR}/ECU_layer/LED/ecu_led.p1 ${OBJECTDIR}/ECU_layer/Pir_sensor/Pir_sensor.p1 ${OBJECTDIR}/ECU_layer/push_button/ecu_push_button.p1 ${OBJECTDIR}/ECU_layer/RealTimeClockDS1307/RealTimeClockDS1307.p1 ${OBJECTDIR}/ECU_layer/Servo_Motor/Servo_motor.p1 ${OBJECTDIR}/ECU_layer/seven_segment/ecu_seven_segment.p1 ${OBJECTDIR}/ECU_layer/TC74_TempSensor/TC74_TempSensor.p1 ${OBJECTDIR}/ECU_layer/ecu_initialize.p1 ${OBJECTDIR}/MCAL_layer/ADC/hal_ADC.p1 ${OBJECTDIR}/MCAL_layer/CCP/CCP1.p1 ${OBJECTDIR}/MCAL_layer/EEPROM/hal_eeprom.p1 ${OBJECTDIR}/MCAL_layer/GPIO/hal_gpio.p1 ${OBJECTDIR}/MCAL_layer/I2C/I2C.p1 ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_external_Interrupt.p1 ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_internal_Interrupt.p1 ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_Interrupt_manger.p1 ${OBJECTDIR}/MCAL_layer/SPI/spi.p1 ${OBJECTDIR}/MCAL_layer/Timer0/Timer0.p1 ${OBJECTDIR}/MCAL_layer/Timer1/Timer1.p1 ${OBJECTDIR}/MCAL_layer/Timer2/Timer2.p1 ${OBJECTDIR}/MCAL_layer/Timer3/Timer3.p1 ${OBJECTDIR}/MCAL_layer/Uart/uart.p1 ${OBJECTDIR}/MCAL_layer/device_config.p1 ${OBJECTDIR}/MCAL_layer/Mcal_Initialize.p1 ${OBJECTDIR}/application.p1

# Source Files
SOURCEFILES=ECU_layer/Char_lCD/ecu_chr_lcd.c ECU_layer/DC_Motor/ecu_Dc_motor.c ECU_layer/ecu_relay/ecu_relay.c ECU_layer/key_pad/ecu_key_pad.c ECU_layer/LED/ecu_led.c ECU_layer/Pir_sensor/Pir_sensor.c ECU_layer/push_button/ecu_push_button.c ECU_layer/RealTimeClockDS1307/RealTimeClockDS1307.c ECU_layer/Servo_Motor/Servo_motor.c ECU_layer/seven_segment/ecu_seven_segment.c ECU_layer/TC74_TempSensor/TC74_TempSensor.c ECU_layer/ecu_initialize.c MCAL_layer/ADC/hal_ADC.c MCAL_layer/CCP/CCP1.c MCAL_layer/EEPROM/hal_eeprom.c MCAL_layer/GPIO/hal_gpio.c MCAL_layer/I2C/I2C.c MCAL_layer/Interrupt/mcal_external_Interrupt.c MCAL_layer/Interrupt/mcal_internal_Interrupt.c MCAL_layer/Interrupt/mcal_Interrupt_manger.c MCAL_layer/SPI/spi.c MCAL_layer/Timer0/Timer0.c MCAL_layer/Timer1/Timer1.c MCAL_layer/Timer2/Timer2.c MCAL_layer/Timer3/Timer3.c MCAL_layer/Uart/uart.c MCAL_layer/device_config.c MCAL_layer/Mcal_Initialize.c application.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/project.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F4620
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/ECU_layer/Char_lCD/ecu_chr_lcd.p1: ECU_layer/Char_lCD/ecu_chr_lcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/Char_lCD" 
	@${RM} ${OBJECTDIR}/ECU_layer/Char_lCD/ecu_chr_lcd.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/Char_lCD/ecu_chr_lcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/Char_lCD/ecu_chr_lcd.p1 ECU_layer/Char_lCD/ecu_chr_lcd.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/Char_lCD/ecu_chr_lcd.d ${OBJECTDIR}/ECU_layer/Char_lCD/ecu_chr_lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/Char_lCD/ecu_chr_lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/DC_Motor/ecu_Dc_motor.p1: ECU_layer/DC_Motor/ecu_Dc_motor.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/DC_Motor" 
	@${RM} ${OBJECTDIR}/ECU_layer/DC_Motor/ecu_Dc_motor.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/DC_Motor/ecu_Dc_motor.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/DC_Motor/ecu_Dc_motor.p1 ECU_layer/DC_Motor/ecu_Dc_motor.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/DC_Motor/ecu_Dc_motor.d ${OBJECTDIR}/ECU_layer/DC_Motor/ecu_Dc_motor.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/DC_Motor/ecu_Dc_motor.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/ecu_relay/ecu_relay.p1: ECU_layer/ecu_relay/ecu_relay.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/ecu_relay" 
	@${RM} ${OBJECTDIR}/ECU_layer/ecu_relay/ecu_relay.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/ecu_relay/ecu_relay.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/ecu_relay/ecu_relay.p1 ECU_layer/ecu_relay/ecu_relay.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/ecu_relay/ecu_relay.d ${OBJECTDIR}/ECU_layer/ecu_relay/ecu_relay.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/ecu_relay/ecu_relay.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/key_pad/ecu_key_pad.p1: ECU_layer/key_pad/ecu_key_pad.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/key_pad" 
	@${RM} ${OBJECTDIR}/ECU_layer/key_pad/ecu_key_pad.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/key_pad/ecu_key_pad.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/key_pad/ecu_key_pad.p1 ECU_layer/key_pad/ecu_key_pad.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/key_pad/ecu_key_pad.d ${OBJECTDIR}/ECU_layer/key_pad/ecu_key_pad.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/key_pad/ecu_key_pad.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/LED/ecu_led.p1: ECU_layer/LED/ecu_led.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/LED" 
	@${RM} ${OBJECTDIR}/ECU_layer/LED/ecu_led.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/LED/ecu_led.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/LED/ecu_led.p1 ECU_layer/LED/ecu_led.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/LED/ecu_led.d ${OBJECTDIR}/ECU_layer/LED/ecu_led.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/LED/ecu_led.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/Pir_sensor/Pir_sensor.p1: ECU_layer/Pir_sensor/Pir_sensor.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/Pir_sensor" 
	@${RM} ${OBJECTDIR}/ECU_layer/Pir_sensor/Pir_sensor.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/Pir_sensor/Pir_sensor.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/Pir_sensor/Pir_sensor.p1 ECU_layer/Pir_sensor/Pir_sensor.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/Pir_sensor/Pir_sensor.d ${OBJECTDIR}/ECU_layer/Pir_sensor/Pir_sensor.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/Pir_sensor/Pir_sensor.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/push_button/ecu_push_button.p1: ECU_layer/push_button/ecu_push_button.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/push_button" 
	@${RM} ${OBJECTDIR}/ECU_layer/push_button/ecu_push_button.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/push_button/ecu_push_button.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/push_button/ecu_push_button.p1 ECU_layer/push_button/ecu_push_button.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/push_button/ecu_push_button.d ${OBJECTDIR}/ECU_layer/push_button/ecu_push_button.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/push_button/ecu_push_button.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/RealTimeClockDS1307/RealTimeClockDS1307.p1: ECU_layer/RealTimeClockDS1307/RealTimeClockDS1307.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/RealTimeClockDS1307" 
	@${RM} ${OBJECTDIR}/ECU_layer/RealTimeClockDS1307/RealTimeClockDS1307.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/RealTimeClockDS1307/RealTimeClockDS1307.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/RealTimeClockDS1307/RealTimeClockDS1307.p1 ECU_layer/RealTimeClockDS1307/RealTimeClockDS1307.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/RealTimeClockDS1307/RealTimeClockDS1307.d ${OBJECTDIR}/ECU_layer/RealTimeClockDS1307/RealTimeClockDS1307.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/RealTimeClockDS1307/RealTimeClockDS1307.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/Servo_Motor/Servo_motor.p1: ECU_layer/Servo_Motor/Servo_motor.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/Servo_Motor" 
	@${RM} ${OBJECTDIR}/ECU_layer/Servo_Motor/Servo_motor.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/Servo_Motor/Servo_motor.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/Servo_Motor/Servo_motor.p1 ECU_layer/Servo_Motor/Servo_motor.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/Servo_Motor/Servo_motor.d ${OBJECTDIR}/ECU_layer/Servo_Motor/Servo_motor.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/Servo_Motor/Servo_motor.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/seven_segment/ecu_seven_segment.p1: ECU_layer/seven_segment/ecu_seven_segment.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/seven_segment" 
	@${RM} ${OBJECTDIR}/ECU_layer/seven_segment/ecu_seven_segment.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/seven_segment/ecu_seven_segment.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/seven_segment/ecu_seven_segment.p1 ECU_layer/seven_segment/ecu_seven_segment.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/seven_segment/ecu_seven_segment.d ${OBJECTDIR}/ECU_layer/seven_segment/ecu_seven_segment.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/seven_segment/ecu_seven_segment.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/TC74_TempSensor/TC74_TempSensor.p1: ECU_layer/TC74_TempSensor/TC74_TempSensor.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/TC74_TempSensor" 
	@${RM} ${OBJECTDIR}/ECU_layer/TC74_TempSensor/TC74_TempSensor.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/TC74_TempSensor/TC74_TempSensor.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/TC74_TempSensor/TC74_TempSensor.p1 ECU_layer/TC74_TempSensor/TC74_TempSensor.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/TC74_TempSensor/TC74_TempSensor.d ${OBJECTDIR}/ECU_layer/TC74_TempSensor/TC74_TempSensor.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/TC74_TempSensor/TC74_TempSensor.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/ecu_initialize.p1: ECU_layer/ecu_initialize.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer" 
	@${RM} ${OBJECTDIR}/ECU_layer/ecu_initialize.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/ecu_initialize.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/ecu_initialize.p1 ECU_layer/ecu_initialize.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/ecu_initialize.d ${OBJECTDIR}/ECU_layer/ecu_initialize.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/ecu_initialize.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/ADC/hal_ADC.p1: MCAL_layer/ADC/hal_ADC.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/ADC" 
	@${RM} ${OBJECTDIR}/MCAL_layer/ADC/hal_ADC.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/ADC/hal_ADC.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/ADC/hal_ADC.p1 MCAL_layer/ADC/hal_ADC.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/ADC/hal_ADC.d ${OBJECTDIR}/MCAL_layer/ADC/hal_ADC.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/ADC/hal_ADC.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/CCP/CCP1.p1: MCAL_layer/CCP/CCP1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/CCP" 
	@${RM} ${OBJECTDIR}/MCAL_layer/CCP/CCP1.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/CCP/CCP1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/CCP/CCP1.p1 MCAL_layer/CCP/CCP1.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/CCP/CCP1.d ${OBJECTDIR}/MCAL_layer/CCP/CCP1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/CCP/CCP1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/EEPROM/hal_eeprom.p1: MCAL_layer/EEPROM/hal_eeprom.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/EEPROM" 
	@${RM} ${OBJECTDIR}/MCAL_layer/EEPROM/hal_eeprom.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/EEPROM/hal_eeprom.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/EEPROM/hal_eeprom.p1 MCAL_layer/EEPROM/hal_eeprom.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/EEPROM/hal_eeprom.d ${OBJECTDIR}/MCAL_layer/EEPROM/hal_eeprom.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/EEPROM/hal_eeprom.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/GPIO/hal_gpio.p1: MCAL_layer/GPIO/hal_gpio.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL_layer/GPIO/hal_gpio.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/GPIO/hal_gpio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/GPIO/hal_gpio.p1 MCAL_layer/GPIO/hal_gpio.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/GPIO/hal_gpio.d ${OBJECTDIR}/MCAL_layer/GPIO/hal_gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/GPIO/hal_gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/I2C/I2C.p1: MCAL_layer/I2C/I2C.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/I2C" 
	@${RM} ${OBJECTDIR}/MCAL_layer/I2C/I2C.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/I2C/I2C.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/I2C/I2C.p1 MCAL_layer/I2C/I2C.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/I2C/I2C.d ${OBJECTDIR}/MCAL_layer/I2C/I2C.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/I2C/I2C.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/Interrupt/mcal_external_Interrupt.p1: MCAL_layer/Interrupt/mcal_external_Interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_external_Interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_external_Interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_external_Interrupt.p1 MCAL_layer/Interrupt/mcal_external_Interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_external_Interrupt.d ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_external_Interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_external_Interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/Interrupt/mcal_internal_Interrupt.p1: MCAL_layer/Interrupt/mcal_internal_Interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_internal_Interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_internal_Interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_internal_Interrupt.p1 MCAL_layer/Interrupt/mcal_internal_Interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_internal_Interrupt.d ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_internal_Interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_internal_Interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/Interrupt/mcal_Interrupt_manger.p1: MCAL_layer/Interrupt/mcal_Interrupt_manger.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_Interrupt_manger.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_Interrupt_manger.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_Interrupt_manger.p1 MCAL_layer/Interrupt/mcal_Interrupt_manger.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_Interrupt_manger.d ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_Interrupt_manger.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_Interrupt_manger.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/SPI/spi.p1: MCAL_layer/SPI/spi.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/SPI" 
	@${RM} ${OBJECTDIR}/MCAL_layer/SPI/spi.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/SPI/spi.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/SPI/spi.p1 MCAL_layer/SPI/spi.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/SPI/spi.d ${OBJECTDIR}/MCAL_layer/SPI/spi.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/SPI/spi.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/Timer0/Timer0.p1: MCAL_layer/Timer0/Timer0.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/Timer0" 
	@${RM} ${OBJECTDIR}/MCAL_layer/Timer0/Timer0.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/Timer0/Timer0.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/Timer0/Timer0.p1 MCAL_layer/Timer0/Timer0.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/Timer0/Timer0.d ${OBJECTDIR}/MCAL_layer/Timer0/Timer0.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/Timer0/Timer0.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/Timer1/Timer1.p1: MCAL_layer/Timer1/Timer1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/Timer1" 
	@${RM} ${OBJECTDIR}/MCAL_layer/Timer1/Timer1.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/Timer1/Timer1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/Timer1/Timer1.p1 MCAL_layer/Timer1/Timer1.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/Timer1/Timer1.d ${OBJECTDIR}/MCAL_layer/Timer1/Timer1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/Timer1/Timer1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/Timer2/Timer2.p1: MCAL_layer/Timer2/Timer2.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/Timer2" 
	@${RM} ${OBJECTDIR}/MCAL_layer/Timer2/Timer2.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/Timer2/Timer2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/Timer2/Timer2.p1 MCAL_layer/Timer2/Timer2.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/Timer2/Timer2.d ${OBJECTDIR}/MCAL_layer/Timer2/Timer2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/Timer2/Timer2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/Timer3/Timer3.p1: MCAL_layer/Timer3/Timer3.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/Timer3" 
	@${RM} ${OBJECTDIR}/MCAL_layer/Timer3/Timer3.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/Timer3/Timer3.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/Timer3/Timer3.p1 MCAL_layer/Timer3/Timer3.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/Timer3/Timer3.d ${OBJECTDIR}/MCAL_layer/Timer3/Timer3.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/Timer3/Timer3.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/Uart/uart.p1: MCAL_layer/Uart/uart.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/Uart" 
	@${RM} ${OBJECTDIR}/MCAL_layer/Uart/uart.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/Uart/uart.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/Uart/uart.p1 MCAL_layer/Uart/uart.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/Uart/uart.d ${OBJECTDIR}/MCAL_layer/Uart/uart.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/Uart/uart.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/device_config.p1: MCAL_layer/device_config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer" 
	@${RM} ${OBJECTDIR}/MCAL_layer/device_config.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/device_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/device_config.p1 MCAL_layer/device_config.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/device_config.d ${OBJECTDIR}/MCAL_layer/device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/Mcal_Initialize.p1: MCAL_layer/Mcal_Initialize.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer" 
	@${RM} ${OBJECTDIR}/MCAL_layer/Mcal_Initialize.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/Mcal_Initialize.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/Mcal_Initialize.p1 MCAL_layer/Mcal_Initialize.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/Mcal_Initialize.d ${OBJECTDIR}/MCAL_layer/Mcal_Initialize.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/Mcal_Initialize.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/application.p1: application.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/application.p1.d 
	@${RM} ${OBJECTDIR}/application.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/application.p1 application.c 
	@-${MV} ${OBJECTDIR}/application.d ${OBJECTDIR}/application.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/application.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/ECU_layer/Char_lCD/ecu_chr_lcd.p1: ECU_layer/Char_lCD/ecu_chr_lcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/Char_lCD" 
	@${RM} ${OBJECTDIR}/ECU_layer/Char_lCD/ecu_chr_lcd.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/Char_lCD/ecu_chr_lcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/Char_lCD/ecu_chr_lcd.p1 ECU_layer/Char_lCD/ecu_chr_lcd.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/Char_lCD/ecu_chr_lcd.d ${OBJECTDIR}/ECU_layer/Char_lCD/ecu_chr_lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/Char_lCD/ecu_chr_lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/DC_Motor/ecu_Dc_motor.p1: ECU_layer/DC_Motor/ecu_Dc_motor.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/DC_Motor" 
	@${RM} ${OBJECTDIR}/ECU_layer/DC_Motor/ecu_Dc_motor.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/DC_Motor/ecu_Dc_motor.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/DC_Motor/ecu_Dc_motor.p1 ECU_layer/DC_Motor/ecu_Dc_motor.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/DC_Motor/ecu_Dc_motor.d ${OBJECTDIR}/ECU_layer/DC_Motor/ecu_Dc_motor.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/DC_Motor/ecu_Dc_motor.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/ecu_relay/ecu_relay.p1: ECU_layer/ecu_relay/ecu_relay.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/ecu_relay" 
	@${RM} ${OBJECTDIR}/ECU_layer/ecu_relay/ecu_relay.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/ecu_relay/ecu_relay.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/ecu_relay/ecu_relay.p1 ECU_layer/ecu_relay/ecu_relay.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/ecu_relay/ecu_relay.d ${OBJECTDIR}/ECU_layer/ecu_relay/ecu_relay.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/ecu_relay/ecu_relay.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/key_pad/ecu_key_pad.p1: ECU_layer/key_pad/ecu_key_pad.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/key_pad" 
	@${RM} ${OBJECTDIR}/ECU_layer/key_pad/ecu_key_pad.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/key_pad/ecu_key_pad.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/key_pad/ecu_key_pad.p1 ECU_layer/key_pad/ecu_key_pad.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/key_pad/ecu_key_pad.d ${OBJECTDIR}/ECU_layer/key_pad/ecu_key_pad.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/key_pad/ecu_key_pad.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/LED/ecu_led.p1: ECU_layer/LED/ecu_led.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/LED" 
	@${RM} ${OBJECTDIR}/ECU_layer/LED/ecu_led.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/LED/ecu_led.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/LED/ecu_led.p1 ECU_layer/LED/ecu_led.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/LED/ecu_led.d ${OBJECTDIR}/ECU_layer/LED/ecu_led.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/LED/ecu_led.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/Pir_sensor/Pir_sensor.p1: ECU_layer/Pir_sensor/Pir_sensor.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/Pir_sensor" 
	@${RM} ${OBJECTDIR}/ECU_layer/Pir_sensor/Pir_sensor.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/Pir_sensor/Pir_sensor.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/Pir_sensor/Pir_sensor.p1 ECU_layer/Pir_sensor/Pir_sensor.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/Pir_sensor/Pir_sensor.d ${OBJECTDIR}/ECU_layer/Pir_sensor/Pir_sensor.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/Pir_sensor/Pir_sensor.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/push_button/ecu_push_button.p1: ECU_layer/push_button/ecu_push_button.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/push_button" 
	@${RM} ${OBJECTDIR}/ECU_layer/push_button/ecu_push_button.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/push_button/ecu_push_button.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/push_button/ecu_push_button.p1 ECU_layer/push_button/ecu_push_button.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/push_button/ecu_push_button.d ${OBJECTDIR}/ECU_layer/push_button/ecu_push_button.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/push_button/ecu_push_button.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/RealTimeClockDS1307/RealTimeClockDS1307.p1: ECU_layer/RealTimeClockDS1307/RealTimeClockDS1307.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/RealTimeClockDS1307" 
	@${RM} ${OBJECTDIR}/ECU_layer/RealTimeClockDS1307/RealTimeClockDS1307.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/RealTimeClockDS1307/RealTimeClockDS1307.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/RealTimeClockDS1307/RealTimeClockDS1307.p1 ECU_layer/RealTimeClockDS1307/RealTimeClockDS1307.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/RealTimeClockDS1307/RealTimeClockDS1307.d ${OBJECTDIR}/ECU_layer/RealTimeClockDS1307/RealTimeClockDS1307.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/RealTimeClockDS1307/RealTimeClockDS1307.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/Servo_Motor/Servo_motor.p1: ECU_layer/Servo_Motor/Servo_motor.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/Servo_Motor" 
	@${RM} ${OBJECTDIR}/ECU_layer/Servo_Motor/Servo_motor.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/Servo_Motor/Servo_motor.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/Servo_Motor/Servo_motor.p1 ECU_layer/Servo_Motor/Servo_motor.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/Servo_Motor/Servo_motor.d ${OBJECTDIR}/ECU_layer/Servo_Motor/Servo_motor.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/Servo_Motor/Servo_motor.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/seven_segment/ecu_seven_segment.p1: ECU_layer/seven_segment/ecu_seven_segment.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/seven_segment" 
	@${RM} ${OBJECTDIR}/ECU_layer/seven_segment/ecu_seven_segment.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/seven_segment/ecu_seven_segment.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/seven_segment/ecu_seven_segment.p1 ECU_layer/seven_segment/ecu_seven_segment.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/seven_segment/ecu_seven_segment.d ${OBJECTDIR}/ECU_layer/seven_segment/ecu_seven_segment.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/seven_segment/ecu_seven_segment.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/TC74_TempSensor/TC74_TempSensor.p1: ECU_layer/TC74_TempSensor/TC74_TempSensor.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/TC74_TempSensor" 
	@${RM} ${OBJECTDIR}/ECU_layer/TC74_TempSensor/TC74_TempSensor.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/TC74_TempSensor/TC74_TempSensor.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/TC74_TempSensor/TC74_TempSensor.p1 ECU_layer/TC74_TempSensor/TC74_TempSensor.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/TC74_TempSensor/TC74_TempSensor.d ${OBJECTDIR}/ECU_layer/TC74_TempSensor/TC74_TempSensor.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/TC74_TempSensor/TC74_TempSensor.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/ecu_initialize.p1: ECU_layer/ecu_initialize.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer" 
	@${RM} ${OBJECTDIR}/ECU_layer/ecu_initialize.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/ecu_initialize.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/ecu_initialize.p1 ECU_layer/ecu_initialize.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/ecu_initialize.d ${OBJECTDIR}/ECU_layer/ecu_initialize.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/ecu_initialize.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/ADC/hal_ADC.p1: MCAL_layer/ADC/hal_ADC.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/ADC" 
	@${RM} ${OBJECTDIR}/MCAL_layer/ADC/hal_ADC.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/ADC/hal_ADC.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/ADC/hal_ADC.p1 MCAL_layer/ADC/hal_ADC.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/ADC/hal_ADC.d ${OBJECTDIR}/MCAL_layer/ADC/hal_ADC.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/ADC/hal_ADC.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/CCP/CCP1.p1: MCAL_layer/CCP/CCP1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/CCP" 
	@${RM} ${OBJECTDIR}/MCAL_layer/CCP/CCP1.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/CCP/CCP1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/CCP/CCP1.p1 MCAL_layer/CCP/CCP1.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/CCP/CCP1.d ${OBJECTDIR}/MCAL_layer/CCP/CCP1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/CCP/CCP1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/EEPROM/hal_eeprom.p1: MCAL_layer/EEPROM/hal_eeprom.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/EEPROM" 
	@${RM} ${OBJECTDIR}/MCAL_layer/EEPROM/hal_eeprom.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/EEPROM/hal_eeprom.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/EEPROM/hal_eeprom.p1 MCAL_layer/EEPROM/hal_eeprom.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/EEPROM/hal_eeprom.d ${OBJECTDIR}/MCAL_layer/EEPROM/hal_eeprom.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/EEPROM/hal_eeprom.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/GPIO/hal_gpio.p1: MCAL_layer/GPIO/hal_gpio.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL_layer/GPIO/hal_gpio.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/GPIO/hal_gpio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/GPIO/hal_gpio.p1 MCAL_layer/GPIO/hal_gpio.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/GPIO/hal_gpio.d ${OBJECTDIR}/MCAL_layer/GPIO/hal_gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/GPIO/hal_gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/I2C/I2C.p1: MCAL_layer/I2C/I2C.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/I2C" 
	@${RM} ${OBJECTDIR}/MCAL_layer/I2C/I2C.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/I2C/I2C.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/I2C/I2C.p1 MCAL_layer/I2C/I2C.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/I2C/I2C.d ${OBJECTDIR}/MCAL_layer/I2C/I2C.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/I2C/I2C.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/Interrupt/mcal_external_Interrupt.p1: MCAL_layer/Interrupt/mcal_external_Interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_external_Interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_external_Interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_external_Interrupt.p1 MCAL_layer/Interrupt/mcal_external_Interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_external_Interrupt.d ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_external_Interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_external_Interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/Interrupt/mcal_internal_Interrupt.p1: MCAL_layer/Interrupt/mcal_internal_Interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_internal_Interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_internal_Interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_internal_Interrupt.p1 MCAL_layer/Interrupt/mcal_internal_Interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_internal_Interrupt.d ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_internal_Interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_internal_Interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/Interrupt/mcal_Interrupt_manger.p1: MCAL_layer/Interrupt/mcal_Interrupt_manger.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_Interrupt_manger.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_Interrupt_manger.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_Interrupt_manger.p1 MCAL_layer/Interrupt/mcal_Interrupt_manger.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_Interrupt_manger.d ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_Interrupt_manger.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_Interrupt_manger.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/SPI/spi.p1: MCAL_layer/SPI/spi.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/SPI" 
	@${RM} ${OBJECTDIR}/MCAL_layer/SPI/spi.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/SPI/spi.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/SPI/spi.p1 MCAL_layer/SPI/spi.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/SPI/spi.d ${OBJECTDIR}/MCAL_layer/SPI/spi.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/SPI/spi.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/Timer0/Timer0.p1: MCAL_layer/Timer0/Timer0.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/Timer0" 
	@${RM} ${OBJECTDIR}/MCAL_layer/Timer0/Timer0.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/Timer0/Timer0.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/Timer0/Timer0.p1 MCAL_layer/Timer0/Timer0.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/Timer0/Timer0.d ${OBJECTDIR}/MCAL_layer/Timer0/Timer0.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/Timer0/Timer0.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/Timer1/Timer1.p1: MCAL_layer/Timer1/Timer1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/Timer1" 
	@${RM} ${OBJECTDIR}/MCAL_layer/Timer1/Timer1.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/Timer1/Timer1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/Timer1/Timer1.p1 MCAL_layer/Timer1/Timer1.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/Timer1/Timer1.d ${OBJECTDIR}/MCAL_layer/Timer1/Timer1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/Timer1/Timer1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/Timer2/Timer2.p1: MCAL_layer/Timer2/Timer2.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/Timer2" 
	@${RM} ${OBJECTDIR}/MCAL_layer/Timer2/Timer2.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/Timer2/Timer2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/Timer2/Timer2.p1 MCAL_layer/Timer2/Timer2.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/Timer2/Timer2.d ${OBJECTDIR}/MCAL_layer/Timer2/Timer2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/Timer2/Timer2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/Timer3/Timer3.p1: MCAL_layer/Timer3/Timer3.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/Timer3" 
	@${RM} ${OBJECTDIR}/MCAL_layer/Timer3/Timer3.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/Timer3/Timer3.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/Timer3/Timer3.p1 MCAL_layer/Timer3/Timer3.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/Timer3/Timer3.d ${OBJECTDIR}/MCAL_layer/Timer3/Timer3.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/Timer3/Timer3.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/Uart/uart.p1: MCAL_layer/Uart/uart.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/Uart" 
	@${RM} ${OBJECTDIR}/MCAL_layer/Uart/uart.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/Uart/uart.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/Uart/uart.p1 MCAL_layer/Uart/uart.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/Uart/uart.d ${OBJECTDIR}/MCAL_layer/Uart/uart.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/Uart/uart.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/device_config.p1: MCAL_layer/device_config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer" 
	@${RM} ${OBJECTDIR}/MCAL_layer/device_config.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/device_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/device_config.p1 MCAL_layer/device_config.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/device_config.d ${OBJECTDIR}/MCAL_layer/device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/Mcal_Initialize.p1: MCAL_layer/Mcal_Initialize.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer" 
	@${RM} ${OBJECTDIR}/MCAL_layer/Mcal_Initialize.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/Mcal_Initialize.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/Mcal_Initialize.p1 MCAL_layer/Mcal_Initialize.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/Mcal_Initialize.d ${OBJECTDIR}/MCAL_layer/Mcal_Initialize.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/Mcal_Initialize.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/application.p1: application.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/application.p1.d 
	@${RM} ${OBJECTDIR}/application.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/application.p1 application.c 
	@-${MV} ${OBJECTDIR}/application.d ${OBJECTDIR}/application.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/application.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/project.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/project.X.${IMAGE_TYPE}.map  -D__DEBUG=1  -mdebugger=none  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto        $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/project.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} ${DISTDIR}/project.X.${IMAGE_TYPE}.hex 
	
else
${DISTDIR}/project.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/project.X.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/project.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
