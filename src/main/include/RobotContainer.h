#pragma once

#include "include.h"
#include "Subsystems/Drivetrain.h"
#include "Drivetrain/SwitchDirection.h"
#include "Drivetrain/ManualDrive.h"

#include "Classes/Pneumatics.h"

#include "Subsystems/Intake.h"
#include "Intake/IntakeSpeed.h"

#include "Subsystems/Shooter.h"

#include "Subsystems/Climber.h"
#include "Climber/VariableSpeed.h"

#include "Subsystems/Hopper.h"

using namespace frc;

class RobotContainer {
 public:

  RobotContainer();
  ~RobotContainer();

  void Periodic();
  frc2::Command *GitAutoCommand();
  
 private:
  Drivetrain *drive;
  Joystick *driveStick, *controlStick;
  Climber *climber;
  frc2::JoystickButton *switchDirection,
                       *ShootTrigger,
                       *intakeDeployButton, *intakeSet, *intakeReverse, *intakeRun,
                       *winchForward, *winchReverse, *winchSelect,
                       *evacHopper, *shootUp, *shootDown, *climbForward, *climbReverse, *runHopper;
  Pneumatics *pneu;
  Intake *intake;
  Shooter *shoot;
  Hopper *hopper;
};
