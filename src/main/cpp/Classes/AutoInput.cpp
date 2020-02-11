#include "Classes/AutoInput.h"

AutoInput::AutoInput() {
	switch0 = new frc::DigitalInput(MXP::DIO::AUTO_0);
	switch1 = new frc::DigitalInput(MXP::DIO::AUTO_1);
	switch2 = new frc::DigitalInput(MXP::DIO::AUTO_2);
	switch3 = new frc::DigitalInput(MXP::DIO::AUTO_3);
	switch4 = new frc::DigitalInput(MXP::DIO::AUTO_4);

	cout << "AutoInput Booted!\n";
}

AutoInput::~AutoInput() {
	delete switch0;
	delete switch1;
	delete switch2;
	delete switch3;
	delete switch4;
}

uint8_t AutoInput::Get() {
	return
		(switch4->Get() << 4) +
		(switch3->Get() << 3) +
		(switch2->Get() << 2) +
		(switch1->Get() << 1) +
		(switch0->Get() << 0)
	;
}