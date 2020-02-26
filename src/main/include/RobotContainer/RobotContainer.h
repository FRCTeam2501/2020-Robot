#pragma once

#include "Utils/include.h"
#include "Drivetrain/Drivetrain.h"
#include "Drivetrain/SwitchDirection.h"
#include "Drivetrain/ManualDrive.h"

#include "Pneumatics/Pneumatics.h"

#include "Intake/Intake.h"
#include "Intake/IntakeSpeed.h"

#include "Shooter/Shooter.h"

#include "Climber/Climber.h"
#include "Climber/VariableSpeed.h"

#include "Hopper/Hopper.h"

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
  frc2::JoystickButton *switchDirection, *Pneumatics1, *Pneumatics2,
                       *ShootTrigger,
                       *intakeDeployButton, *intakeSet, *intakeReverse, *intakeRun,
                       *winchForward, *winchReverse, *winchSelect,
                       *evacHopper, *shootUp, *shootDown, *climbForward, *climbReverse, *runHopper;
  Pneumatics *pneu;
  Intake *intake;
  Shooter *shoot;
  Hopper *hopper;
};
