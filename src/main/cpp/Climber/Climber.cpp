#include "Climber/Climber.h"

Climber::Climber(Pneumatics *pneumatics) : pneumatics(pneumatics) {
    armState = new uint8_t(OFF);
    speed = new double(0.0);

    left = new rev::CANSparkMax(CAN::CLIMBER_LEFT, rev::CANSparkMax::MotorType::kBrushless);
    right = new rev::CANSparkMax(CAN::CLIMBER_RIGHT, rev::CANSparkMax::MotorType::kBrushless);

    right->Follow(*left);
}

Climber::~Climber(){
    delete armState;
    delete speed;
    delete left;
    delete right;
    delete speed;
}

void Climber::StateUp(){
    switch(*armState){
        case DEFAULT:
            pneumatics->ClimbRetract();
            pneumatics->VerticalLiftRetract();
            *armState = DOWN;
//            wpi::outs() << "DEFAULT";
            SmartDashboard::PutString("CLimb", "DEFAULT->DOWN");
            break;
        case DOWN:
            pneumatics->VerticalLiftExtend();
            *armState = UP;
//            wpi::outs() << "DOWN";
            SmartDashboard::PutString("CLimb", "DOWN->UP");
            break;
        case UP:
            pneumatics->ClimbExtend();
            *armState = EXTEND;
//            wpi::outs() << "UP";
            SmartDashboard::PutString("CLimb", "UP->EXTEND");

            break;
        case EXTEND:
            pneumatics->ClimbRetract();
            *armState = RETRACT;
//            wpi::outs() << "EXTEND";
            SmartDashboard::PutString("CLimb", "EXTEND->RETRACT");

            break;
        case RETRACT:
            pneumatics->VerticalLiftRetract();
            *armState = DOWN;
//            wpi::outs() << "RETRACT";
            SmartDashboard::PutString("CLimb", "RETRACT->DOWN");
            break;
        default:
            break;
    }
}

void Climber::StateBack(){
    switch(*armState){
            case DEFAULT:
                pneumatics->ClimbRetract();
                pneumatics->VerticalLiftRetract();
                *armState = DOWN;   
                SmartDashboard::PutString("CLimb", "DEFAULT->DOWN");
                break;
            case DOWN:
                pneumatics->VerticalLiftExtend();
                *armState = UP;
                SmartDashboard::PutString("CLimb", "DOWN->UP");
                break;
            case UP:
                pneumatics->VerticalLiftRetract();
                *armState = DOWN;
                SmartDashboard::PutString("CLimb", "UP->DOWN");
                break;
            case EXTEND:
                pneumatics->ClimbRetract();
                *armState = RETRACT;
                SmartDashboard::PutString("CLimb", "EXTEND->RETRACT");
                break;
            case RETRACT:
                pneumatics->ClimbExtend();
                *armState = EXTEND;
                SmartDashboard::PutString("CLimb", "RETRACT->EXTEND");
                break;
            default:
                break;
    }
}

void Climber::SetClimb(double speed){
    left->Set(speed);
}

void Climber::ToggleWinchOn(){
    switch(*winchState){
        case OFF:
            *winchState = FORWARD;

            break;
        case FORWARD:
        case REVERSE:  
        default:
            *winchState = OFF;
                break;
    }
}

void Climber::ToggleWinchOff(){
    *winchState = DEFAULT;
}

void Climber::ToggleWinchDownOn(){
    switch(*winchState){
        case OFF:
            *winchState = REVERSE;
            break;
        case REVERSE:
        default:
            *winchState = OFF;
                break;
    }
}

void Climber::ToggleWinchDownOff(){
    *winchState = DEFAULT;
}

void Climber::SetSpeed(double speed){
    *Climber::speed = speed;
}