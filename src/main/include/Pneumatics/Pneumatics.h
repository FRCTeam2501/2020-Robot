#pragma once
#include "include.h"
using namespace frc;


class Pneumatics : public frc2::SubsystemBase {
private:
	Compressor *compressor;
	//DoubleSolenoid *climbArm, *climbExtend, *intake, *shooter;

public:
	Pneumatics();
	~Pneumatics();
	void Periodic();

	void SetClimbArm(DoubleSolenoid::Value value) {
		//climbArm->Set(value);
	}

	DoubleSolenoid::Value GetClimbArm() {
		//return climbArm->Get();
		return DoubleSolenoid::kOff;
	}

	void SetClimbExtend(DoubleSolenoid::Value value) {
		//climbExtend->Set(value);
	}

	DoubleSolenoid::Value GetClimbExtend() {
		//return climbExtend->Get();
		return DoubleSolenoid::kOff;
	}

	void SetIntake(DoubleSolenoid::Value value) {
		//intake->Set(value);
	}

	DoubleSolenoid::Value GetIntake() {
		//return intake->Get();
		return DoubleSolenoid::kOff;
	}

	void SetShooter(DoubleSolenoid::Value value) {
		//shooter->Set(value);
	}

	DoubleSolenoid::Value GetShooter() {
		//return shooter->Get();
		return DoubleSolenoid::kOff;
	}

	void StartCompressor() {
		//compressor->Start();
	}

	void StopCompressor() {
		//compressor->Stop();
	}
};