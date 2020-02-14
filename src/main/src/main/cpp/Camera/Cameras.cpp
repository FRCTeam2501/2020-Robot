#include "Cameras/Cameras.h"

Cameras::Cameras() {
    wideCam = new cs::UsbCamera("Top Camera", 0);

    dashStream = new cs::MjpegServer("Dashboard Stream", 1185);

    wideCam->SetResolution(WIDTH, HEIGHT);
	wideCam->SetFPS(FPS);
	wideCam->SetConnectionStrategy(cs::VideoSource::kConnectionKeepOpen);

    dashStream->SetResolution(WIDTH, HEIGHT);
	dashStream->SetFPS(FPS);

    dashStream->SetSource(*wideCam);
}

Cameras::~Cameras() {
    delete wideCam;
    delete dashStream;
}

void Cameras::Periodic() {}

