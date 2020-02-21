#include "Classes/RGB.h"


RGB::RGB(Drivetrain *drivetrain, Climber *climber, Intake *intake, Shooter *shooter) {
	//Grab state pointers from all subsystems
	driveLeft = drivetrain->GetLeft();
	driveRight = drivetrain->GetRight();

	climbArm = climber->GetArmState();
	climbWinch = climber->GetWinchState();
	climbRun = climber->GetRunState();
	climbSpeed = climber->GetWinchSpeed();

	shooterSpeed = shooter->GetSetpoint();
	shooterOn = shooter->GetOn();


	leds = new frc::AddressableLED(PORTS::PWM::RGB);

	leds->SetLength(CONSTANTS::RGB::LENGTH);
	leds->SetData(ledData);
	leds->Start();
}

RGB::~RGB() {
	leds->Stop();

	delete leds;
}

frc::Color8Bit RGB::GetAllianceColor() {
	switch(frc::DriverStation::GetInstance().GetAlliance()) {
		case frc::DriverStation::Alliance::kRed:
			return frc::Color::kRed;
		case frc::DriverStation::Alliance::kBlue:
			return frc::Color::kBlue;
		case frc::DriverStation::Alliance::kInvalid:
		default:
			return CONSTANTS::RGB::ERROR;
	}
}

void RGB::SetLEDsPercent(uint32_t start, uint32_t end, frc::Color8Bit color, double percentLength) {
	uint32_t i = start, length = end - start;
	while(i < ((percentLength * length) + start) && i < end) {
		ledData[i].SetLED(color);
		i++;
	}
	while(i < end) {
		ledData[i].SetLED(frc::Color::kBlack);
	}
}

void RGB::SetLEDsPercentReverse(uint32_t start, uint32_t end, frc::Color8Bit color, double percentLength) {
	uint32_t i = end, length = end - start;
	while(i > end - ((percentLength * length)) && i >= start) {
		ledData[i].SetLED(color);
		i--;
	}
	while(i >= start) {
		ledData[i].SetLED(frc::Color::kBlack);
	}
}

void RGB::Periodic() {
	RunDrivetrain();
	RunClimber();
	RunShooter();
}

void RGB::RunDrivetrain() {
	if(frc::DriverStation::GetInstance().IsEnabled()) {
		if(frc::DriverStation::GetInstance().IsOperatorControl()) {
			//Change drivetrain RGB length depending on that side's speed, color depends on match type and alliance
			frc::Color color;
			switch(frc::DriverStation::GetInstance().GetMatchType()) {
				case frc::DriverStation::MatchType::kElimination:
					color = GetAllianceColor();
					break;
				case frc::DriverStation::MatchType::kQualification:
					color = Multiply(GetAllianceColor(), CONSTANTS::RGB::DISABLED);
					break;
				case frc::DriverStation::MatchType::kPractice:
					color = frc::Color::kPurple;
					break;
				case frc::DriverStation::MatchType::kNone:
				default:
					color = CONSTANTS::RGB::ERROR;
					break;
			}
			SetDrivetrain(color, *driveLeft, *driveRight);
		}
		else if(frc::DriverStation::GetInstance().IsAutonomous()) {
			SetDrivetrain(frc::Color::kWhite, *driveLeft, *driveRight);
		}
		else {
			SetDrivetrain(CONSTANTS::RGB::ERROR, 1.0, 1.0);
		}
	}
	else {
		SetDrivetrainDisabled();
	}
}

void RGB::RunClimber() {
	//Change climber arm RGB length depending on state
	switch(*climbArm) {
		case Climber::DOWN:
			SetClimbArm(0.25);
			break;
		case Climber::UP:
			SetClimbArm(0.5);
			break;
		case Climber::EXTEND:
			SetClimbArm(0.75);
			break;
		case Climber::RETRACT:
			SetClimbArm(1.0);
			break;
		case Climber::DEFAULT:
		default:
			SetClimbArm(0.125);
			break;
	}

	//Change climber winch RGB length depending on state, side depends on which side is engaged
	double climbPercent = 0.0;
	switch(*climbRun) {
		case Climber::FORWARD:
			climbPercent = 1.0;
			break;
		case Climber::REVERSE:
			climbPercent = 0.25;
			break;
		case Climber::OFF:
		default:
			climbPercent = 0.5;
			break;
	}
	switch(*climbWinch) {
		case Climber::LEFT:
			SetClimbWinch(climbPercent, 0.0);
			break;
		case Climber::RIGHT:
			SetClimbWinch(0.0, climbPercent);
			break;
		case Climber::BOTH:
		default:
			SetClimbWinch(climbPercent, climbPercent);
			break;
	}
}

void RGB::RunIntake() {

}

void RGB::RunShooter() {
	//Change shooter RGB length depending on speed, color depends on enabled mode
	SetShooter((*shooterOn ? GetAllianceColor() : CONSTANTS::RGB::DISABLED), (*shooterSpeed / CONSTANTS::SHOOTER::MAX_SPEED).to<double>());
}