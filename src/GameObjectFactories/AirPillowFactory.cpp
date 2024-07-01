#include "GameObjectFactories/AirPillowFactory.h"
#include "GameObjects/AirPillow.h"

//===================================================================
// creats Air pillow object
//===================================================================
std::unique_ptr<GameObject> AirPillowFactory::createObject(const std::string& line, World& world, const sf::Texture& texture)
{
	std::istringstream iss(line);
	Data objectData;

	iss >> objectData.m_type >> objectData.m_subType >> objectData.m_pos.x >> objectData.m_pos.y >> objectData.m_angle;

	return std::make_unique<AirPillow>(objectData, world, texture);
}
