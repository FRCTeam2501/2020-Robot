#pragma once
#include "include.h"
#include "Subsystems/Drivetrain.h"
#include "Subsystems/Climber.h"
#include "Subsystems/Intake.h"
#include "Subsystems/Shooter.h"


class RGB : public frc::ErrorBase {
private:
	frc::AddressableLED *leds;
	std::array<frc::AddressableLED::LEDData, CONSTANTS::RGB::LENGTH> ledData;

	frc::Color8Bit GetAllianceColor();
	void SetLEDsPercent(uint32_t start, uint32_t end, frc::Color8Bit color, double percentLength, bool reverse = false);
	void RunDisabled();

	frc::Color8Bit Multiply(frc::Color8Bit base, frc::Color8Bit mask) {
		return frc::Color8Bit(base.red * mask.red / 255, base.green * mask.red / 255, base.blue * mask.blue / 255);
	}

	double *driveLeft, *driveRight;
	void RunDrivetrain();
	void SetDrivetrain(frc::Color8Bit color, double leftPercent, double rightPercent) {
		SetDrivetrainSide(CONSTANTS::RGB::DRIVETRAIN::START, CONSTANTS::RGB::DRIVETRAIN::LEFT_FRONT_END,
			CONSTANTS::RGB::DRIVETRAIN::LEFT_REAR_START, CONSTANTS::RGB::DRIVETRAIN::LEFT_END,
			color, leftPercent);
		SetDrivetrainSide(CONSTANTS::RGB::DRIVETRAIN::RIGHT_START, CONSTANTS::RGB::DRIVETRAIN::RIGHT_FRONT_END,
			CONSTANTS::RGB::DRIVETRAIN::RIGHT_REAR_START, CONSTANTS::RGB::DRIVETRAIN::END,
			color, rightPercent);
	}
	void SetDrivetrainSide(uint32_t front_start, uint32_t front_end, uint32_t rear_start, uint32_t rear_end, frc::Color8Bit color, double percentLength) {
		double frontPercent, rearPercent;
		if(percentLength > 0) {
			frontPercent = percentLength;
			rearPercent = 0.0;
		}
		else {
			frontPercent = 0.0;
			rearPercent = abs(percentLength);
		}
	
		SetLEDsPercent(front_start, front_end, color, frontPercent, true);
		SetLEDsPercent(rear_start, rear_end, color, rearPercent);
	}

	uint32_t *climbArm, *climbWinch, *climbRun;
	double *climbSpeed;
	void RunClimber();
	void SetClimbArm(double percentLength) {
		frc::Color8Bit color = GetAllianceColor();
		SetLEDsPercent(CONSTANTS::RGB::CLIMBER::START, CONSTANTS::RGB::CLIMBER::LEFT_ARM_END, color, percentLength);
		SetLEDsPercent(CONSTANTS::RGB::CLIMBER::RIGHT_ARM_START, CONSTANTS::RGB::CLIMBER::RIGHT_ARM_END, color, percentLength);
	}
	void SetClimbWinch(double leftPercent, double rightPercent) {
		frc::Color8Bit color = GetAllianceColor();
		SetLEDsPercent(CONSTANTS::RGB::CLIMBER::LEFT_WINCH_START, CONSTANTS::RGB::CLIMBER::LEFT_WINCH_END, color, leftPercent);
		SetLEDsPercent(CONSTANTS::RGB::CLIMBER::RIGHT_WINCH_START, CONSTANTS::RGB::CLIMBER::END, color, rightPercent);
	}

	bool *intakeRunning, *intakeInverted;
	double *intakeSpeed;
	void RunIntake();
	void SetIntake(frc::Color8Bit color, double percentLength) {
		SetLEDsPercent(CONSTANTS::RGB::INTAKE::START, CONSTANTS::RGB::INTAKE::LEFT_END, color, percentLength);
		SetLEDsPercent(CONSTANTS::RGB::INTAKE::RIGHT_START, CONSTANTS::RGB::INTAKE::END, color, percentLength);
	}

	units::angular_velocity::revolutions_per_minute_t *shooterSpeed;
	bool *shooterOn;
	void RunShooter();
	void SetShooter(frc::Color8Bit color, double percentLength) {
		SetLEDsPercent(CONSTANTS::RGB::SHOOTER::START, CONSTANTS::RGB::SHOOTER::LEFT_END, color, percentLength);
		SetLEDsPercent(CONSTANTS::RGB::SHOOTER::RIGHT_START, CONSTANTS::RGB::SHOOTER::END, color, percentLength);
	}

public:
	RGB(Drivetrain *drivetrain, Climber *climber, Intake *intake, Shooter *shooter);
	~RGB();

	void Periodic();
	void Start() {
		leds->Start();
	}
	void Stop() {
		leds->Stop();
	}
};