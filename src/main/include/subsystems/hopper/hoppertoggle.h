
#include <frc2/command/Command.h> 
#include <frc2/command/InstantCommand.h> 
#include "subsystems/hopper/hopper.h"
#include "Utils/include.h"

class hoppertoggle : public frc2::InstantCommand {
    public:
    hoppertoggle(Hopper* subsytem); 

    void Initialize() override;

private:
    Hopper * hopper;
};
