#pragma once
/**
 * Port declarations
 * 
 * Access each by accessing the namespace then the port name
 * Example: AI:EMPTY0
 */

//Pick one of the following:
#define MXP_DIO
//#define MXP_PWM

//Define if using pneumatics
#define PNEUMATICS

namespace JOYSTICK	//USB Joystick Ports
{
	//Can have a dynamic number of devices
	enum JOYSTICK_ID
	{
		DRIVER = 0,
		DRIVER_ROTATE,
		CONTROL
	};
}
namespace PWM		//RoboRIO PWM Ports
{
	//Do not add more ports, the RIO only has 10
	enum PWM_OUTPUT
	{
		RIGHT_FRONT = 0,
		RIGHT_REAR,
		LEFT_FRONT,
		LEFT_REAR,
		LIFTER,
		EMPTY_5,
		EMPTY_6,
		EMPTY_7,
		EMPTY_8,
		EMPTY_9
	};
}
namespace CAN		//RoboRIO CAN Devices
{
	//Can have a dynamic number of devices
	enum CAN_DEVICES
	{
		CAN_PCM = 0,
		EMPTY_1
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
namespace MXP		
{

	#ifdef MXP_DIO 
	#ifndef MXP_PWM
	namespace DIO
	{	
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
		SOL_LEFT_A = 0,
		SOL_LEFT_B,
		SOL_RIGHT_A,
		SOL_RIGHT_B,
		SOL_RAISE_A,
		SOL_RAISE_B,
		EMPTY_6,
		EMPTY_7
	};
}
#endif