#pragma once


/**
 * Port declarations
 * 
 * Access each by accessing the namespace then the port name
 * Example: AI:EMPTY0
 */

#define MXP_DIO
//#define MXP_PWM
	//Pick either DIO or PWM for the MXP ports

#define PNEUMATICS
	//Uncomment to allow pneumatic ports


namespace JOYSTICK	//USB Joystick Ports
{
	//Can have a dynamic number of devices
	enum JOYSTICK_ID
	{
		DRIVER = 0,
		DRIVER_2,
		CONTROL
	};
}
namespace PWM		//RoboRIO PWM Ports
{
	//Do not add more ports, the RIO only has 10
	enum PWM_OUTPUT
	{
		FRONT_LEFT = 0,
		FRONT_RIGHT,
		REAR_LEFT,
		REAR_RIGHT,
		EMPTY_4,
		EMPTY_5,
		EMPTY_6,
		EMPTY_7,
		EMPTY_8,
		EMPTY_9
	};
}
namespace CAN		//RoboRIO CAN Devices
{
	enum PCM_ID
	{
		PCM = 0
	};
	enum PDP_ID
	{
		PDP = 0
	};
	//Can have a dynamic number of devices
	enum CAN_DEVICES
	{
		ELEVATOR_A = 5,
		ELEVATOR_B,
		BOOST_MOTOR
	};
}
namespace DIO		//RoboRIO DIO Ports
{
	//Do not add more ports, the RIO only has 10
	enum DIO_PORTS
	{
		E_ENC_A = 0,
		E_ENC_B,
		E_LS,
		EMPTY_3,
		EMPTY_4,
		EMPTY_5,
		EMPTY_6,
		EMPTY_7,
		EMPTY_8,
		EMPTY_9
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
			EMPTY_0 = 10,
			EMPTY_1,
			EMPTY_2,
			EMPTY3,
			EMPTY4,
			EMPTY5,
			EMPTY6,
			EMPTY7,
			EMPTY8,
			EMPTY9
		};
	}
	#endif //MXP_PWM
	#endif //MXP_DIO
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
	#endif //MXP_DIO
	#endif //MXP_PWM
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
	//Note: Must have PNEUMATICS defined to be included
	enum PCM_PORTS
	{
		MANIP_INTAKE_A = 0,
		MANIP_INTAKE_B,
		MANIP_ACTUATOR_A,
		MANIP_ACTUATOR_B,
		BOOSTER_A,
		BOOSTER_B,
		BOOSTER_C,
		BOOSTER_D
	};
}
#endif //PNEUMATICS
namespace PDP_PORTS
{
	enum PORTS
	{
		DRIVE_RF = 0,
		DRIVE_RR,
		DRIVE_LF,
		DRIVE_LR,
		EMPTY_4,
		EMPTY_5,
		EMPTY_6,
		EMPTY_7,
		EMPTY_8,
		EMPTY_9,
		EMPTY_10,
		EMPTY_11,
		BOOSTER,
		ELEVATOR_A,
		ELEVATOR_B,
		EMPTY_15
	};
}