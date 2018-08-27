#pragma config(Sensor, S2,     light,          sensorLightActive)
#pragma config(Sensor, S3,     color,          sensorColorNxtFULL)
#pragma config(Motor,  motorB,          LM,            tmotorNXT, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          RM,            tmotorNXT, PIDControl, driveRight, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{

	int red = 0;
	int green = 0;
	int blue = 0;
	int yellow = 0;


	float cost = 0;
	int blackcounter = 0;
	while(true){



		if(SensorValue[color] == 6){ // white

			motor[LM] = 25;
			motor[RM] = 0;
			eraseDisplay();

			}else { // other colors
			// turn left
			motor[LM] = 0;
			motor[RM] = 25;

			if(SensorValue[color] == 1){ // black

				displayTextLine(6, "S.V: %d ", SensorValue[color]);
				displayTextLine(7, "Black #: %d", blackcounter);
				++blackcounter;
				if(blackcounter > 7){
					break;
					}else{
					motor[LM] = 30;
					motor[RM] = 30;
					wait1Msec(500);
				}

				}else if(SensorValue[color] == 5){ // red
				++red;
				if(red == 1){
						cost = cost + (.75);
				}
				displayBigTextLine(4, "Bakery");
				//wait1Msec(2000);

				}else if(SensorValue[color] == 3){ // green
				++green;
				if(green == 1){
					cost = cost + 1.25;
				}
				displayBigTextLine(4, "Candy");
				//wait1Msec(2000);

				}else if(SensorValue[color] == 4){ // yellow
				++yellow;
				if(yellow == 1){
					cost = cost + 1;
				}
				displayBigTextLine(4, "Ferris Wheel");
				//wait1Msec(2000);
				}else if(SensorValue[color] == 2){ // blue
				++blue;
				if(blue == 1){
					cost = cost + 0.50;
				}
				displayBigTextLine(4, "Forest");
				//wait1Msec(2000);
			}

		}
	}

	eraseDisplay();
	// stop motors
	motor[LM] = 0;
	motor[RM] = 0;
	displayBigTextLine(4, "Home");
	displayBigTextLine(5, "$: %.2f",cost);
	wait1Msec(2000);

}
