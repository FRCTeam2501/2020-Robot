#include "include.h"
#include "Drivetrain/Drivetrain.h"
#pragma once
using namespace frc;


class ManualDrive
    : public frc2::CommandHelper<frc2::CommandBase, ManualDrive> {
private:
	Drivetrain *drive;
	std::function<double()> y;
	std::function<double()> rz;
public:
	ManualDrive(Drivetrain *drive,
				std::function<double()> y,
            	std::function<double()> rz);
	~ManualDrive();
	void Initialize() override;
	void Execute() override;
	void End(bool interrupted) override;
	bool IsFinished() override;
};