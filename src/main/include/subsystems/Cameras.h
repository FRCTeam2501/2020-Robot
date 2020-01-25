#pragma once;

#include "Utils/include.h"

using namespace frc;

class Cameras : frc2::SubsystemBase
{
private:
    cs::UsbCamera *WideCam;
    cs::MjpegServer *dashStream;

    const int WITH = 320;
    const int HEIGHT = 230;
    const int FPS = 30;

public:
    Cameras();
    ~Cameras();

    void Periodic();


 
};























