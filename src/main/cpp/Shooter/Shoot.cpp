#include "Shooter/Shoot.h"

Shoot::Shoot(Shooter* subsystem)
: shoot(subsystem) {
    AddRequirements(subsystem);
}

void Shoot::Initialize() {
    shoot->FlyWheelSet(ShooterConstants::ShootConst);
}


