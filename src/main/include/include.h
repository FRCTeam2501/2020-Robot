#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/TimedRobot.h>
#include <frc/XboxController.h>
#include <frc/Joystick.h>
#include <frc/Encoder.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/Compressor.h>
#include <frc/DoubleSolenoid.h>
#include <frc/DigitalInput.h>

#include <frc2/command/CommandScheduler.h>
#include <frc2/command/button/JoystickButton.h>
#include <frc2/command/Command.h>
#include <frc2/command/SubsystemBase.h>
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc2/command/InstantCommand.h>

#include <frc2/command/StartEndCommand.h>
#include <frc2/command/WaitCommand.h>
#include <frc2/command/WaitUntilCommand.h>
#include <frc2/command/ParallelRaceGroup.h>
#include <frc2/command/ParallelDeadlineGroup.h>
#include <frc2/command/SequentialCommandGroup.h>

#include "ctre/Phoenix.h"
#include "rev/CANSparkMax.h"

#include "Utils/constants.h"
#include "Utils/ports.h"
#include "Utils/buttonMap.h"

#define cout wpi::outs()