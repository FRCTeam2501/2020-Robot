#include "Drivetrain/ManualDrive.h"
using namespace frc;

ManualDrive::ManualDrive( Drivetrain* subsystem,
std::function<double()> y, 
std::function<double()> x) 
: drive(subsystem),y(y),x(x){
    AddRequirements(subsystem);

}


void ManualDrive::Execute(){

drive->ArcadeDrive(y(), x());

}

