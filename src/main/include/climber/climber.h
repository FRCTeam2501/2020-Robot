
#pragma once

#include <frc2/command/SubsystemBase.h>
#include "Utils/include.h"
#include "Pneumatics/Pneumatics.h"

using namespace frc;

class climber : public frc2::SubsystemBase {
 public:
  climber(Pneumatics *pneumatics);
  ~climber();

  void StateUp();
  void StateBack();
  void SetClimb(units::angular_velocity::revolutions_per_minute_t rpm);

 private:
  Pneumatics *pneumatics;

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