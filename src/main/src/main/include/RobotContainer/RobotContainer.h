#pragma once

#include <frc2/command/Command.h>
#include "frc/WPILib.h"

#include "include.h"
#include "Subsystems/Drivetrain.h"
#include "Subsystems/SwitchDirection.h"
#include "Subsystems/ManualDrive.h"

#include "Classes/Cameras.h"

#include "Classes/Pneumatics.h"
#include "Classes/TogglePneu.h"
#include "Classes/TogglePneu2.h"

#include "Subsystems/Intake.h"
#include "Subsystems/IntakeSpeed.h"
#include "Subsystems/ToggleDeployIntake.h"

#include "Subsystems/Shooter.h"
#include "Subsystems/Shoot.h"

#include "Subsystems/Climber.h"
#include "Subsystems/VariableSpeed.h"

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
  Cameras *cameras;
  Climber *climber;
  frc2::JoystickButton *switchDirection, *Pneumatics1, *Pneumatics2,
                       *ShootTrigger,
                       *intakeDeployButton, *intakeSet,
                       *winchForward, *winchReverse;
  Pneumatics *pneu;
  Intake *intake;
  Shooter *shoot;
};
