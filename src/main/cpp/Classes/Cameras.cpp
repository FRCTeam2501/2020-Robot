#include "Classes/Cameras.h"

Cameras::Cameras() {
	front = new cs::UsbCamera("Front Camera", PORTS::CAMERA::FRONT);
	top = new cs::UsbCamera("Top Camera", PORTS::CAMERA::TOP);
	stream = frc::CameraServer::GetInstance()->AddSwitchedCamera("Switched Stream");
	state = new uint32_t(OFF);

	front->SetResolution(CONSTANTS::CAMERA::WIDTH, CONSTANTS::CAMERA::HEIGHT);
	front->SetFPS(CONSTANTS::CAMERA::FPS);
	front->SetConnectionStrategy(cs::VideoSource::kConnectionKeepOpen);

	top->SetResolution(CONSTANTS::CAMERA::WIDTH, CONSTANTS::CAMERA::HEIGHT);
	top->SetFPS(CONSTANTS::CAMERA::FPS);
	top->SetConnectionStrategy(cs::VideoSource::kConnectionKeepOpen);

	stream.SetResolution(CONSTANTS::CAMERA::WIDTH, CONSTANTS::CAMERA::HEIGHT);
	stream.SetFPS(CONSTANTS::CAMERA::FPS);

	stream.SetSource(*front);
	*state = FRONT;

	cout << "Cameras Booted!\n";
}

Cameras::~Cameras() {
	delete front;
	delete top;
}

void Cameras::Toggle() {
	switch(*state) {
		case FRONT:
			stream.SetSource(*top);
			*state = TOP;
			break;
		case TOP:
		case OFF:
		default:
			stream.SetSource(*front);
			*state = FRONT;
			break;

	}
}