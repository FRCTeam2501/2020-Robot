#pragma once
#include <include.h>


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
					ADJUST_SPEED = 50_rpm,
					MAX_SPEED = 5700_rpm;
	}
	namespace CAMERA {
		constexpr uint32_t
			WIDTH = 320,
			HEIGHT = 240,
			FPS = 30;
	}
	namespace RGB {
		constexpr uint32_t
			//Length of entire strip
			LENGTH = 150,
			START = 0,
			END = LENGTH - 1;

			namespace DRIVETRAIN {
				constexpr uint32_t
					LENGTH = 30,
					STRIP_LENGTH = LENGTH / 2,
					START = RGB::START,

					LEFT_FRONT_END = START + (STRIP_LENGTH / 2) - 1,
					LEFT_REAR_START = LEFT_FRONT_END + 1,
					LEFT_END = START + STRIP_LENGTH - 1,
					RIGHT_START = LEFT_END + 1,
					RIGHT_FRONT_END = RIGHT_START + (STRIP_LENGTH / 2) - 1,
					RIGHT_REAR_START = RIGHT_FRONT_END + 1,

					END = START + LENGTH - 1;
			}

			namespace CLIMBER {
				constexpr uint32_t
					LENGTH = 60,
					STRIP_LENGTH = LENGTH / 4,
					START = DRIVETRAIN::END + 1,

					LEFT_ARM_END = START + STRIP_LENGTH - 1,
					RIGHT_ARM_START = LEFT_ARM_END + 1,
					RIGHT_ARM_END = RIGHT_ARM_START + STRIP_LENGTH - 1,
					LEFT_WINCH_START = RIGHT_ARM_END + 1,
					LEFT_WINCH_END = LEFT_WINCH_START + STRIP_LENGTH - 1,
					RIGHT_WINCH_START = LEFT_WINCH_END + 1,

					END = START + LENGTH - 1;
			}

			namespace INTAKE {
				constexpr uint32_t
					LENGTH = 30,
					STRIP_LENGTH = LENGTH / 2,
					START = CLIMBER::END,

					LEFT_END = START + STRIP_LENGTH - 1,
					RIGHT_START = LEFT_END + 1,

					END = START + LENGTH - 1;
			}

			namespace SHOOTER {
				constexpr uint32_t
					LENGTH = 30,
					STRIP_LENGTH = LENGTH / 2,
					START = INTAKE::END,

					LEFT_END = START + STRIP_LENGTH - 1,
					RIGHT_START = LEFT_END + 1,

					END = START + LENGTH - 1;
			}

			constexpr frc::Color8Bit
				DISABLED = frc::Color::kGray,
				ERROR = frc::Color::kDeepPink;
	}

	namespace AUTO {
		namespace OFF_0 {
			constexpr uint32_t MODE = 0b00000;
		}
		namespace SIMPLE_DRIVE {
			constexpr uint32_t MODE = 0b00001;
			constexpr units::millisecond_t TIME = 1000_ms;
			constexpr double SPEED = 0.75;
		}
		namespace SIMPLE_SHOOT {
			constexpr uint32_t MODE = 0b00010;
			constexpr units::millisecond_t
					SPIN_UP_TIME = 1500_ms,
					SHOOT_TIME = 7500_ms;
		}
		namespace SIMPLE_DRIVE_SHOOT {
			constexpr uint32_t MODE = 0b00011;
		}
		namespace SIMPLE_SHOOT_DRIVE {
			constexpr uint32_t MODE = 0b00100;
		}
		namespace OFF_1 {
			constexpr uint32_t MODE = 0b11111;
		}
	}
	namespace TELEOP {
		namespace HOPPER {
			constexpr units::millisecond_t TIME = 500_ms;
		}
	}
}