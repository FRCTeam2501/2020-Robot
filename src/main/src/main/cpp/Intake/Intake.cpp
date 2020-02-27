#include "Subsystems/Intake.h"

Intake::Intake(Pneumatics *pneumatics) {
    intakeWheel = new WPI_TalonSRX(CAN::INTAKE);

}
Intake::~Intake() {
    delete intakeWheel;
}
void Intake::IntakeSpeed(double IntakeSet){
    intakeWheel->Set(IntakeSet);
}
void Intake::ToggleDeploy(){
    pneumatics->ToggleIntake();
}