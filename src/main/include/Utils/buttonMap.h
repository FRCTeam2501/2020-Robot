#pragma once

namespace CONTROLLER {
	namespace DI {
		//Logitech controller button and axis numbers (DUAL INPUT NORMAL MODE)
		namespace BUTTON {
			constexpr uint32_t
				X = 1,
				A = 2,
				B = 3,
				Y = 4,
				LB = 5,
				RB = 6,
				LT = 7,
				RT = 8,
				BACK = 9,
				START = 10,
				LMELEE = 11,
				RMELEE = 12;
		}
		namespace AXIS {
			constexpr uint32_t
				L_X = 0,
				L_Y = 1,
				R_X = 2,
				R_Y = 3;
		}
	}
	namespace X {
		//Logitech controller button and axis numbers (XBOX NORMAL MODE)
		namespace BUTTON {
			constexpr uint32_t
				A = 1,
				B = 2,
				X = 3,
				Y = 4,
				LB = 5,
				RB = 6,
				BACK = 7,
				START = 8;
		}
		namespace AXIS {
			constexpr uint32_t
				L_X = 0,
				L_Y = 1,
				L_TRIGGER = 2,
				R_TRIGGER = 3,
				R_X = 4,
				R_Y = 5;
		}
	}
	namespace POV {
		//Logitech controller D-pad degrees
		constexpr uint32_t
			TOP = 0,
			TOP_RIGHT = 45,
			RIGHT = 90,
			BOTTOM_RIGHT = 135,
			BOTTOM = 180,
			BOTTOM_LEFT = 225,
			LEFT = 270,
			TOP_LEFT = 315;
	}
}

namespace JOYSTICK {
	//Standard Logitech joystick button and axis numbers
	namespace BUTTON {
		constexpr uint32_t
			TRIGGER = 1,
			THUMB = 2,
			BUTTON_3 = 3,
			BUTTON_4 = 4,
			BUTTON_5 = 5,
			BUTTON_6 = 6,
			BUTTON_7 = 7,
			BUTTON_8 = 8,
			BUTTON_9 = 9,
			BUTTON_10 = 10,
			BUTTON_11 = 11,
			BUTTON_12 = 12;
	}
	namespace AXIS {
		constexpr uint32_t
			X = 0,
			Y = 1,
			R = 2,
			Z = 3;
	}
	namespace POV {
		//Logitech controller POV degrees
		constexpr uint32_t
			TOP = 0,
			TOP_RIGHT = 45,
			RIGHT = 90,
			BOTTOM_RIGHT = 135,
			BOTTOM = 180,
			BOTTOM_LEFT = 225,
			LEFT = 270,
			TOP_LEFT = 315;
	}
}