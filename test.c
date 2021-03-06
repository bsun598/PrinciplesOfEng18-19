#pragma config(Sensor, in1,    follower1,      sensorLineFollower)
#pragma config(Sensor, dgtl2,  ,               sensorSONAR_mm)
#pragma config(Motor,  port1,           flashlight1,   tmotorVexFlashlight, openLoop, reversed)
#pragma config(Motor,  port2,           servo1,        tmotorServoStandard, openLoop)
#pragma config(Motor,  port8,           motor1,        tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	while(1==1)
	{
		startMotor(motor1, -127);
		setServo(servo1, 0);
		turnFlashlightOn(flashlight1, -127);
		if (SensorValue(follower1) < 1850)
		{
			setServo(servo1, -90);
			wait(1);
		}
		else
		{
			wait(0.2);
			setServo(servo1, 0);
		}
	}
}
