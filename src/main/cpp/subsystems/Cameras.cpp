#include "subsystems/Cameras.h"


using namespace frc; 

Cameras::Cameras(){

  WideCam = new cs::UsbCamera("Top Camera", 0);
  OtherCam = new cs::UsbCamera("Other Camera", 1);
  dashStream = new cs::MjpegServer("Dashboard Stream", 1185);
  otherStream = new cs::MjpegServer("That other stream", 1186);

    WideCam->SetResolution(WITH, HEIGHT);
    WideCam->SetFPS(FPS);
    WideCam->SetConnectionStrategy(cs::VideoSource::kConnectionKeepOpen);

    OtherCam->SetResolution(WITH, HEIGHT);
    OtherCam->SetFPS(FPS);
    OtherCam->SetConnectionStrategy(cs::VideoSource::kConnectionKeepOpen);

    dashStream->SetResolution(WITH, HEIGHT);
    dashStream->SetFPS(FPS);
    dashStream->SetSource(*WideCam);

    otherStream->SetResolution(WITH, HEIGHT);
    otherStream->SetFPS(FPS);
    otherStream->SetSource(*OtherCam);
    
}

Cameras::~Cameras(){

delete WideCam;
delete OtherCam;
delete dashStream;
delete otherStream;

}


void Cameras::InitDefaultCommand(){

}

void Cameras::StreamOtherCam(){
dashStream->SetSource(*OtherCam);
	*stream = '1';
}

void Cameras::StreamWideCam(){
dashStream->SetSource(*WideCam);
	*stream = 'O';
}

char Cameras::GetStream(){
  return *stream;
}

