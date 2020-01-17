/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include "utils/include.h"

using namespace frc;

class Drivetrain : public frc2::SubsystemBase {
 public:
  Drivetrain();
  ~Drivetrain();
  
  
  void ArcadeDrive( double x, double y);
  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
 void Periodic();

 private:


  PWMVictorSPX *frontLeft , *frontRight , *rearLeft , * rearRight;

  SpeedControllerGroup *left, *right;
  DifferentialDrive *drive; 

  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
