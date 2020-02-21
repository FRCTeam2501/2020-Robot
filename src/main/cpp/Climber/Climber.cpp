#include "Climber/Climber.h"

Climber::Climber(Pneumatics *pneumatics) : pneumatics(pneumatics) {
    armState = new uint8_t(DEFAULT);
    speed = new double(0.0);
    speedWinch = new double(0.0);
    runState = new uint8_t(OFF);
    winchState = new uint8_t(BOTH);

    changed = new bool(false);

    left = new rev::CANSparkMax(CAN::CLIMBER_LEFT, rev::CANSparkMax::MotorType::kBrushless);
    right = new rev::CANSparkMax(CAN::CLIMBER_RIGHT, rev::CANSparkMax::MotorType::kBrushless);

    //right->Follow(*left);
}

Climber::~Climber(){
    delete armState;
    delete speedWinch;
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
    switch(*runState){
        case OFF:
            *runState = FORWARD;

            break;
        case FORWARD:
        case REVERSE:  
        default:
            *runState = OFF;
                break;
    }
}

void Climber::ToggleWinchOff(){
    *runState = DEFAULT;
}

void Climber::ToggleWinchDownOn(){
    switch(*runState){
        case OFF:
            *runState = REVERSE;
            break;
        case REVERSE:
        default:
            *runState = OFF;
                break;
    }
}

void Climber::ToggleWinchDownOff(){
    *runState = DEFAULT;
}

void Climber::SetSpeed(double speed){
    *Climber::speedWinch = speed;
}

void Climber::Periodic() {
//    if(*changed) {
        if(*armState == RETRACT){
            wpi::outs() << "IN RETRACT";
            double speed = 0.0;
            switch(*runState) {
                case FORWARD:
                    speed = *speedWinch;
                    wpi::outs() << "forward ";
                    break;
                case REVERSE:
                    wpi::outs() << "reverse ";
                    speed = *speedWinch * -1.0;
                    break;
                case OFF:
                default:
                    break;
            }
            switch(*winchState) {
                case BOTH:
                default:
                    wpi::outs() << "both\n";
                    left->Set(speed);
                    right->Set(speed);
                break;
            }
        }

 //   }
}