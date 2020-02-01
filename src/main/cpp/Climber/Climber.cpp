#include "Climber/Climber.h"
using namespace frc;


Climber::Climber(Pneumatics *pneumatics) : pneumatics(pneumatics) {
	right = new rev::CANSparkMax(CAN::CLIMBER_RIGHT, rev::CANSparkMax::MotorType::kBrushless);
	left = new rev::CANSparkMax(CAN::CLIMBER_LEFT, rev::CANSparkMax::MotorType::kBrushless);

	right->RestoreFactoryDefaults();
	left->RestoreFactoryDefaults();

	left->Follow(*right);

	speed = new double (0.0);
	state = new uint8_t(OFF);
	enabled = new bool(false);
	cout << "Climber Subsystem Booted!\n";
}

Climber::~Climber() {
	delete right;
	delete left;

	delete speed;
	delete state;
	delete enabled;
}

void Climber::Periodic() {
	if(*enabled && *state == RETRACT) {
		right->Set(*speed);
	}
}

void Climber::SetWinch(double speed) {
	if(*enabled && *state == RETRACT) {
		*Climber::speed = speed;
	}
}

void Climber::Forward() {
	switch(*state) {
		case OFF:
		case DOWN:
			SetArm(true);
			*state = UP;
			break;
		case UP:
			SetExtend(true);
			*state = EXTEND;
			break;
		case EXTEND:
			SetExtend(false);
			*state = RETRACT;
			break;
		case RETRACT:
			SetArm(false);
			*state = DOWN;
			break;
		case ILLEGAL:
		default:
			cout << "Climber in illegal state!";
			break;
	}
}

void Climber::Reverse() {
	switch(*state) {
		case OFF:
		case DOWN:
			SetArm(true);
			*state = UP;
			break;
		case UP:
			SetArm(false);
			*state = DOWN;
			break;
		case EXTEND:
			SetExtend(false);
			*state = RETRACT;
			break;
		case RETRACT:
			SetExtend(true);
			*state = EXTEND;
			break;
		case ILLEGAL:
		default:
			cout << "Climber in illegal state!";
			break;
	}
}

void Climber::SetArm(bool up) {
	if(up) {
		pneumatics->SetClimbArm(DoubleSolenoid::kForward);
	}
	else {
		pneumatics->SetClimbArm(DoubleSolenoid::kReverse);
	}
}

void Climber::SetExtend(bool extend) {
	if(extend) {
		pneumatics->SetClimbExtend(DoubleSolenoid::kForward);
	}
	else {
		pneumatics->SetClimbExtend(DoubleSolenoid::kReverse);
	}
}