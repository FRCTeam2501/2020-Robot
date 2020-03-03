#include "subsystem/climber/variablespeed.h"

using namespace frc;

VariableSpeed::VariableSpeed(Climber* subsystem,
 std::function<double()> speed) : climber(subsystem), speed(speed) {
    AddRequirements(subsystem);
}

void VariableSpeed::Execute() {
  climber->SetSpeed(speed());
}