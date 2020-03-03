#include "subsystems/Cameras.h"


using namespace frc; 

Cameras::Cameras(){

  WideCam = new cs::UsbCamera("Top Camera", 0);
  dashStream = new cs::MjpegServer("Dashboard Stream", 1185);
  cameraRotator = new frc::Servo(cameraAngle);

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
delete cameraRotator;
}


void Cameras::StreamWideCam(){
dashStream->SetSource(*WideCam);
	*stream = 'O';
}

char Cameras::GetStream(){
  return *stream;
}

void Cameras::RotateCameraUp(){
  if(cameraAngle <= 0.95){
cameraAngle += changeAngle;
cameraRotator->Set(cameraAngle);
}
}
void Cameras::RotateCameraDown(){
  if(cameraAngle >= 0.05){
cameraAngle -= changeAngle;
cameraRotator->Set(cameraAngle);
}
}
