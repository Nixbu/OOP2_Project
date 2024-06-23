#include "Level.h"

Level::Level() :  m_status(OnGoing) , m_stars(0), m_world(m_status , m_stars), m_accumulator(0) 
{
}

void Level::loadLevel()
{
	
	this->m_world.reset();
	// TODO add try catch
	m_levelFile.open(m_levelName);

	this->readLevel();

	m_levelFile.close();

	this->m_clock.restart();

}

void Level::draw(sf::RenderWindow& window) const
{
	this->m_world.draw(window);
}

void Level::update()
{
	this->m_world.handleCollisions();

	float deltaTime = m_clock.restart().asSeconds();
	m_accumulator += deltaTime;

	// Update the world if the accumulator exceeds the time step
	while (m_accumulator >= TIME_STEP) {
		m_world.update(TIME_STEP);
		m_accumulator -= TIME_STEP;
	}
}

void Level::handleClicks(const sf::Vector2f& mousePos)
{
	this->m_world.handleClicks(mousePos);
}
void Level::setLevelName(const std::string& levelName)
{
	this->m_levelName = levelName;
}

levelStatus_t Level::getLevelStatus() const
{
	return this->m_status;
}

void Level::setLevelStatus(const levelStatus_t& status)
{
	this->m_status = status;
}

std::string Level::getLevelName() const
{
	return this->m_levelName;
}

void Level::resetStars()
{
	this->m_stars = 0;
}

int Level::getStars() const
{
	return this->m_stars;
}

void Level::readLevel()
{
	std::string line;

	while (std::getline(this->m_levelFile, line)) {
		this->m_world.addObject(line);
	}
	
	this->m_world.clear();
}

