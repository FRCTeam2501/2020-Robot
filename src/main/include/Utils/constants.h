#pragma once
#include <include.h>


namespace CONSTANTS {
	//	Use WPILib units for everything, unless it is only internal.
	//	https://nholthaus.github.io/units/namespaces.html

	namespace DRIVETRAIN {
		constexpr units::current::ampere_t
					CURRENT_LIMIT = 60_A,
					HARD_CURRENT_LIMIT = 100_A;
		constexpr units::dimensionless::scalar_t
					GEAR_RATIO = 11.0;
		constexpr units::meter_t
					WHEEL_DIAMETER = 8_in,
					TRACK_WIDTH = 22_in,
					WHEEL_CIR = (WHEEL_DIAMETER * units::constants::pi);
		constexpr auto
					TURN_TO_METER = WHEEL_CIR * GEAR_RATIO / units::angle::turn_t(1);
	}
	namespace CLIMBER {
		constexpr units::current::ampere_t
					CURRENT_LIMIT = 60_A,
					HARD_CURRENT_LIMIT = 100_A;
	}
	namespace INTAKE {
		constexpr units::current::ampere_t
					CONTINUOUS_LIMIT = 20_A,
					PEAK_LIMIT = 30_A;
		constexpr units::millisecond_t
					PEAK_TIME = 500_ms;
	}
	namespace HOPPER {
		constexpr units::current::ampere_t
					CONTINUOUS_LIMIT = 20_A,
					PEAK_LIMIT = 30_A;
		constexpr units::millisecond_t
					PEAK_TIME = 500_ms;
		constexpr double
			ON = 0.5,
			OFF = 0,
			REVERSE = -0.5;
	}
	namespace SHOOTER {
		constexpr double
					MIN = -1.0, MAX = 1.0,
					P = 6e-5, I = 5e-7, D = 0, IZ = 0,
					FF = 0;
		constexpr units::current::ampere_t
					STALL_CURRENT_LIMIT = 20_A,
					FREE_CURRENT_LIMIT = 60_A,
					HARD_CURRENT_LIMIT = 80_A;
		constexpr units::angular_velocity::revolutions_per_minute_t
					ON_SPEED = 3900_rpm,
					OFF_SPEED = 0_rpm,
					ADJUST_SPEED = 50_rpm,
					MAX_SPEED = 5700_rpm,
					STALL_SPEED = 300_rpm;
	}
	namespace CAMERA {
		constexpr uint32_t
			WIDTH = 320,
			HEIGHT = 240,
			FPS = 30;
	}
	namespace RGB {
		constexpr units::millisecond_t
			PERIOD = 100_ms;
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
		//	Do nothing (0)
		namespace OFF_0 {
			constexpr uint32_t MODE = 0b00000;
		}
		//	Drive forward at x percent for y time
		namespace SIMPLE_DRIVE {
			constexpr uint32_t MODE = 0b00001;
			constexpr units::millisecond_t TIME = 1000_ms;
			constexpr double SPEED = 0.75;
		}
		//	Shoot a few balls
		namespace SIMPLE_SHOOT {
			constexpr uint32_t MODE = 0b00010;
			constexpr units::millisecond_t
				SPIN_UP_TIME = 1500_ms,
				SHOOT_TIME = 7500_ms;
		}
		//	Combine SIMPLE_DRIVE and SIMPLE_SHOOT (in that order)
		namespace SIMPLE_DRIVE_SHOOT {
			constexpr uint32_t MODE = 0b00011;
		}
		//	Combine SIMPLE_SHOOT and SIMPLE_DRIVE (in that order)
		namespace SIMPLE_SHOOT_DRIVE {
			constexpr uint32_t MODE = 0b00100;
		}
		//	Drive at x percent until past y feet
		namespace ADV_DRIVE {
			constexpr uint32_t MODE = 0b00101;
			constexpr double SPEED = 0.75;
			constexpr units::meter_t DISTANCE = 3_ft;
		}
		//	Do nothing (1)
		namespace OFF_1 {
			constexpr uint32_t MODE = 0b11111;
		}
	}
}