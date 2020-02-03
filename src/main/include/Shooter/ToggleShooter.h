#pragma once
#include "include.h"
#include "Shooter/Shooter.h"
using namespace frc;


class ToggleShooter
	: public frc2::CommandHelper<frc2::CommandBase, ToggleShooter> {
private:
	Shooter *shooter;

public:
	explicit ToggleShooter(Shooter *shooter);
	void Initialize() override;
	bool IsFinished() override {
		return true;
	}
};