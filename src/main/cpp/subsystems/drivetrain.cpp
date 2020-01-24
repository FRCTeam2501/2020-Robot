#include "subsystems/drivetrain.h"
#include "subsystems/Utils/include.h"

void Drivetrain::Periodic() {}

Drivetrain::Drivetrain() {
    
    frontLeft = new PWMVictorSPX(PWM::FRONT_LEFT);
    frontRight = new PWMVictorSPX(PWM::FRONT_RIGHT);
    rearLeft = new PWMVictorSPX(PWM::REAR_LEFT);
    rearRight = new PWMVictorSPX(PWM::REAR_RIGHT);

    left = new SpeedControllerGroup(*frontLeft, *rearLeft); 
    right = new SpeedControllerGroup(*frontRight, *rearRight);

    drive = new DifferentialDrive(*left, *right); 
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

void Drivetrain :: ArcadeDrive (double x, double z){
    drive->ArcadeDrive(x,z);
}