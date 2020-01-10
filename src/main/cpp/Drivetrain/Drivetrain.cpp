#include "Utils/include.h"
#include "Drivetrain/Drivetrain.h"

Drivetrain::Drivetrain() {
    frontLeft = new PWMVictorSPX(PWM::LEFT_FRONT);
    frontRight = new PWMVictorSPX(PWM::RIGHT_FRONT);
    rearLeft = new PWMVictorSPX(PWM::LEFT_REAR);
    rearRight = new PWMVictorSPX(PWM::RIGHT_REAR);

    xSpeed = new double (0.0);
    zSpeed = new double (0.0);
}

Drivetrain::~Drivetrain(){
    delete frontLeft;
    delete frontRight;
    delete rearLeft;
    delete rearRight;
    delete xSpeed;
    delete zSpeed; //a
}

void Drivetrain::setSpeed(double x, double z){
    drive->ArcadeDrive(x, z);
        z = *zSpeed;
        x = *xSpeed;
}

double Drivetrain::getXSpeed(){
    return *xSpeed;
}
double Drivetrain::getZSpeed(){
    return *zSpeed;
}

void Drivetrain::Periodic() {}