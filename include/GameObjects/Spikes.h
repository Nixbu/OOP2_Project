#pragma once
#include "Settings.h"
#include "FactoryManager.h"
#include "GameObjectFactories/SpikesFactory.h"
#include "GameObjects/ClickableObject.h"

class Spikes : public ClickableObject
{
public:
	Spikes(const Data& ObjectData, b2World& world, const sf::Texture& texture);
	virtual void update();
	virtual void handleClicked() {};

private:
	b2BodyDef m_bodyDef;
	b2FixtureDef m_fixtureDef;
	static bool m_registerit;
};