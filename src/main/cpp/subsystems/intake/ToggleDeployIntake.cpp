#include "subsystems/intake/ToggleDeployIntake.h"

ToggleDeployIntake::ToggleDeployIntake(Intake*subsystem)
: intake(subsystem) { 
    AddRequirements (intake);
} 

void ToggleDeployIntake::Initialize() { 
    intake->Toggledeploy();

}