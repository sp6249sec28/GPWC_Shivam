#include "bat.h"

Bat::Bat(float startX, float startY){
	m_Position.x = startX;
	m_Position.y = startY;
	
	m_Shape.setSize(sf::Vector2f(50, 5));
	m_Shape.setPosition(m_Position);
	
}

FloatRect Bat::getPosition(){     //scope resolution operator is used to declare public members
	return m_Shape.getGlobalBounds();
}

RectangleShape Bat::getShape(){   //scope resolution operator is used to declare public members
	return m_Shape;
}

void Bat::moveLeft(){             //scope resolution operator is used to declare public members
	m_MovingLeft = true;
}

void Bat::moveRight(){            //scope resolution operator is used to declare public members
	m_MovingRight = true;
}

void Bat::stopLeft(){             //scope resolution operator is used to declare public members
	m_MovingLeft = false;
}

void Bat::stopRight(){            //scope resolution operator is used to declare public members
	m_MovingRight = false;
}

void Bat::update(Time dt){
	if (m_MovingLeft){
		m_Position.x = m_Position.x - m_Speed * dt.asSeconds();
	}
	if (m_MovingRight){
		m_Position.x = m_Position.x + m_Speed * dt.asSeconds();
	}
	
	m_Shape.setPosition(m_Position);
}
