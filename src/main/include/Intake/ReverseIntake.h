#pragma once
#include "include.h"
#include "Intake/Intake.h"
using namespace frc;


class ReverseIntake
	: public frc2::CommandHelper<frc2::CommandBase, ReverseIntake> {
private:
	Intake *intake;

public:
	ReverseIntake(Intake *intake);
	void Initialize() override;
	void End(bool interrupted) override;
};