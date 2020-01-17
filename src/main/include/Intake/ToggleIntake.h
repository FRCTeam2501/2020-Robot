#pragma once
#include "include.h"
#include "Intake/Intake.h"
using namespace frc;


class ToggleIntake
	: public frc2::CommandHelper<frc2::InstantCommand, ToggleIntake> {
private:
	Intake *intake;

public:
	ToggleIntake(Intake *intake);
	void Initialize() override;
};