
#include "subsystems/camera.h"



camera::camera() {
	
	wideCam = new cs::UsbCamera("Top camera", 0);
	
	
	dashStream = new cs::MjpegServer("Dashboard Stream", 1185);
	
	
	
	wideCam->SetResolution(WIDTH, HEIGHT);
	wideCam->SetFPS(FPS);
	wideCam->SetConnectionStrategy(cs::VideoSource::kConnectionKeepOpen);

	
	dashStream->SetResolution(WIDTH, HEIGHT);
	dashStream->SetFPS(FPS);

	dashStream->SetSource(*wideCam);
	
}
camera::~camera(){
	delete wideCam;
	delete dashStream;
}

void camera::Periodic() {}	



