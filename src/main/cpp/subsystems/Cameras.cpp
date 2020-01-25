#include "subsystems/Cameras.h"



Cameras::Cameras(){

 WideCam = new cs::UsbCamera("Top Camera", 0);

  dashStream = new cs::MjpegServer("Dashboard Stream", 1185);

    WideCam->SetResolution(WITH, HEIGHT);
    WideCam->SetFPS(FPS);
    WideCam->SetConnectionStrategy(cs::VideoSource::kConnectionKeepOpen);

    dashStream->SetResolution(WITH, HEIGHT);
    dashStream->SetFPS(FPS);

    dashStream->SetSource(*WideCam);
}

Cameras::~Cameras(){

delete WideCam;
delete dashStream;

}


void Cameras::Periodic(){}














