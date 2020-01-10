#include "Utils/include.h"

using namespace frc;

#pragma once

class OI {
 private:
    static Joystick 
      *driverStick,
      *driverStick2,
      *controlStick;
  
 public:
  OI();
  ~OI();

  double getXSpeed(){
    return driverStick -> GetX();
  }
  double getZSpeed(){
    return driverStick2 -> GetZ();
  }
};
