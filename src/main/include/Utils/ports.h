#pragma once



#define MXP_DIO

#define PNEUMATICS

namespace JOYSTICK	
{

	enum JOYSTICK_ID
	{
		DRIVER = 0,
		DRIVER_ROTATE,
		CONTROL
	};
}
namespace PWM		
{
	enum PWM_OUTPUT
	{
		RIGHT_FRONT = 0,
		RIGHT_REAR,
		LEFT_FRONT,
		Hopper2,
		Hopper,
		RGB,
		EMPTY_6,
		EMPTY_7,
		EMPTY_8,
		EMPTY_9
	};
}
namespace CAN		
{
	
	enum CAN_DEVICES
	{
		LEFT_FRONT = 0,
		LEFT_REAR,
		RIGHT_FRONT,
		RIGHT_REAR,
		INTAKE,
		HOPPER_LEFT,
		HOPPER_RIGHT,
		EMPTY_1,
		EMPTY_2,
		EMPTY_3,
		EMPTY_4,
		CLIMBER_LEFT,
		CLIMBER_RIGHT,
		SHOOTER_LEFT,
		SHOOTER_RIGHT

	};
	enum CAN_PCM
	{
		CAN_PCM = 0
	};
}
namespace DIO		//RoboRIO DIO Ports
{
	//Do not add more ports, the RIO only has 10
	enum DIO_PORTS
	{
		LS_BOTTOM = 0,
		LS_TOP,
		EMPTY_2,
		EMPTY_3,
		EMPTY_4,
		AUTO_A,
		AUTO_B,
		AUTO_C,
		AUTO_D,
		AUTO_E
	};
}
namespace MXP		//RoboRIO's MyRIO eXpansion Ports
{
	//Do not add more ports, only edit and define MXP_DIO
	#ifdef MXP_DIO 
	#ifndef MXP_PWM
	namespace DIO
	{	//Do not add more ports, the RIO only has 10 on MXP
		enum DIO_ON_MXP
		{
			EMPTY0 = 10,
			EMPTY1,
			EMPTY2,
			EMPTY3,
			EMPTY4,
			EMPTY5,
			EMPTY6,
			EMPTY7,
			EMPTY8,
			EMPTY9
		};
	}
	#endif 
	#endif

	#ifdef MXP_PWM
	#ifndef MXP_DIO
	namespace PWM
	{
		enum PWM_ON_MXP
		{	//Do not add more ports, the RIO only has 10 on MXP
			EMPTY0 = 10,
			EMPTY1,
			EMPTY2,
			EMPTY3,
			EMPTY4,
			EMPTY5,
			EMPTY6,
			EMPTY7,
			EMPTY8,
			EMPTY9
		};
	}
	#endif
	#endif
	namespace AI
	{	//Do not add more ports, the RIO only has 4 on MXP
		enum ANALOG_INPUT
		{
			EMPTY0 = 0,
			EMPTY1,
			EMPTY2,
			EMPTY3
		};
	}
}
namespace AI		//RoboRIO Analog Input Ports
{
	//Do not add more ports, the RIO only has 4
	enum ANALOG_INPUT
	{
		EMPTY0 = 0,
		EMPTY1,
		EMPTY2,
		EMPTY3
	};
}
namespace RELAY		//RoboRio Relay Ports
{
	//Do not add more ports, the RIO only has 4
	enum RELAY_OUT
	{
		EMPTY_0 = 0,
		EMPTY_1,
		EMPTY_2,
		EMPTY_3
	};
}
#ifdef PNEUMATICS
namespace PCM		//Pnuematics Control Module Ports
{
	//Note: Must have PNUEMATICS defined to be included
	//Use SOL prefix for solenoids
	enum PCM_PORTS
	{
		SOL_VERTICALLIFT_A = 0,
		SOL_VERTICALLIFT_B,

		SOL_CLIMB_A,
		SOL_CLIMB_B,

		SOL_INTAKE_A,
		SOL_INTAKE_B
	};
}
#endif
