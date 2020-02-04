#include <math.h>
#pragma once


namespace CONSTANTS {
	namespace SHOOTER {
		const double P = 6e-5, I = 1e-6, D = 0,
					IZ = 0, FF = 0.000015,
					MAX = 1.0, MIN = -1.0,
					ON = 5000, OFF = 0, ADJUST = 50,
					CURRENT_LIMIT = 60.0,
					PPR = 42;			//Pulses per revolution
	}

	namespace HOPPER {
		const double SPEED = 0.5;
	}
}