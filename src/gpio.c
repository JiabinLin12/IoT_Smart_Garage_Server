/*
  gpio.c
 
   Created on: Dec 12, 2018
       Author: Dan Walkes
   Updated by Dave Sluiter Dec 31, 2020. Minor edits with #defines.

   March 17
   Dave Sluiter: Use this file to define functions that set up or control GPIOs.

 */




#include "gpio.h"





// Set GPIO drive strengths and modes of operation
void gpioInit()
{

	GPIO_DriveStrengthSet(LED0_port, gpioDriveStrengthStrongAlternateStrong);
	//GPIO_DriveStrengthSet(LED0_port, gpioDriveStrengthWeakAlternateWeak);
	GPIO_PinModeSet(LED0_port, LED0_pin, gpioModePushPull, false);

	GPIO_DriveStrengthSet(LED1_port, gpioDriveStrengthStrongAlternateStrong);
	//GPIO_DriveStrengthSet(LED1_port, gpioDriveStrengthWeakAlternateWeak);
	GPIO_PinModeSet(LED1_port, LED1_pin, gpioModePushPull, false);

  //PB0
  GPIO_PinModeSet(PB0_PORT, PB0_PIN, gpioModeInputPullFilter, true);
  GPIO_ExtIntConfig(PB0_PORT,PB0_PIN,PB0_PIN,true,true,true);

  //Break Beam
  GPIO_PinModeSet(BREAK_BEAM_PORT, BREAK_BEAM_PIN, gpioModeInputPullFilter, true);
  NVIC_EnableIRQ(GPIO_EVEN_IRQn);
  GPIO_ExtIntConfig(BREAK_BEAM_PORT,BREAK_BEAM_PIN,BREAK_BEAM_PIN,false,true,true);

} // gpioInit()


void gpioLed0SetOn()
{
	GPIO_PinOutSet(LED0_port,LED0_pin);
}


void gpioLed0SetOff()
{
	GPIO_PinOutClear(LED0_port,LED0_pin);
}


void gpioLed1SetOn()
{
	GPIO_PinOutSet(LED1_port,LED1_pin);
}


void gpioLed1SetOff()
{
	GPIO_PinOutClear(LED1_port,LED1_pin);
}

/**
 * Enable SENSOR_ENABLE PIN for si7021 in the schematic
 * to enable the sensor
 * */
void si7021_enable(){
  GPIO_PinOutSet(SI7021_PORT,SI7021_PIN);
}
/**
 * Disable SENSOR_ENABLE PIN for si7021 in the schematic
 * to disable the sensor
 * */
void si7021_disable(){
  GPIO_PinOutClear(SI7021_PORT,SI7021_PIN);
}

void gpioSensorEnSetOn(){
  GPIO_PinOutSet(DISP_PORT,DISP_PIN);
}

void gpioSetDisplayExtcomin(bool status){
  if(status){
    GPIO_PinOutSet(DISP_PORT,DISP_PIN);
  }else{
    GPIO_PinOutClear(DISP_PORT,DISP_PIN);
  }
}

void light_sensor_enable(){
  GPIO_PinOutSet(LIGHT_SENSOR_POWER_PORT,LIGHT_SENSOR_POWER_PIN);
}

void light_sensor_disable(){
  GPIO_PinOutSet(LIGHT_SENSOR_POWER_PORT,LIGHT_SENSOR_POWER_PIN);
}


void ToggleLED0 () {
  static bool  state=false;

  if (state) {
      state = false;
      gpioLed0SetOff();
  } else {
      state = true;
      gpioLed0SetOn();
  }
}



