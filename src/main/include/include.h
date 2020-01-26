#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/TimedRobot.h>
#include <frc/XboxController.h>
#include <frc/Joystick.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/Encoder.h>
#include <frc/PWMVictorSPX.h>
#include <frc/SpeedControllerGroup.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/Compressor.h>
#include <frc/DoubleSolenoid.h>

#include <frc2/command/CommandScheduler.h>
#include <frc2/command/button/JoystickButton.h>
#include <frc2/command/Command.h>
#include <frc2/command/Command.h>
#include <frc2/command/SubsystemBase.h>
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc2/command/InstantCommand.h>

#include "ctre/Phoenix.h"
#include "rev/CANSparkMax.h"

#include "constants.h"
#include "ports.h"
#include "buttonMap.h"

#define cout wpi::outs()