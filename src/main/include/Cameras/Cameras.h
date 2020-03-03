#pragma once

#include "Utils/include.h"


using namespace frc;

class Cameras : frc2::SubsystemBase
{
private:
    cs::UsbCamera *WideCam;
    cs::MjpegServer *dashStream;
    //frc::Servo *cameraRotator;

    char *stream;

    const int WITH = 320, HEIGHT = 230, FPS = 30;
    //const double changeAngle = 5;
    //double cameraAngle = 100;
    
public:
    Cameras();
    ~Cameras();

    void StreamWideCam();
    char GetStream();
    //void RotateCameraUp();
    //void RotateCameraDown();
};