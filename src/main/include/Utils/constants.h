#include <math.h>
#pragma once


namespace CONSTANTS {
	//	Use WPILib units for everything, unless it is only internal.
	//	https://nholthaus.github.io/units/namespaces.html

	namespace DRIVETRAIN {
		constexpr units::current::ampere_t
					CURRENT_LIMIT = 60.0_A;
	}
	namespace CLIMBER {
		constexpr units::current::ampere_t
					CURRENT_LIMIT = 60.0_A;
	}
	namespace INTAKE {
		constexpr units::current::ampere_t
					CONTINUOUS_LIMIT = 20.0_A,
					PEAK_LIMIT = 35.0_A;
		constexpr units::millisecond_t
					PEAK_TIME = 1000_ms;
	}
	namespace HOPPER {
		constexpr units::current::ampere_t
					CONTINUOUS_LIMIT = 20.0_A,
					PEAK_LIMIT = 35.0_A;
		constexpr units::millisecond_t
					PEAK_TIME = 1000_ms;
		constexpr double ON = 0.5, OFF = 0;
	}
	namespace SHOOTER {
		constexpr double
					MIN = -1.0, MAX = 1.0,
					P = 1e-7, I = 0, D = 0, IZ = 0;
		constexpr units::voltage::volt_t
					FF = 0_V;
		constexpr units::current::ampere_t
					CURRENT_LIMIT = 40.0_A;
		constexpr units::angular_velocity::revolutions_per_minute_t
					ON_SPEED = 3900_rpm,
					OFF_SPEED = 0_rpm,
					ADJUST_SPEED = 50_rpm;
	}
/*
	namespace SHOOTER_SATURDAY {
		constexpr double
					P = 1e-7, I = 0, D = 0,
					IZ = 0, FF = 1.75e-4,
					MIN = -1.0, MAX = 1.0,
					ON_SPEED = (3900/2), OFF_SPEED = 0, ADJUST_SPEED = 50,
					CURRENT_LIMIT = 60.0;
	}
	namespace SHOOTER_OLD {
		constexpr double
					P = 6e-5, I = 1e-6, D = 0,
					IZ = 0, FF = 1.5e-5,
					MAX = 1.0, MIN = -1.0,
					ON_SPEED = 3900, OFF_SPEED = 0, ADJUST_SPEED = 25,
					CURRENT_LIMIT = 60.0,
					PPR = 42;			//Pulses per revolution
	}
*/
	namespace AUTO {
		namespace OFF_0 {
			constexpr uint8_t MODE = 0b00000;
		}
		namespace SIMPLE_DRIVE {
			constexpr uint8_t MODE = 0b00001;
			constexpr units::second_t TIME = 1.0_s;
			constexpr double SPEED = 0.75;
		}
		namespace SIMPLE_SHOOT {
			constexpr uint8_t MODE = 0b00010;
			constexpr units::second_t
					SPIN_UP_TIME = 1.5_s,
					SHOOT_TIME = 7.5_s;
		}
		namespace SIMPLE_DRIVE_SHOOT {
			constexpr uint8_t MODE = 0b00011;
		}
		namespace SIMPLE_SHOOT_DRIVE {
			constexpr uint8_t MODE = 0b00100;
		}
		namespace OFF_1 {
			constexpr uint8_t MODE = 0b11111;
		}
	}
	namespace CAMERA {
		constexpr uint32_t
			WIDTH = 320,
			HEIGHT = 240,
			FPS = 30;
	}
}