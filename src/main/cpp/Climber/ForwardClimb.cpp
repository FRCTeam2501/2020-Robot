#include "Climber/ForwardClimb.h"
using namespace frc;


ForwardClimb::ForwardClimb(Climber *climber) : climber(climber) {}

void ForwardClimb::Initialize() {
	climber->Forward();
}