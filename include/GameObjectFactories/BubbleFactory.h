#pragma once

#include "box2d/box2d.h"
#include <memory>
#include "GameObjects/Bubble.h"
#include "World.h"


class BubbleFactory {
public:

	static std::shared_ptr<GameObject> createObject(const std::string& line, 
									World& world, const sf::Texture& texture);

private:

};