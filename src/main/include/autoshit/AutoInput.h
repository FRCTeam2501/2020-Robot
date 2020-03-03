#pragma once
#include "Utils/include.h"

class AutoInput : public frc::ErrorBase {
private:
        frc::DigitalInput *switch0, *switch1, *switch2, *switch3, *switch4;
        //poop?

public: 
        AutoInput();
        ~AutoInput();

        uint32_t Get();
        wpi::Twine GetTwine();

};
