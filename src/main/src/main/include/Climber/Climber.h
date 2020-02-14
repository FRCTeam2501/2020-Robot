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
  void SetClimb(double speed);

  void ToggleWinchOn();
  void ToggleWinchOff();

  void ToggleWinchDownOn(); 
  void ToggleWinchDownOff();

  void SetSpeed(double speed);

 private:
  Pneumatics *pneumatics;

  double *speed;

  uint8_t *state;

  rev::CANSparkMax *left, *right;

  enum STATES{
      OFF = 0,
      DOWN,
      UP,
      EXTEND,
      RETRACT
  };
};
