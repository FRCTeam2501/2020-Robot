#include <math.h>
#pragma once


namespace CONSTANTS {
	//Cycles for the code to run per second
	const int CYCLES = 100;
	//Period of a cycle of the robot code
	const double PERIOD = 1.0 / CYCLES;

	namespace SHOOTER {
		const double P = 6e-5,
					I = 1e-6,
					D = 0,
					IZ = 0,
					FF = 0.000015,
					MAX = 1.0,
					MIN = -1.0,
					ON = 5000,
					OFF = 0;
		const int PPR = 42;			//Pulses per revolution
	}
}