#pragma config(UART_Usage, UART1, uartVEXLCD, baudRate19200, IOPins, None, None)
#pragma config(UART_Usage, UART2, uartNotUsed, baudRate4800, IOPins, None, None)
#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    potLeft,        sensorPotentiometer)
#pragma config(Sensor, in2,    potRight,       sensorPotentiometer)
#pragma config(Sensor, I2C_1,  nEncoderLeft,   sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_2,  nEncoderRight,  sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Motor,  port1,           intakeMotorRight, tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           topRightArm,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           bottomRightArm, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           topLeftArm,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           bottomLeftArm, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           frontRight,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           backRight,     tmotorVex393_MC29, openLoop, reversed, encoderPort, I2C_1)
#pragma config(Motor,  port8,           backLeft,      tmotorVex393_MC29, openLoop, encoderPort, I2C_2)
#pragma config(Motor,  port9,           frontLeft,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          intakeMotorLeft, tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main(){
	//LCD DISPLAY CODE
	bLCDBacklight = true;
	//clear top line
	clearLCDLine(0);
	//clear bottom line
	clearLCDLine(1);
	//set lcd positon to top right
	displayLCDPos(0,0);
	//print
	displayNextLCDString("Pot1: ");
	//set to bottem left
	displayLCDPos(1,0);
	//print
	displayNextLCDString("Pot2: ");
	//displays potentiometer value
	displayNextLCDNumber(SensorValue(potLeft));
	//displays encoder value
	//displayNextLCDNumber(nMotorEncoder(backRight));
	//sets position
	displayLCDPos(0,6);
	//displays sensor value
	displayNextLCDNumber(SensorValue(potRight));
	//displays encoder value
	//displayNextLCDNumber(nMotorEncoder(backLeft));


	//MOVEMENT CODE

	//resets motor encoders
	nMotorEncoder[backLeft] = 0;
	nMotorEncoder[backRight] = 0;
	//go forward till encoder hits
	while(abs(nMotorEncoder[backRight]) < 600 && abs(nMotorEncoder[backLeft]) < 600){
		motor[backLeft] = 127;
		motor[backRight] = 127;
		motor[frontLeft] = 127;
		motor[frontRight] = 127;
	}
	wait1Msec(100);
	//stops robot
	motor[backLeft] = 0;
	motor[backRight] = 0;
	motor[frontLeft] = 0;
	motor[frontRight] = 0;
	//picks up cube
	motor[intakeMotorLeft] = 127;
	motor[intakeMotorRight] = 127;
	wait1Msec(900);
	motor[intakeMotorLeft] = 0;
	motor[intakeMotorRight] = 0;
	nMotorEncoder[backLeft] = 0;
	nMotorEncoder[backRight] = 0;
	//turns left toward pole
	while(abs(nMotorEncoder[backLeft]) < 100 && abs(nMotorEncoder[backRight]) < 100){
		motor[backLeft] =   -100;
		motor[backRight] =  100;
		motor[frontLeft] =  -100;
		motor[frontRight] = 100;
	}
	wait1Msec(100);
	//stops robot
	motor[backLeft] = 0;
	motor[backRight] = 0;
	motor[frontLeft] = 0;
	motor[frontRight] = 0;
	nMotorEncoder[backLeft] = 0;
	nMotorEncoder[backRight] = 0;

	//moves arm up till medium pole height
	while(SensorValue[potLeft] > 1960 || SensorValue[potRight] > 1813){
		motor[topRightArm] = -127;
		motor[bottomLeftArm] = -127;
		motor[topLeftArm] = -127;
		motor[bottomRightArm] = -127;
}
//stops robot
	motor[topRightArm] =  0;
	motor[bottomLeftArm] = 0;
	motor[topLeftArm] =  0;
	motor[bottomRightArm] =  0;
	//resets motor encoders
	nMotorEncoder[backLeft] = 0;
	nMotorEncoder[backRight] = 0;

	//go forward toward pole
	while(abs(nMotorEncoder[backRight]) < 70 && abs(nMotorEncoder[backLeft]) < 70){
		motor[backLeft] = 127;
		motor[backRight] = 127;
		motor[frontLeft] = 127;
		motor[frontRight] = 127;
	}
	wait1Msec(100);
	//stops robot
	motor[backLeft] = 0;
	motor[backRight] = 0;
	motor[frontLeft] = 0;
	motor[frontRight] = 0;

	//drops off cube
	motor[intakeMotorLeft] = -127;
	motor[intakeMotorRight] = -127;
	wait1Msec(1600);
	// stops intake
	motor[intakeMotorLeft] = 0;
	motor[intakeMotorRight] = 0;

}
