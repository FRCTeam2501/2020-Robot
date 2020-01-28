
#pragma once
#include "Utils/include.h"
#include <frc2/command/SubsystemBase.h>

class camera : public frc2::SubsystemBase {
 public:
  camera();
~camera();


  void Periodic();

 private:
cs ::UsbCamera *wideCam;
cs::MjpegServer *dashStream;
const int WIDTH= 320, HEIGHT = 240, FPS = 30;
};
