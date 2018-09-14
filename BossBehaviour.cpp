#include "BossBehaviour.h"

#include "Reference.h"

BossBehaviour::BossBehaviour() {
	velocity = Ref::VectorZero;
	delta = Ref::VectorZero;
	count = 0;
}