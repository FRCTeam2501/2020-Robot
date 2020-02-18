#include <units/units.h>
#pragma once


namespace CONSTANTS {
	//	Use WPILib units for everything, unless it is only internal.
	//	https://nholthaus.github.io/units/namespaces.html

	namespace DRIVETRAIN {
		constexpr units::current::ampere_t
					CURRENT_LIMIT = 60_A;
		constexpr units::inch_t
					WHEEL_DIAMETER = 8_in,
					TRACK_WIDTH = 22_in;
		constexpr units::length::foot_t
					WHEEL_CIR = (WHEEL_DIAMETER * units::constants::pi);
		constexpr units::dimensionless::scalar_t
					GEAR_RATIO = 10.1;
		constexpr auto
					TURN_TO_FEET = WHEEL_CIR * GEAR_RATIO / units::angle::turn_t(1);
	}
	namespace CLIMBER {
		constexpr units::current::ampere_t
					CURRENT_LIMIT = 60_A;
	}
	namespace INTAKE {
		constexpr units::current::ampere_t
					CONTINUOUS_LIMIT = 20_A,
					PEAK_LIMIT = 35_A;
		constexpr units::millisecond_t
					PEAK_TIME = 1000_ms;
	}
	namespace HOPPER {
		constexpr units::current::ampere_t
					CONTINUOUS_LIMIT = 20_A,
					PEAK_LIMIT = 35_A;
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
					CURRENT_LIMIT = 40_A;
		constexpr units::angular_velocity::revolutions_per_minute_t
					ON_SPEED = 3900_rpm,
					OFF_SPEED = 0_rpm,
					ADJUST_SPEED = 50_rpm;
	}
	namespace CAMERA {
		constexpr uint32_t
			WIDTH = 320,
			HEIGHT = 240,
			FPS = 30;
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
			constexpr units::millisecond_t TIME = 1000_ms;
			constexpr double SPEED = 0.75;
		}
		namespace SIMPLE_SHOOT {
			constexpr uint8_t MODE = 0b00010;
			constexpr units::millisecond_t
					SPIN_UP_TIME = 1500_ms,
					SHOOT_TIME = 7500_ms;
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
	namespace TELEOP {
		namespace HOPPER {
			constexpr units::millisecond_t TIME = 500_ms;
		}
	}
}