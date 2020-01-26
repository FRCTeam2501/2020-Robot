#pragma once
#include "include.h"
#include "Shooter/Shooter.h"
using namespace frc;


class ToggleShooter
	: public frc2::CommandHelper<frc2::InstantCommand, ToggleShooter> {
private:
	Shooter *shooter;

public:
	ToggleShooter(Shooter *shooter);
	void Initialize() override;
};