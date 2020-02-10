#pragma once
#include "include.h"
#include "Drivetrain/Drivetrain.h"


class ManualDrive
    : public frc2::CommandHelper<frc2::CommandBase, ManualDrive> {
private:
	Drivetrain* drive;
	std::function<double()> y;
	std::function<double()> rz;

public:
	ManualDrive(Drivetrain* drive, std::function<double()> y,
			std::function<double()> rz);
	void Execute() override;
};