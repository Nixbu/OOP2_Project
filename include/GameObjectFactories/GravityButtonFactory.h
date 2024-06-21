#pragma once

#include "box2d/box2d.h"
#include <memory>
#include "GameObjects/GravityButton.h"
#include "World.h"


class GravityButtonFactory {
public:

	static std::shared_ptr<GameObject> createObject(const Data& ObjectData,
		World& world, const sf::Texture& texture);

private:

};