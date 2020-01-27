/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/RobotContainer.h"
using namespace frc;



Drivetrain::Drivetrain() {
frontLeft = new PWMVictorSPX(PWM::LEFT_FRONT);
frontRight = new PWMVictorSPX(PWM::RIGHT_FRONT);
rearLeft = new PWMVictorSPX(PWM::LEFT_REAR);
rearRight = new PWMVictorSPX(PWM::RIGHT_REAR);

left = new SpeedControllerGroup (*frontLeft, *rearLeft);
right = new SpeedControllerGroup(*frontRight, *rearRight);

drive = new DifferentialDrive (*left, *right);
}


Drivetrain::~Drivetrain() {
    delete frontLeft;
    delete frontRight;
    delete rearLeft;
    delete rearRight;
    delete left;
    delete right;
    delete drive;
// Deleets stuf to not be like Google Chrome
}

void Drivetrain::Periodic() {}


void Drivetrain::ArcadeDrive(double x, double y){

drive->ArcadeDrive(x, y);


}




