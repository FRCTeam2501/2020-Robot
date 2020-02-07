#include "subsystems/intake/IntakeSpeed.h"

using namespace frc;


IntakeSpeed::IntakeSpeed(Intake* subsystem, 
        std::function<double()>intakeRC)
        : intake(subsystem), intakeRC(intakeRC) {
        AddRequirements(subsystem);
        }

        void IntakeSpeed::Execute() { 
            intake->IntakeSpeed (intakeRC());
}