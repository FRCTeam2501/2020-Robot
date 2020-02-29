#pragma once

#include <frc2/command/SubsystemBase.h>
#include "Utils/include.h"
#include "Pneumatics/Pneumatics.h"

using namespace frc;

class Climber : public frc2::SubsystemBase {
 public:
  Climber(Pneumatics *pneumatics);
  ~Climber();

  void StateUp();
  void StateBack();

  void ToggleWinchOn();
  void ToggleWinchOff();

  void ToggleWinchDownOn(); 
  void ToggleWinchDownOff();

  void WinchToggle();

  void SetSpeed(double speed);

  void Periodic();

 private:
  Pneumatics *pneumatics;

  double *speedWinch, *speed;

  bool *changed;

  uint8_t *armState, *winchState, *runState;

  rev::CANSparkMax *left, *right;

  enum STATES{
      DEFAULT = 0,
      DOWN,
      UP,
      EXTEND,
      RETRACT
  };

  enum RUN_STATES{
      OFF = 0,
      FORWARD,
      REVERSE
  };
  
  enum WINCH_STATES{
      BOTH = 0,
      LEFT,
      RIGHT
  };
};
