#pragma once

#include "Utils/include.h"

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