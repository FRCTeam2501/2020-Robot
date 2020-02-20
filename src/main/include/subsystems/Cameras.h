#pragma once;

#include "Utils/include.h"

using namespace frc;

class Cameras : frc2::SubsystemBase
{
private:
    cs::UsbCamera *WideCam, *OtherCam;
    cs::MjpegServer *dashStream;

    char *stream;

    const int WITH = 320;
    const int HEIGHT = 230;
    const int FPS = 30;

public:
    Cameras();
    ~Cameras();

    void InitDefaultCommand();
    void StreamOtherCam();
    void StreamWideCam();
    char GetStream();

};























