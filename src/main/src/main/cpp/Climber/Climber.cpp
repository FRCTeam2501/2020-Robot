#include "Subsystems/Climber.h"

Climber::Climber(Pneumatics *pneumatics) {
    state = new uint8_t(OFF);
    speed = new double(0.0);

    left = new rev::CANSparkMax(CAN::CLIMBER_LEFT, rev::CANSparkMax::MotorType::kBrushless);
    right = new rev::CANSparkMax(CAN::CLIMBER_RIGHT, rev::CANSparkMax::MotorType::kBrushless);

    right->Follow(*left);
}

Climber::~Climber() {
    
}

void Climber::StateUp(){
    switch(*state){
        case OFF:
            pneumatics->ClimbRetract();
            pneumatics->VerticalLiftRetract();
            *state = DOWN;
            break;
        case DOWN:
            pneumatics->VerticalLiftExtend();
            *state = UP;
            break;
        case UP:
            pneumatics->ClimbExtend();
            *state = EXTEND;
            break;
        case EXTEND:
            pneumatics->ClimbRetract();
            *state = RETRACT;
            break;
        case RETRACT:
            pneumatics->VerticalLiftRetract();
            *state = DOWN;
            break;
        default:
            break;
    }
}

void Climber::StateBack(){
    switch(*state){
            case OFF:
                pneumatics->ClimbRetract();
                pneumatics->VerticalLiftRetract();
                *state = DOWN;
                break;
            case DOWN:
                pneumatics->VerticalLiftExtend();
                *state = UP;
                break;
            case UP:
                pneumatics->VerticalLiftRetract();
                *state = DOWN;
                break;
            case EXTEND:
                pneumatics->ClimbRetract();
                *state = RETRACT;
                break;
            case RETRACT:
                pneumatics->ClimbExtend();
                *state = EXTEND;
                break;
            default:
                break;
    }
}

void Climber::SetClimb(double speed){
    left->Set(speed);
}

void Climber::ToggleWinchOn(){

}

void Climber::ToggleWinchOff(){

}

void Climber::ToggleWinchDownOn(){

}

void Climber::ToggleWinchDownOff(){

}

void Climber::SetSpeed(double speed){
    *Climber::speed = speed;
}