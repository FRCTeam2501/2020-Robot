#include "OI/OI.h"
#include "Utils/include.h"

using namespace frc;

Joystick
*OI::driverStick,
*OI::driverStick2,
*OI::controlStick;

//make the shit
OI::OI() {

    driverStick = new Joystick(JOYSTICK::DRIVER);
    driverStick2 = new Joystick(JOYSTICK::DRIVER);
    controlStick = new Joystick(JOYSTICK::DRIVER);
}

//break the shit
OI::~OI() {
    delete driverStick;
    delete driverStick2;
    delete controlStick;
}
