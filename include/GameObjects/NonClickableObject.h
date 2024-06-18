#pragma once

#include "GameObjects/GameObject.h"
#include "Settings.h"


class NonClickableObject : public GameObject
{
public:
	NonClickableObject(const Data& data, const sf::Texture& texture);
	virtual ~NonClickableObject() = 0;
	virtual void update(){};

private:

};