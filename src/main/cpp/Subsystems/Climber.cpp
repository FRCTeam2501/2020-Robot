#include "Subsystems/Climber.h"


Climber::Climber(Pneumatics *pneumatics) : pneumatics(pneumatics) {
	left = new rev::CANSparkMax(PORTS::CAN::CLIMBER_LEFT, rev::CANSparkMax::MotorType::kBrushless);
	right = new rev::CANSparkMax(PORTS::CAN::CLIMBER_RIGHT, rev::CANSparkMax::MotorType::kBrushless);

	left->RestoreFactoryDefaults();
	left->SetSmartCurrentLimit(CONSTANTS::SHOOTER::CURRENT_LIMIT.to<double>());
	left->SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
	right->RestoreFactoryDefaults();
	right->SetSmartCurrentLimit(CONSTANTS::SHOOTER::CURRENT_LIMIT.to<double>());
	right->SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);

	winchSpeed = new double(0.0);
	armState = new uint32_t(DEFAULT);
	winchState = new uint32_t(BOTH);
	runState = new uint32_t(OFF);
	changed = new bool(false);

	cout << "Climber Subsystem Booted!\n";
}

Climber::~Climber() {
	delete right;
	delete left;

	delete winchSpeed;
	delete armState;
	delete winchState;
	delete runState;
	delete changed;
}

void Climber::Periodic() {
	if(*changed) {
		if((*armState == RETRACT)) {
			double speed = 0.0;
			switch(*runState) {
				case FORWARD:
					speed = *winchSpeed;
					break;
				case REVERSE:
					speed = *winchSpeed * -1.0;
					break;
				case OFF:
				default:
					break;
			}
			switch(*winchState) {
				case LEFT:
					left->Set(speed);
					right->Set(0.0);
					break;
				case RIGHT:
					left->Set(0.0);
					right->Set(speed);
					break;
				case BOTH:
				default:
					left->Set(speed);
					right->Set(speed);
					break;
			}
		}
		else {
			left->Set(0.0);
			right->Set(0.0);
		}
	}
	*changed = false;
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

void Climber::ForwardArmState() {
	switch(*armState) {
		case DEFAULT:
		case DOWN:
			SetArm(true);
			*changed = true;
			*armState = UP;
			break;
		case UP:
			SetExtend(true);
			*changed = true;
			*armState = EXTEND;
			break;
		case EXTEND:
			SetExtend(false);
			*changed = true;
			*armState = RETRACT;
			break;
		case RETRACT:
			SetArm(false);
			*changed = true;
			*armState = DOWN;
			break;
		default:
			cout << "Climber in illegal state!";
			break;
	}
}

void Climber::ReverseArmState() {
	switch(*armState) {
		case DEFAULT:
		case DOWN:
			SetArm(true);
			*armState = UP;
			break;
		case UP:
			SetArm(false);
			*armState = DOWN;
			break;
		case EXTEND:
			SetExtend(false);
			*armState = RETRACT;
			break;
		case RETRACT:
			SetExtend(true);
			*armState = EXTEND;
			break;
		default:
			cout << "Climber in illegal state!";
			break;
	}
	*changed = true;
}

void Climber::SetWinchSpeed(double speed) {
	*Climber::winchSpeed = speed;
	*changed = true;
}

void Climber::ToggleWinches() {
	switch(*winchState) {
		case BOTH:
			*winchState = LEFT;
			break;
		case LEFT:
			*winchState = RIGHT;
			break;
		case RIGHT:
		default:
			*winchState = BOTH;
			break;
	}
	*changed = true;
}

void Climber::ToggleRunning(bool reverse) {
	if(*runState == OFF) {
		if(reverse) {
			*runState = REVERSE;
		}
		else {
			*runState = FORWARD;
		}
	}
	else {
		*runState = OFF;
	}
	*changed = true;
}