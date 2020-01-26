#pragma once
#include "include.h"
using namespace frc;


class Pneumatics : public frc2::SubsystemBase {
private:
	Compressor *compressor;
	DoubleSolenoid *climbArm, *climbExtend, *intake, *shooter;

public:
	Pneumatics();
	~Pneumatics();
	void Periodic();

	void SetClimbArm(DoubleSolenoid::Value value) {
		climbArm->Set(value);
	}

	DoubleSolenoid::Value GetClimbArm() {
		return climbArm->Get();
	}

	void SetClimbExtend(DoubleSolenoid::Value value) {
		climbExtend->Set(value);
	}

	DoubleSolenoid::Value GetClimbExtend() {
		return climbExtend->Get();
	}

	void SetIntake(DoubleSolenoid::Value value) {
		intake->Set(value);
	}

	DoubleSolenoid::Value GetIntake() {
		return intake->Get();
	}

	void SetShooter(DoubleSolenoid::Value value) {
		shooter->Set(value);
	}

	DoubleSolenoid::Value GetShooter() {
		return shooter->Get();
	}

	void StartCompressor() {
		compressor->Start();
	}

	void StopCompressor() {
		compressor->Stop();
	}

	void Disable() {
		climbArm->Set(DoubleSolenoid::kOff);
		climbExtend->Set(DoubleSolenoid::kOff);
		intake->Set(DoubleSolenoid::kOff);
		shooter->Set(DoubleSolenoid::kOff);
	}
};