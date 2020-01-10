/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Drivetrain.h"


Drivetrain::Drivetrain() {
frontLeft = new PWMVictorSPX(PWM::LEFT_FRONT);
frontRight = new PWMVictorSPX(PWM::RIGHT_FRONT);
rearLeft = new PWMVictorSPX(PWM::LEFT_REAR);
rearRight = new PWMVictorSPX(PWM::RIGHT_REAR);

xSpeed = new double (0.0);
ySpeed = new double (0.0);



}


Drivetrain::~Drivetrain() {
    delete frontLeft;
    delete frontRight;
    delete rearLeft;
    delete rearRight;
    delete xSpeed;
    delete ySpeed;
// Deleets stuf to not be like Google Chrome
}
double Drivetrain::getXSpeed(){
    return xSpeed;
}

double Drivetrain::getXspeed(){
    return xSpeed;
}

