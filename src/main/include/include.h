#pragma once

#include "frc/WPILib.h"

#include "frc2/command/SubsystemBase.h"
#include "frc2/command/CommandScheduler.h"
#include "frc2/command/CommandHelper.h"
#include "frc2/command/CommandBase.h"

#include "ctre/Phoenix.h"

#include <time.h>

#include "Utils/ports.h"
#include "Utils/constants.h"
#include "Utils/buttonmap.h"

#define cout wpi::outs()