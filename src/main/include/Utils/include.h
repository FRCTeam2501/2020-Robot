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
#include <frc/DoubleSolenoid.h>
#include <frc/Compressor.h>
#include <frc/Servo.h>

#include <frc2/command/CommandScheduler.h>
#include <frc2/command/button/JoystickButton.h>
#include <frc2/command/Command.h>
#include <frc2/command/Command.h>
#include <frc2/command/SubsystemBase.h>
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc2/command/InstantCommand.h>

#include "Utils/Constants.h"
#include "Utils/ButtonMap.h"
#include "Utils/ports.h"

#include "rev/CANSparkMax.h"
#include "rev/CANPIDController.h"
#include "rev/CANEncoder.h"

#include "ctre/Phoenix.h"