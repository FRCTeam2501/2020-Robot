

#include "RobotContainer.h"
#include "Constants.h"
#include "frc2/command/ParallelRaceGroup.h"
#include "subsystems/drivetrain.h"

RobotContainer::RobotContainer() : m_autonomousCommand(&m_subsystem) {
   //Initialize all of your commands and subsystems here

  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
}

frc2::Command* RobotContainer::GetAutonomousCommand() {

  return &m_autonomousCommand;
}
RobotContainer::RobotContainer() {
  stick = new frc::Joystick(JOYSTICK::STICK);

switchDirection = new frc2::JoystickButton(driveStick, JOYSTICK::THUMB);
	
	switchDirection->WhenPressed(new SwitchDirection(drive));

	Pneumatics1 = new frc2::JoystickButton(driveStick, JOYSTICK::BUTTON_8);

	Pneumatics1->WhenPressed(new ToggleVert(pneu));

	Pneumatics2 = new frc2::JoystickButton(driveStick, JOYSTICK::BUTTON_9);

	Pneumatics2->WhenPressed(new ToggleClimb(pneu));

	ShootTrigger = new frc2::JoystickButton(driveStick, JOYSTICK::TRIGGER);

	ShootTrigger->WhenPressed(new Shoot(shoot));

	intakeDeployButton = new frc2::JoystickButton(controlStick, JOYSTICK::BUTTON_8);

	intakeDeployButton->WhenPressed(new ToggleDeployIntake(intake));

  intaketoggle = new frc2::JoystickButton(driveStick, JOYSTICK::BUTTON_4);
  
  intaketoggle->WhenPressed(new intaketoggle(intake);

	winchForward = new frc2::JoystickButton(controlStick, JOYSTICK::BUTTON_6);
	winchForward->ToggleWhenPressed(new frc2::StartEndCommand(
		[this]{
			climber->ToggleWinchOn();
		},
		[this]{
			climber->ToggleWinchOff();
		},
		{climber}
	));

	winchReverse = new frc2::JoystickButton(controlStick, JOYSTICK::BUTTON_4);
	winchReverse->ToggleWhenPressed(new frc2::StartEndCommand(
		[this]{
			climber->ToggleWinchDownOn();
		},
		[this]{
			climber->ToggleWinchDownOff();
		},
		{climber}
	));

	climber->SetDefaultCommand(VariableSpeed(
		  climber,
		  [this] { return (controlStick->GetRawAxis(JOYSTICK::Z)+1)/2;}
	));
}
RobotContainer::~RobotContainer(){
	delete drive;
	delete driveStick;
	delete cameras;
	delete switchDirection;
	delete intake;
	delete winchForward;
	delete winchReverse;
}
