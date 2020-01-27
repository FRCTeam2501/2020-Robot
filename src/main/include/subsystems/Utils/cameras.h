#pragma once 

#include "subsystems/Utils/include.h"
#include <frc2/command/SubsystemBase.h>

class Cameras: public frc2::SubsystemBase { 
    public:
    
    Cameras(); 
    ~Cameras();

    void Periodic(); 

    private: 

    cs::UsbCamera *wideCam; 
    cs::MjpegServer *dashStream;

    const int WIDTH = 320, HEIGHT = 240, FPS = 30;

};