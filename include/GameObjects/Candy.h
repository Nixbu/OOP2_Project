#pragma once
#include "Settings.h"
#include "FactoryManager.h"
#include "GameObjectFactories/CandyFactory.h"
#include "GameObjects/PhysicalObject.h"

class Candy : public PhysicalObject
{
public:
	Candy(const Data& ObjectData, b2World& world, const sf::Texture& texture);
	virtual void update();
	virtual void handleClicked(World& world) {};

	
private:
	b2BodyDef m_bodyDef;
	b2FixtureDef m_fixtureDef;
	static bool m_registerit;
};