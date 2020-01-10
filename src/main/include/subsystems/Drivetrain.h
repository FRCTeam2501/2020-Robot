/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
#include "utils/include.h"

#include <frc2/command/SubsystemBase.h>
using namespace frc;

class Drivetrain : public frc2::SubsystemBase {
 public:
  Drivetrain();
  ~Drivetrain();
  void set (double x, double y);

  double getXSpeed();
  double getYSpeed();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();

 private:


  PWMVictorSPX *frontLeft , *frontRight , *rearLeft , * rearRight;

  double *xSpeed, *ySpeed;

  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
