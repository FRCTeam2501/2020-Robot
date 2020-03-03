#include "autoshit/AutoInput.h"
#include "Utils/ports.h"


AutoInput::AutoInput() {
    switch0 = new frc::DigitalInput(MXP::DIO::brian);//porst dumb
    switch1 = new frc::DigitalInput(MXP::DIO::is);
    switch2 = new frc::DigitalInput(MXP::DIO::uppy);
    switch3 = new frc::DigitalInput(MXP::DIO::wuppy);
    switch4 = new frc::DigitalInput(MXP::DIO::indeed);
    //uppy wuppy poopy woopy
  
}

AutoInput::~AutoInput() {
        delete switch0;
         delete switch1;
         delete switch2;
         delete switch3;
         delete switch4;
}

uint32_t AutoInput::Get() { 
    return 
                (switch4->Get() << 4)+
                 (switch4->Get() << 3)+
                  (switch4->Get() << 2)+
                  (switch4->Get() << 1)+
                  (switch4->Get() << 0)
            ;

                
}

wpi::Twine AutoInput::GetTwine() {
    return wpi::Twine(Get());
}