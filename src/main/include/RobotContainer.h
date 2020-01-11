#include "include.h"
#include "Drivetrain/Drivetrain.h"
#pragma once
using namespace frc;


class RobotContainer {
private:
	Joystick *driveStick;
public:
    Drivetrain *drive;

    RobotContainer();
    ~RobotContainer();

    double GetYSpeed();
    double GetRZSpeed();
};