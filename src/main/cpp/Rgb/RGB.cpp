    #include "Rgb/RGB.h"
    #include "Utils/ports.h"
   
    RGB::RGB(Climber *climber){

	armState = climber->GetArmState();
	winchState = climber->GetWinchState();
	runState = climber->GetRunState();
	changed= climber->GetWinchSpeed();
    leds = new frc::AddressableLED(PORTS::PWM::RGB);
    led->SetLength(CONSTANTS::RGB::36);
    leds->Start();
}
    uint32_t *climbArm, *climbWinch, *climbRun;
	double *climbSpeed;
	
  void RGB::RunClimber() {
      switch(*winchState)
    case Climber::BOTH:
			SetClimbArm(1);
			break;
		case Climber::LEFT:
			SetClimbArm(0.5);
			break;
		case Climber::RIGHT:
			SetClimbArm(0.5);
			break;
            }
    frc::Color8Bit RGB::Color() {

    }
    void RGB::setLEDsPercent(uint32_t start, uint32_t end, frc::Color8Bit color, double percentLength){
        uint32_t i, length = end - start;
        
           i=start;
            while(i < ((percentLength * length) + start )&& i < end){
                ledData[i].setLED(frc::Color::kPurple);
                1++;
            }
            while(i < end ){
                ledData[i].setLED(frc::Color::kBlack);
            }
        
    }
  