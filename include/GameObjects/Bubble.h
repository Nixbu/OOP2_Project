#pragma once
#include "Settings.h"
#include "FactoryManager.h"
#include "GameObjectFactories/BubbleFactory.h"
#include "GameObjects/ClickableObject.h"

class Bubble : public ClickableObject
{
public:
	Bubble(const Data& ObjectData, b2World& world, const sf::Texture& texture);
	void changeToDynamic();
	virtual void update();
	virtual void handleClicked();

private:
	b2BodyDef m_bodyDef;
	b2FixtureDef m_fixtureDef;
	static bool m_registerit;
};