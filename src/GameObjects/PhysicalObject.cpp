#include "GameObjects/PhysicalObject.h"

PhysicalObject::PhysicalObject(const Data& data,const sf::Texture& texture) : m_body(nullptr) ,  GameObject(data.m_pos,texture)
	
{

}

void PhysicalObject::initBody(b2World& world, 
	const b2BodyDef& bodyDef,
	const b2FixtureDef& fixtureDef)
{
	m_body = world.CreateBody(&bodyDef);
	this->m_body->CreateFixture(&fixtureDef);
}

void PhysicalObject::update()
{
	b2Vec2 position = m_body->GetPosition();
	float angle = m_body->GetAngle();

	// Convert Box2D position (meters) to SFML position (pixels)
	this->setPosition(position.x * SCALE, position.y * SCALE * -1);
	this->setRotation(angle * 180.0f / b2_pi);
}

PhysicalObject::~PhysicalObject()
{
	if (m_body) {
		m_body->GetWorld()->DestroyBody(m_body);
	}
}
