    #include "Utils/include.h"
    #pragma once
    #include "climber/Climber.h"
    class RGB : public frc::ErrorBase {
        public:
        RGB(Climber *climber);
        ~RGB();
        setLEDsPercent(CONSTANTS *CONSTANTS, ledData *ledData);
        ~setLEDsPercent();  
        climber(BOTH *BOTH, LEFT *LEFT, RIGHT *RIGHT, GetArmState *GetArmState, GetWinchState *GetWinchState, GetRunState *GetRunState, GetWinchSpeed *GetWinchSpeed);
        ~climber();
        private: 
        frc::AddressableLED *leds;
       uint32_t *climbArm, *winchState, *climbWinch, *climbRun, *armState, *runState, *changed;
	double *climbSpeed;
	
    void RunClimber();
	void SetClimbArm(double percentLength) {
		frc::Color8Bit color = (frc::Color::kPurple);
		SetLEDsPercent(CONSTANTS::RGB::CLIMBER::LEFT, CONSTANTS::RGB::CLIMBER::LEFT_ARM_END, color, abs(percentLength));
		SetLEDsPercent(CONSTANTS::RGB::CLIMBER::RIGHT, CONSTANTS::RGB::CLIMBER::RIGHT_ARM_END, color, abs(percentLength));
        SetLEDsPercent(CONSTANTS::RGB::CLIMBER::BOTH, CONSTANTS::RGB::CLIMBER::BOTH_ARM_END, color, abs(percentLength));
    }
    };  
