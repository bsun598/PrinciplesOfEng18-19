#pragma config(Sensor, dgtl1,  bump1,          sensorTouch)
#pragma config(Sensor, dgtl2,  bump2,          sensorTouch)
#pragma config(Sensor, dgtl3,  bump3,          sensorTouch)
#pragma config(Sensor, dgtl4,  ultrasonic,     sensorSONAR_cm)
#pragma config(Sensor, dgtl9,  greenLED,       sensorLEDtoVCC)
#pragma config(Sensor, dgtl10, yellowLED,      sensorLEDtoVCC)
#pragma config(Sensor, dgtl11, redLED,         sensorLEDtoVCC)
#pragma config(Motor,  port2,           motor1,        tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
//*Purpose: Program an elevator that can move between 3 floors in any combination, with a *//
//*         safety mechanism that returns the elevator to ground floor after 5 seconds.   *//

task main()
{
	while(SensorValue(ultrasonic) < 27) // (lower value = higher height) while elevator is above ground
	{
		startMotor(motor1, 15); // turn motor until elevator is @ ground floor
	}
	stopMotor(motor1); // stop motor
	while (1==1) // infinite loop
	{
		if (SensorValue(bump1) == 1) // if floor 1 button pressed
		{
			turnLEDOff(yellowLED);
			turnLEDOff(redLED);
			while(SensorValue(ultrasonic) < 27)
			{
				startMotor(motor1, 10); // return to ground floor
			}
			stopMotor(motor1);
			turnLEDOn(greenLED); // turn on green LED (indicating floor 1)
		}
		if (SensorValue(bump2) == 1) // if floor 2 button pressed
		{
			clearTimer(T1); // start timer for automatic floor return
			turnLEDOff(greenLED); // turn LEDs off for other floors
			turnLEDOff(redLED);
			while (SensorValue(ultrasonic) > 19) // if current floor below floor 2, motor goes up
			{
				startMotor(motor1, -17);
			}
			while (SensorValue(ultrasonic) < 17) // if current floor above floor 2, motor goes down
			{
				startMotor(motor1, 10);
			}
			stopMotor(motor1);
			turnLEDOn(yellowLED); // turn on LED for 2nd floor
		}
		if (SensorValue(bump3) == 1) // if floor 3 button pressed
		{
			clearTimer(T1); // start timer for automatic floor return
			turnLEDOff(greenLED); // turn LEDs off for other floors
			turnLEDOff(yellowLED);
			while (SensorValue(ultrasonic) > 5) // if current floor below floor 3, motor goes up
			{
				startMotor(motor1, -17);
			}
			turnLEDOn(redLED); // turn on LEd for 3rd floor
			stopMotor(motor1);
		}
		if (time1[T1] >= 6000) // once 6 seconds have elapsed, begin automatic floor return
		{
			clearTimer(T1); // clear timer
			turnLEDOff(greenLED); // turn off LEDs for all floors
			turnLEDOff(yellowLED);
			turnLEDOff(redLED);
			while (SensorValue(ultrasonic) < 27) // motor goes down until ground floor reached
			{
				startMotor(motor1, 10);
			}
			stopMotor(motor1);
			turnLEDOn(greenLED); // turn on LED for ground floor
		}
	}
}
