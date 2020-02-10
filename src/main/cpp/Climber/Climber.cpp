#include "Climber/Climber.h"


Climber::Climber(Pneumatics *pneumatics) : pneumatics(pneumatics) {
	left = new rev::CANSparkMax(CAN::CLIMBER_LEFT, rev::CANSparkMax::MotorType::kBrushless);
	right = new rev::CANSparkMax(CAN::CLIMBER_RIGHT, rev::CANSparkMax::MotorType::kBrushless);

	left->RestoreFactoryDefaults();
	left->SetSmartCurrentLimit(CONSTANTS::SHOOTER::CURRENT_LIMIT.to<double>());
	left->SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
	right->RestoreFactoryDefaults();
	right->SetSmartCurrentLimit(CONSTANTS::SHOOTER::CURRENT_LIMIT.to<double>());
	right->SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);

	right->Follow(*left);

	speed = new double(0.0);
	state = new uint8_t(OFF);
	enabled = new bool(false);
	changed = new bool(false);

	cout << "Climber Subsystem Booted!\n";
}

Climber::~Climber() {
	delete right;
	delete left;

	delete speed;
	delete state;
	delete enabled;
	delete changed;
}

void Climber::Periodic() {
	if(*changed) {
		if(!(*enabled && *state == RETRACT)) {
			*speed = 0.0;
		}

		left->Set(*speed);

		frc::SmartDashboard::PutNumber("Speed", *speed);
	}
}

void Climber::SetWinch(double speed) {
	*Climber::speed = speed;
	*changed = true;
}

void Climber::Forward() {
	if(!*enabled)
		return;

	switch(*state) {
		case OFF:
		case DOWN:
			SetArm(true);
			*changed = true;
			*state = UP;
			break;
		case UP:
			SetExtend(true);
			*changed = true;
			*state = EXTEND;
			break;
		case EXTEND:
			SetExtend(false);
			*changed = true;
			*state = RETRACT;
			break;
		case RETRACT:
			SetArm(false);
			*changed = true;
			*state = DOWN;
			break;
		default:
			cout << "Climber in illegal state!";
			break;
	}
}

void Climber::Reverse() {
	if(!*enabled)
		return;

	switch(*state) {
		case OFF:
		case DOWN:
			SetArm(true);
			*changed = true;
			*state = UP;
			break;
		case UP:
			SetArm(false);
			*changed = true;
			*state = DOWN;
			break;
		case EXTEND:
			SetExtend(false);
			*changed = true;
			*state = RETRACT;
			break;
		case RETRACT:
			SetExtend(true);
			*changed = true;
			*state = EXTEND;
			break;
		default:
			cout << "Climber in illegal state!";
			break;
	}
}

void Climber::SetArm(bool up) {
	if(up) {
		pneumatics->SetClimbArm(frc::DoubleSolenoid::kForward);
	}
	else {
		pneumatics->SetClimbArm(frc::DoubleSolenoid::kReverse);
	}
}

void Climber::SetExtend(bool extend) {
	if(extend) {
		pneumatics->SetClimbExtend(frc::DoubleSolenoid::kForward);
	}
	else {
		pneumatics->SetClimbExtend(frc::DoubleSolenoid::kReverse);
	}
}