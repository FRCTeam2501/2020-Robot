#include <math.h>
#pragma once


namespace CONSTANTS
{
	//Cycles for the code to run per second
	const int CYCLES = 100;
	//Period of a cycle of the robot code
	const double PERIOD = 1.0 / CYCLES;
	//Number of cycles to run before SmartDashboard is refreshed
	const double SHUFFLEBOARD_TIME = 5.0;
	//Time to eject game piece before it retracts
	const float MANIP_EXTEND_TIME = 0.8;
	//Time to lower manipulator to ground 
	const float MANIP_ACTUATOR_TIME = 0.7;

	//Used for the BoostSequence function:
	const float BOOSTDRIVE_SPEED = 0.7;
	
	const float BOOST_DRIVE_TIME_0 = 0.5,
				BOOST_DRIVE_TIME_1 = 0.5,
				BOOST_DRIVE_TIME_2 = 0.8;

	const double ROTATE_SPEED = 0.5;    //Rotation speed as a function of drive speed

	namespace EL
	{
		const float MIN = 19.5;//Min height (Inches)
		const float MAX = 80.0;//Max height(Inches)

		//Elevator manual lifting setpoint variables
		const double TIMETOTOP = 1.75;
		const double INPERSEC = (MAX - MIN) / TIMETOTOP;
		const double INPERCYCLE = INPERSEC * PERIOD;

		//Elevator PID values
		const float kP = 0.3;
		const float kI = 0.2;
		const float kD = 0.2;
		const float kF = 0.5;

		const float RADIUS = 1.317;    //Radius of gear or shaft (Inches)
		const float RATIO= 22 / 48; 	//Small sprocket to big sprocket
		const float RESOLUTION = 2048;  //Pulses per revolution of encoder
		const float ADJUST = 1.0;       //Misc adjustment value to compensate for friction or other inconsistancy

		const float STEPTOIN = RATIO * RADIUS * 4 * M_PI  / RESOLUTION;	 //Converts steps of encoder to inches 


		const float MAX_HEIGHT_SPEED = 0.3;//Drive speed while elevator is fully extended
		const float CUTOFF_HEIGHT = 20.0;//Height below which to not alter drive speed
		const double TOLERANCE = 0.1;//Deviation(Inches)
		const double HOME_DIST = 0.05; //Distance per cycle to lower while homing the elevator initially - be careful with this one

		const double DEADZONE = 0.1; //Deadzone on joystick axes for elevator inputs
		const double  MOTOR_MIN = 0.3;  //Minimum current to spin motor
		const double  LINEARITY = 2.5;  //Linearity of elevator curve

		const float MAX_ACTUATOR_HEGIHT = 18.0; //Height above which manipulator actuator will not function safely
	}
	namespace HEIGHTS
	{
		//All units are heights from 0 in inches
		const double ROCKET_CARGO_LOW = 27.5;
		const double ROCKET_CARGO_MED = 55.5;
		const double ROCKET_CARGO_HIGH = 83.5;

		const double ROCKET_HATCH_LOW = 19.0;
		const double ROCKET_HATCH_MED = 47.0;
		const double ROCKET_HATCH_HIGH = 75.0;

		const double SHIP_HATCH = 19.0;
		const double SHIP_CARGO = 44.0;
		
		const double FEEDER_HATCH = 19.0;
		const double FEEDER_CARGO = 38.5;

		const double HEIGHT_MAX = 60.0;
		const double HEIGHT_MIN = 0.0;
	}
	namespace DRIVE
	{
		const double DEADZONE = 0.1;         //Deadzone on joystick axes for drive inputs
		const double  MOTOR_MIN = 0.2;      //Minimum current to spin motor
		const int LINEARITY = 3;       //Linearity of drive curve
	}
}