#pragma once
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/TimedRobot.h>
#include <frc/XboxController.h>
#include <frc/Joystick.h>
#include <frc/Encoder.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/Compressor.h>
#include <frc/DoubleSolenoid.h>
#include <frc/DigitalInput.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/livewindow/LiveWindow.h>
#include <frc/kinematics/DifferentialDriveKinematics.h>
#include <frc/kinematics/DifferentialDriveOdometry.h>
#include <frc/AddressableLED.h>
#include <frc/DriverStation.h>

#include <frc2/command/CommandScheduler.h>
#include <frc2/command/button/JoystickButton.h>
//#include <frc2/command/button/POVButton.h>
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

#include <units/units.h>
#include <hal/HAL.h>
#include <cameraserver/CameraServer.h>
#include "vision/VisionRunner.h"

#include "ctre/Phoenix.h"
//  http://devsite.ctr-electronics.com/maven/release/com/ctre/phoenix/Phoenix-latest.json
#include "rev/CANSparkMax.h"
//  https://www.revrobotics.com/content/sw/max/sdk/REVRobotics.json
#include "libcu/lasershark.h"
//  https://copperforge.cc/dev/files/vendordeps/LibCu-latest.json


#include "Utils/constants.h"
#include "Utils/ports.h"
#include "Utils/buttonMap.h"

#define cout wpi::outs()