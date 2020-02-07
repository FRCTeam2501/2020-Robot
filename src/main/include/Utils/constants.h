#include <math.h>
#pragma once


namespace CONSTANTS {
	namespace SHOOTER {
		constexpr double P = 6e-5, I = 1e-6, D = 0,
					IZ = 0, FF = 0.000015,
					MAX = 1.0, MIN = -1.0,
					ON_SPEED = 4000, OFF_SPEED = 0, ADJUST_SPEED = 50,
					CURRENT_LIMIT = 60.0,
					PPR = 42;			//Pulses per revolution
	}

	namespace HOPPER {
		constexpr double ON_SPEED = 0.5, OFF_SPEED = 0;
	}

	namespace AUTO {
		namespace OFF_0 {
			constexpr uint8_t MODE = 0b00000;
		}
		namespace SIMPLE_DRIVE {
			constexpr uint8_t MODE = 0b00001;
			constexpr units::second_t TIME = units::second_t(1.0);
			constexpr double SPEED = 0.75;
		}
		namespace SIMPLE_SHOOT {
			constexpr uint8_t MODE = 0b00010;
			constexpr units::second_t SPIN_UP_TIME = units::second_t(1.5);
			constexpr units::second_t SHOOT_TIME = units::second_t(7.5);
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
}