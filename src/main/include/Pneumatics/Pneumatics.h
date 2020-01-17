#pragma once
#include "include.h"
using namespace frc;

class Pneumatics : public frc2::SubsystemBase {
private:
	Compressor *compressor;
	DoubleSolenoid *climbRight, *climbLeft, *intakeRight, *intakeLeft;

public:
	Pneumatics();
	~Pneumatics();
	void Periodic();

	void SetClimb(DoubleSolenoid::Value value) {
		climbRight->Set(value);
		climbLeft->Set(value);
	}

	DoubleSolenoid::Value GetClimb() {
		return climbRight->Get();
	}

	void SetIntake(DoubleSolenoid::Value value) {
		intakeRight->Set(value);
		intakeLeft->Set(value);
	}

	DoubleSolenoid::Value GetIntake() {
		return intakeRight->Get();
	}

	void StartCompressor() {
		compressor->Start();
	}

	void StopCompressor() {
		compressor->Stop();
	}
};
