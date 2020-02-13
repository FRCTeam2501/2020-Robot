#include "climber/climber.h"
void climber ::periodic(){}
climber::climber(Pneumatics *pneumatics) {
left= new rev::CANSparkMax(CAN::CLIMBER_LEFT, rev::CANSparkMax::MotorType::kBrushless);
right= new rev::CANSparkMax(CAN::CLIMBER_RIGHT, rev::CANSparkMax::MotorType::kBrushless);

right->Follow(*left);

}
climber::~climber() {
}

void climber ::StateUp(){
switch (*state){
case OFF:
pneumatics->ClimbRetract();
pneumatics->VerticalLiftRetract();
*state=DOWN;
break;
case DOWN:
pneumatics->VericalLiftExtend();
*state=UP
break;
case UP:
pneumatics->ClimbRetract();
*state RETRACT;
pneumatics->ClimbExtend();
*state EXTEND;
break;
pneumatics->VerticalLiftRetract
*state DOWN;
break;
default:
break;
}
}
void climber::StateBack(){
switch(*state){
case OFF:
pnuematics-> ClimbRetract();
pnuematics->VerticalLiftRetract();
*state DOWN;
break;
pnuematics->VerticalLiftExtend();
*state UP;
break;
case UP;
pneumatics->VerticalLiftRetract();
*state DOWN;
break;
case Extend;
pneumatics->ClimbExtend();
*state EXTEND;
break;
case:RERACT
pneumatics->ClimbRetract();
*state RETRACT;
break;
default:
break;
}
}
void::climber::SetClimb(){
left->set(5000);
}





