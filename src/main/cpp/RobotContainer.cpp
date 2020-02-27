#include "Utils/ButtonMap.h"
#include "RobotContainer.h"
#include "Utils/include.h"
#include"Utils/ports.h"                                                                                                                               
RobotContainer::RobotContainer() {

startHopper = new frc2::JoystickButton(controlStick, JOYSTICK::BUTTON_11);
startHopper->ToggleWhenPressed(new frc2::StartEndCommand(
[this]{
   hopper->UppyWuppy(-1.0);
},
[this]{
    hopper->UppyWuppy(0.0);
},
{hopper}
));
}
reverseHopper = new frc2::JoystickButton(controlStick, JOYSTICK::BUTTON_10);
reverseHopper->ToggleWhenPressed(new frc2::StartEndCommand(
[this]{
   hopper->UppyWuppy(1.0);
},
[this]{
    hopper->UppyWuppy(0.0);
},
{hopper}
));
}
}
