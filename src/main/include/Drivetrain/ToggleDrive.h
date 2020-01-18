#pragma once
#include "include.h"
#include "Drivetrain/Drivetrain.h"
using namespace frc;


class ToggleDrive
	: public frc2::CommandHelper<frc2::InstantCommand, ToggleDrive> {
private:
	Drivetrain *drive;

public:
	ToggleDrive(Drivetrain *drive);
	void Initialize() override;
};