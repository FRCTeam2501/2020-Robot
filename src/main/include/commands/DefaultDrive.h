#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/DriveSubsystem.h"


class DefaultDrive
    : public frc2::CommandHelper<frc2::CommandBase, DefaultDrive> {
public:
	DefaultDrive(DriveSubsystem* subsystem, std::function<double()> forward,
			std::function<double()> rotation);
	void Execute() override;
private:
	DriveSubsystem* drive;
	std::function<double()> forward;
	std::function<double()> rotation;
};