#pragma once
#include "include.h"
#include "Pneumatics/Pneumatics.h"


class Hopper : public frc2::SubsystemBase {
private:
	Pneumatics* pneumatics;
	WPI_TalonSRX *left, *right;

public:
	Hopper(Pneumatics* pneumatics);
	~Hopper();

	void Set(double speed);

	void TogglePin() {
		switch(pneumatics->GetHopper()) {
			case frc::DoubleSolenoid::kReverse:
				pneumatics->SetHopper(frc::DoubleSolenoid::kForward);
				break;
			case frc::DoubleSolenoid::kForward:
			case frc::DoubleSolenoid::kOff:
			default:
				pneumatics->SetHopper(frc::DoubleSolenoid::kReverse);
				break;
		}
	}
};