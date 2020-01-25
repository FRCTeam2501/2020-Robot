#include "Drivetrain/Drivetrain.h"
#include "Utils/include.h"

void Drivetrain::Periodic(){}

Drivetrain::Drivetrain() {

    frontLeft = new PWMVictorSPX(DriveConstants::kLeftMotor1Port);
    frontRight = new PWMVictorSPX(DriveConstants::kRightMotor1Port);
    rearLeft = new PWMVictorSPX(DriveConstants::kLeftMotor2Port);
    rearRight = new PWMVictorSPX(DriveConstants::kRightMotor2Port);

    left = new SpeedControllerGroup(*frontLeft, *rearLeft);
    right = new SpeedControllerGroup(*frontRight, *rearRight);

    drive = new DifferentialDrive(*left, *right);
}
void Drivetrain::Switch(){
    direction!=direction;
}

Drivetrain::~Drivetrain() {

    delete frontLeft;
    delete frontRight;
    delete rearLeft;
    delete rearRight;

    delete left;
    delete right;

    delete drive;
}

void Drivetrain::ArcadeDrive(double x, double z){
    if(direction)
        x*=-1.0;
        
    drive->ArcadeDrive(x, z);
}