#include "Drivetrain/Drivetrain.h"
#include "Utils/include.h"

void Drivetrain::Periodic(){}

Drivetrain::Drivetrain() {

    frontLeft = new rev::CANSparkMax(CAN::LEFT_FRONT, rev::CANSparkMax::MotorType::kBrushless);
    frontRight = new rev::CANSparkMax(CAN::RIGHT_FRONT, rev::CANSparkMax::MotorType::kBrushless);
    rearLeft = new rev::CANSparkMax(CAN::LEFT_REAR, rev::CANSparkMax::MotorType::kBrushless);
    rearRight = new rev::CANSparkMax(CAN::RIGHT_REAR, rev::CANSparkMax::MotorType::kBrushless);

    rearLeft->Follow(*frontLeft);
    rearRight->Follow(*frontRight);

    frontLeft->SetSmartCurrentLimit(60);
    frontRight->SetSmartCurrentLimit(60);
    rearLeft->SetSmartCurrentLimit(60);
    rearRight->SetSmartCurrentLimit(60);

    drive = new DifferentialDrive(*frontLeft, *frontRight);
}
void Drivetrain::Switch(){
    direction=!direction;
}

Drivetrain::~Drivetrain() {

    delete frontLeft;
    delete frontRight;
    delete rearLeft;
    delete rearRight;

    delete drive;
}

void Drivetrain::ArcadeDrive(double x, double z){
    if(direction)
        x*=-1.0;
        
    drive->ArcadeDrive(x, z);
}