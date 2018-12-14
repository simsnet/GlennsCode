#pragma config(Sensor, dgtl1,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  rightEncoder,   sensorQuadEncoder)
#pragma config(Motor,  port1,           leftMotor,     tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port6,           clawMotor,     tmotorVex269_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           armMotor,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          rightMotor,    tmotorVex393_HBridge, openLoop)

task main ()
{
	while(1 == 1)
	{
		//Driving Motor Control
		motor[leftMotor] = vexRT[Ch3] / 2;
		motor[rightMotor] = vexRT[Ch2] / 2;

		// Raise, lower or do not move arm
		if(vexRT[Btn5U] == 1)       	//If button 5U is pressed...
		{
			motor[armMotor] = -127;    	//...raise the arm.
		}
		else if(vexRT[Btn5D] == 1)  	//Else, if button 5D is pressed...
		{
			motor[armMotor] = 127;   	//...lower the arm.
		}
		else                      		//Else (neither button is pressed)...
		{
			motor[armMotor] = 0;      	//...stop the arm.
		}

		// Open, close or do not more claw
		if(vexRT[Btn6U] == 1)       	//If Button 6U is pressed...
		{
			motor[clawMotor] = -127;  		//...close the gripper.
		}
		else if(vexRT[Btn6D] == 1)  	//Else, if button 6D is pressed...
		{
			motor[clawMotor] = 127; 		//...open the gripper.
		}
		else                      		//Else (neither button is pressed)...
		{
			motor[clawMotor] = 0;    		//...stop the gripper.
		}
	}
}
