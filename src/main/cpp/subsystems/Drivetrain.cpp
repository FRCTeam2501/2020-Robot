#include "Drivetrain/Drivetrain.h"
void Drivetrain :: Periodic(){}
Drivetrain::Drivetrain(){
frontLeft= new PWMVictorSPX(DriveConstants::kLeftMotor1Port);
rearLeft = new PWMVictorSPX(DriveConstants::kLeftMotor2Port);
frontRight=new PWMVictorSPX(DriveConstants::kRightMotor1Port);
rearRight=new PWMVictorSPX(DriveConstants::kRightMotor2Port);

left = new SpeedControllerGroup(*frontLeft, *rearLeft);
right = new SpeedControllerGroup(*frontRight, *rearRight);

drive = new DifferentialDrive(*left, *right);
}
Drivetrain::~Drivetrain() {
 delete frontLeft;
 delete rearLeft;
 delete rearRight;
 delete frontRight;
 delete left;
 delete right;
 delete drive;  
}
void Drivetrain :: ArcadeDrive(double x, double z) {
drive->ArcadeDrive(x, z);
}
