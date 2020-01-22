#inlcude "subsystems/Cameras.h"



Cameras::Cameras(){

 wideCam = new cs::UsbCamera("Top Camera", 0);

  dashStream = new cs::MjpegServer("Dashboard Stream", 1185);

    WideCam->SetResolution(WITH, HEIGHT);
    WideCam->SetFPS(FPS);
    wideCam->SetConnectionStrategy(cs::VideoSource::kConnectionKeepOpen);

    dashStream->SetResolution(WITH, HEIGHT);
    dashStream->SetFPS(FPS);

    dashStream->SetScource(*wideCam);
}

Cameras::~Cameras(){

delete WideCam;
delete dashStream;

}


void Cameras::Periodic(){}














