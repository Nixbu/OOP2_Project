#include "GameObjectFactories/CandyFactory.h"
#include "GameObjects/Candy.h"


std::unique_ptr<PhysicalObject> CandyFactory::createPhysicalObject(const Data& ObjectData, b2World& world) const
{
	return std::make_unique<Candy>(ObjectData, world);
}
