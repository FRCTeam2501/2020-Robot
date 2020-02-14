#include "Shooter/Shoot.h"

Shoot::Shoot(Shooter* subsystem)
: shoot(subsystem) {
    AddRequirements(shoot);
    wpi::outs() << "made\n";
}

void Shoot::Initialize() {
    shoot->ToggleShoot();
    wpi::outs() << "shoot\n";
}


