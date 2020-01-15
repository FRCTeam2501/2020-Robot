#pragma once

#include "Utils/Include.h"
#include <frc2/command/SubsystemBase.h>

class Cameras : public frc2::SubsystemBase {
 public:
  Cameras();
  ~Cameras();

  void Periodic();

 private:
};
