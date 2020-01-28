#include "subsystems/manualdrive.h"

using namespace frc;

manualdrive::manualdrive(Drivetrain* subsystem, 
std::function<double()> forward,
std::function<double()> rotation)
: drive(subsystem), forward(forward), rotation(rotation){
AddRequirements(subsystem);
}
  void manualdrive::Execute(){
drive->ArcadeDrive(forward(), rotation());}

