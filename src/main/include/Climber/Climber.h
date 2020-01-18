#pragma once

#include <frc2/command/SubsystemBase.h>

using namespace frc;

class Climber : public frc2::SubsystemBase {
 public:
  Climber();
  ~Climber();

  void Periodic(); 

 private:
};
