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

namespace JOYSTICK {		//USB Joystick Ports
	//Can have a dynamic number of devices
	enum JOYSTICK_ID {
		DRIVER = 0,
		CONTROL,
		DRIVER_2
	};
}
namespace PWM {				//RoboRIO PWM Ports
	//Do not add more ports, the RIO only has 10
	enum PWM_OUTPUT {
		EMPTY_0 = 0,
		EMPTY_1,
		EMPTY_2,
		EMPTY_3,
		EMPTY_4,
		EMPTY_5,
		EMPTY_6,
		EMPTY_7,
		EMPTY_8,
		EMPTY_9
	};
}
namespace CAN {				//RoboRIO CAN Devices
	//Can have a dynamic number of devices
	enum CAN_DEVICES {
		LEFT_FRONT = 0,
		LEFT_REAR,
		RIGHT_FRONT,
		RIGHT_REAR,
		INTAKE,
		HOPPER_LEFT,
		HOPPER_RIGHT,
		EMPTY_7,
		EMPTY_8,
		EMPTY_9,
		EMPTY_10,
		CLIMBER_LEFT,
		CLIMBER_RIGHT,
		SHOOTER_LEFT,
		SHOOTER_RIGHT
	};
	enum CAN_PCM {
		CAN_PCM = 0
	};
	enum CAN_PDP {
		CAN_PDP = 0
	};
}
namespace DIO {				//RoboRIO DIO Ports
	//Do not add more ports, the RIO only has 10
	enum DIO_PORTS {
		EMPTY_0 = 0,
		EMPTY_1,
		EMPTY_2,
		EMPTY_3,
		EMPTY_4,
		EMPTY_5,
		EMPTY_6,
		EMPTY_7,
		EMPTY_8,
		EMPTY_9
	};
}
namespace MXP {				//RoboRIO's MyRIO eXpansion Ports
	//Do not add more ports, only edit and define MXP_DIO
	#ifdef MXP_DIO 
	#ifndef MXP_PWM
	namespace DIO {
		//Do not add more ports, the RIO only has 10 on MXP
		enum DIO_ON_MXP {
			EMPTY_0 = 10,
			EMPTY_1,
			EMPTY_2,
			EMPTY_3,
			EMPTY_4,
			EMPTY_5,
			EMPTY_6,
			EMPTY_7,
			EMPTY_8,
			EMPTY_9
		};
	}
	#endif 
	#endif

	#ifdef MXP_PWM
	#ifndef MXP_DIO
	namespace PWM {
		enum PWM_ON_MXP {
			//Do not add more ports, the RIO only has 10 on MXP
			EMPTY_0 = 10,
			EMPTY_1,
			EMPTY_2,
			EMPTY_3,
			EMPTY_4,
			EMPTY_5,
			EMPTY_6,
			EMPTY_7,
			EMPTY_8,
			EMPTY_9
		};
	}
	#endif
	#endif
	namespace AI {
		//Do not add more ports, the RIO only has 4 on MXP
		enum ANALOG_INPUT {
			EMPTY_0 = 0,
			EMPTY_1,
			EMPTY_2,
			EMPTY_3
		};
	}
}
namespace AI {				//RoboRIO Analog Input Ports
	//Do not add more ports, the RIO only has 4
	enum ANALOG_INPUT {
		EMPTY_0 = 0,
		EMPTY_1,
		EMPTY_2,
		EMPTY_3
	};
}
namespace RELAY {			//RoboRio Relay Ports
	//Do not add more ports, the RIO only has 4
	enum RELAY_OUT {
		EMPTY_0 = 0,
		EMPTY_1,
		EMPTY_2,
		EMPTY_3
	};
}
#ifdef PNEUMATICS
namespace PCM {				//Pnuematics Control Module Ports
	//Note: Must have PNUEMATICS defined to be included
	//Use SOL prefix for solenoids
	enum PCM_PORTS {
		VERTICALLIFT_A = 0,
		VERTICALLIFT_B,
		CLIMB_A,
		CLIMB_B,
		INTAKE_A,
		INTAKE_B
	};
}
#endif