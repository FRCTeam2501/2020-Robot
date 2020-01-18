#include "Drivetrain/Drivetrain.h"
using namespace frc;


Drivetrain::Drivetrain() {
	leftFront = new PWMVictorSPX(PWM::LEFT_FRONT);
	leftRear = new PWMVictorSPX(PWM::LEFT_REAR);
	rightFront = new PWMVictorSPX(PWM::RIGHT_FRONT);
	rightRear = new PWMVictorSPX(PWM::RIGHT_REAR);

	left = new SpeedControllerGroup(*leftFront, *leftRear);
	right = new SpeedControllerGroup(*rightFront, *rightRear);

	drive = new DifferentialDrive(*left, *right);

	inverted = new bool(false);
}

Drivetrain::~Drivetrain() {
	delete leftFront;
	delete leftRear;
	delete rightFront;
	delete rightRear;

	delete left;
	delete right;

	delete drive;

	delete inverted;
}

void Drivetrain::Periodic() {}

void Drivetrain::ArcadeDrive(double y, double rz) {
	if(*inverted)
		y *= -1.0;

	drive->ArcadeDrive(y, rz);
}