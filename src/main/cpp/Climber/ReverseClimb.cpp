#include "Climber/ReverseClimb.h"
using namespace frc;


ReverseClimb::ReverseClimb(Climber *climber) : climber(climber) {}

void ReverseClimb::Initialize() {
	climber->Forward();
}