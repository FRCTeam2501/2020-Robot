#include "Intake/ToggleDeployIntake.h"

ToggleDeployIntake::ToggleDeployIntake(Intake* subsystem)
: intake(subsystem) {
    AddRequirements(subsystem);
}

void ToggleDeployIntake::Initialize() {
    intake->ToggleDeploy();
}
