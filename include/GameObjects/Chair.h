#pragma once
#include "Settings.h"
#include "FactoryManager.h"
#include "GameObjectFactories/ChairFactory.h"
#include "GameObjects/NonClickableObject.h"

class Chair : public NonClickableObject
{
public:
	Chair(const Data& ObjectData, World& world, const sf::Texture& texture);
	virtual void update(sf::Time& deltaTime);

private:
	static bool m_registerit;
};