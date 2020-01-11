#include "Drivetrain/Drivetrain.h"


Drivetrain::Drivetrain() {
    drive = new DifferentialDrive(*left, *right);

    left = new SpeedControllerGroup(*frontLeft, *rearLeft);
    right = new SpeedControllerGroup(*frontRight, *rearRight);

    frontLeft = new PWMVictorSPX(PWM::LEFT_FRONT);
    rearLeft = new PWMVictorSPX(PWM::LEFT_REAR);
    frontRight = new PWMVictorSPX(PWM::RIGHT_FRONT);
    rearRight = new PWMVictorSPX(PWM::RIGHT_REAR);

    ySpeed = new double(0.0);
    rzSpeed = new double(0.0);
}

Drivetrain::~Drivetrain() {
    delete drive;

    delete left;
    delete right;

    delete frontLeft;
    delete frontRight;
    delete rearLeft;
    delete rearRight;

    delete ySpeed;
    delete rzSpeed;
}

void Drivetrain::SetSpeed(double y, double rz) {
    y = *ySpeed;
    rz = *rzSpeed;
}

double Drivetrain::GetYSpeed() {
    return *ySpeed;
}

double Drivetrain::GetRZSpeed() {
    return *rzSpeed;
}

void Drivetrain::Periodic() {
    drive->ArcadeDrive(*ySpeed, *rzSpeed);
}