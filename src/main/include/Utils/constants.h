#pragma once
#include <units/units.h>

namespace CONSTANTS {

	namespace SHOOTER{
		const double 
		kP = 6e-5,
		//kP is the thing that keeps it at that speed
		kI = 5e-7, 
		//kI is the thing that gets it up to speed
		kD = 0, 
		//kD is the thing that is ocelation prevention
		kIz = 0, 
		kFF = 0, 
		kMaxOutput = 1.0, 
		kMinOutput = -1.0,
		adjustSpeed = 50,
		MaxRPM = 5700;
	}

	namespace DRIVETRAIN {
		constexpr units::current::ampere_t
			CURRENT_LIMIT = 60_A;
		constexpr units::meter_t
			WHEEL_DIAMETER = 8_in,
			TRACK_WIDTH = 22_in;
		constexpr units::length::meter_t
			WHEEL_CIRCUM = WHEEL_DIAMETER*(units::constants::pi);
		constexpr units::dimensionless::scalar_t
			GEAR_RATIO = 11.1;
		constexpr auto
			TURN_TO_METER = WHEEL_CIRCUM * GEAR_RATIO / units::angle::turn_t(1);

	}

	namespace INTAKE {
		constexpr units::current::ampere_t
			CURRENT_LIMIT = 60_A,
			PEAK_LIMIT = 30_A;
	}

	namespace HOPPER {
		constexpr units::current::ampere_t
			CURRENT_LIMIT = 40_A;
		constexpr double 
			MIN = -1.0,
			MAX = 1.0,
			P = 1e-7,
			I = 0,
			D = 0,
			IZ = 0;
		constexpr units::voltage::volt_t
			FF = 0_V;
		constexpr units::angular_velocity::revolutions_per_minute_t
			ON_SPEED = 3000_rpm,
			OF_SPEED = 0_rpm,
			MAX_SPEED = 5700_rpm,
			ADJUST_SPEED = 50_rpm;
	}

	namespace CLIMBER {
		constexpr units::current::ampere_t
			CURRENT_LIMIT = 60_A;
	}
	
	namespace CAMARA {
		constexpr uint32_t
			WIDTH = 320,
			HEIGTH = 240,
			FPS = 60;
	}
}