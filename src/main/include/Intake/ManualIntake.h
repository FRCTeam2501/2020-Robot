#pragma once
#include "include.h"
#include "Intake/Intake.h"
using namespace frc;


class ManualIntake
	: public frc2::CommandHelper<frc2::CommandBase, ManualIntake> {
private:
	Intake *intake;
	std::function<double()> speed;

public:
	ManualIntake(Intake *intake, std::function<double()> speed);
	void Execute() override;
};