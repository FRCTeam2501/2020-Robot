#pragma once

#include <frc2/command/Command.h>
#include "frc/WPILib.h"

#include "Utils/include.h"
#include "Drivetrain/Drivetrain.h"
#include "Drivetrain/SwitchDirection.h"
#include "Drivetrain/ManualDrive.h"

#include "Cameras/Cameras.h"

#include "Pneumatics/Pneumatics.h"
#include "Pneumatics/TogglePneu.h"
#include "Pneumatics/TogglePneu2.h"

#include "Intake/Intake.h"
#include "Intake/IntakeSpeed.h"
#include "Intake/ToggleDeployIntake.h"

#include "Shooter/Shooter.h"
#include "Shooter/Shoot.h"

#include "Climber/Climber.h"

using namespace frc;

class RobotContainer {
 public:

  RobotContainer();
  ~RobotContainer();

  void Periodic();
  
 private:
  bool state = false;
  Drivetrain *drive;
  Joystick *driveStick, *controlStick;
  //Cameras *cameras;
  frc2::JoystickButton *switchDirection, *Pneumatics1, *Pneumatics2,
                       *ShootTrigger,
                       *intakeDeployButton, *intakeSet;
  Pneumatics *pneu;
  Intake *intake;
  Shooter *shoot;
};
