/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Drivetrain/SwitchDirection.h"

SwitchDirection::SwitchDirection() {
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void SwitchDirection::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void SwitchDirection::Execute() {}

// Called once the command ends or is interrupted.
void SwitchDirection::End(bool interrupted) {}

// Returns true when the command should end.
bool SwitchDirection::IsFinished() { return false; }
