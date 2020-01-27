#include "subsystems/drivetrain.h"
#include "subsystems/Utils/include.h"

void Drivetrain::Periodic() {}

Drivetrain::Drivetrain() {
    
    frontLeft = new PWMVictorSPX(PWM::LEFT_FRONT);
    frontRight = new PWMVictorSPX(PWM::RIGHT_FRONT);
    rearLeft = new PWMVictorSPX(PWM::LEFT_REAR);
    rearRight = new PWMVictorSPX(PWM::RIGHT_REAR);

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