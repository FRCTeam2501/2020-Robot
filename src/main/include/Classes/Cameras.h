#pragma once

#include "include.h"

class Cameras : public frc::ErrorBase {
 public:

  Cameras();
  ~Cameras();

  void Periodic();

 private:

    cs::UsbCamera *wideCam;
    cs::MjpegServer *dashStream;

    const int WIDTH = 320, HEIGHT = 240, FPS = 30;
 
};
