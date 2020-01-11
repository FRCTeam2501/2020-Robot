#include "Utils/include.h"
#include "Drivetrain/Drivetrain.h"


Drivetrain::Drivetrain()
{
    frontLeft = new PWMVictorSPX(PWM::LEFT_FRONT);
    frontRight = new PWMVictorSPX(PWM::RIGHT_FRONT);
    rearLeft = new PWMVictorSPX(PWM::LEFT_REAR);
    rearRight = new PWMVictorSPX(PWM::RIGHT_REAR);

    xSpeed = new double(0.0);
    rSpeed = new double(0.0);
}

Drivetrain::~Drivetrain()
{
    delete frontLeft;
    delete frontRight;
    delete rearLeft;
    delete rearRight;

    delete xSpeed;
    delete rSpeed;
}

void Drivetrain::setSpeed(double x, double r)
{
    x = *xSpeed;
    r = *zSpeed;

    drive->ArcadeDrive(*xSpeed, *rSpeed);
}

double Drivetrain::getXSpeed()
{
    return *xSpeed;
}
double Drivetrain::getRSpeed()
{
    return *rSpeed;
}

void Drivetrain::Periodic()
{
    //Do nothing
}