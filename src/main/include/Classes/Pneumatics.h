#pragma once
#include "include.h"


class Pneumatics : public frc::ErrorBase {
private:
	frc::Compressor *compressor;
	frc::DoubleSolenoid *climbArm, *climbExtend, *intake, *hopper;

public:
	Pneumatics();
	~Pneumatics();
	void Periodic();

	void SetClimbArm(frc::DoubleSolenoid::Value value) {
		climbArm->Set(value);
	}

	frc::DoubleSolenoid::Value GetClimbArm() {
		return climbArm->Get();
	}

	void SetClimbExtend(frc::DoubleSolenoid::Value value) {
		climbExtend->Set(value);
	}

	frc::DoubleSolenoid::Value GetClimbExtend() {
		return climbExtend->Get();
	}

	void SetIntake(frc::DoubleSolenoid::Value value) {
		intake->Set(value);
	}

	frc::DoubleSolenoid::Value GetIntake() {
		return intake->Get();
	}

	void SetHopper(frc::DoubleSolenoid::Value value) {
		hopper->Set(value);
	}

	frc::DoubleSolenoid::Value GetHopper() {
		return hopper->Get();
	}

	void StartCompressor() {
		compressor->Start();
	}

	void StopCompressor() {
		compressor->Stop();
	}
};