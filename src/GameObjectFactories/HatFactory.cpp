#include "GameObjectFactories/HatFactory.h"
#include "GameObjects/Hat.h"


std::shared_ptr<GameObject> HatFactory::createObject(const Data& ObjectData,
	b2World& world,
	const sf::Texture& texture) const
{
	return std::make_shared<Hat>(ObjectData, texture);
}