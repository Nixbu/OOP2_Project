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
	auto pos = this->m_body->GetPosition();
	this->setPosition(pos.x, pos.y );
	
}

void PhysicalObject::update()
{
	b2Vec2 position = m_body->GetPosition();
	float angle = m_body->GetAngle();

	// Convert Box2D position (meters) to SFML position (pixels)
	this->setPosition(position.x * SCALE, WINDOW_MANAGER_HEIGHT - position.y * SCALE);
	this->setRotation(angle * 180.0f / b2_pi);
}

PhysicalObject::~PhysicalObject()
{
	if (m_body) {
		m_body->GetWorld()->DestroyBody(m_body);
	}
}

b2Body* PhysicalObject::getBody()
{
	return m_body;
}

void PhysicalObject::SetLinearVelocity(const b2Vec2 linearVelocity)
{
	this->m_body->SetLinearVelocity(linearVelocity);
}