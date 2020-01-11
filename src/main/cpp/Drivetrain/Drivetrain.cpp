#include "Utils/include.h"
#include "Drivetrain/Drivetrain.h"
#include "Robot.h"

Drivetrain::Drivetrain() {
    frontLeft = new PWMVictorSPX(PWM::LEFT_FRONT);
    frontRight = new PWMVictorSPX(PWM::RIGHT_FRONT);
    rearLeft = new PWMVictorSPX(PWM::LEFT_REAR);
    rearRight = new PWMVictorSPX(PWM::RIGHT_REAR);

    left = new SpeedControllerGroup(*frontLeft, *rearLeft);
    right = new SpeedControllerGroup(*frontRight, *rearRight);

    drive = new DifferentialDrive(*left, *right);

    xSpeed = new double (0.0);
    zSpeed = new double (0.0);

    Register();
}

Drivetrain::~Drivetrain(){
    delete frontLeft;
    delete frontRight;
    delete rearLeft;
    delete rearRight;
    delete xSpeed;
    delete zSpeed;
    delete left;
    delete right;
    delete drive;
}

void Drivetrain::setSpeed(double x, double z){
    drive->ArcadeDrive(x, z);
        *zSpeed = z;
        *xSpeed = x;
        cout << "setspeed\n";
}

double Drivetrain::getXSpeed(){
    return *xSpeed;
}
double Drivetrain::getZSpeed(){
    return *zSpeed;
}

void Drivetrain::Periodic() {
    drive->ArcadeDrive(Robot::oi->getXSpeed(), Robot::oi->getZSpeed());
  cout << "PERIODIC\n";
}