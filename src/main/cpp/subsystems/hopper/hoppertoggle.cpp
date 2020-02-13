#include <frc2/command/Command.h> 
#include <frc2/command/Command.h> 
#include "subsystems/hopper/hopper.h"
#include "subsystems/hopper/hoppertoggle.h"

using namespace frc; 

hoppertoggle::hoppertoggle(Hopper* subsytem)
        : hopper(subsytem) { 
          AddRequirements(subsytem);
        }

void hoppertoggle::Initialize(){ 
  hopper->hoppertoggle();
}