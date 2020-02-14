#include "Intake/Intake.h"

Intake::Intake(Pneumatics *pneumatics) {
    intakeWheel = new WPI_TalonSRX(CAN::INTAKE_RIGHT);
    intakeWheel2 = new WPI_TalonSRX(CAN::INTAKE_LEFT);
    pneumatics = new Pneumatics();

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