#ifndef M_ENTITY_H
#define M_ENTITY_H

#include <SFML/Graphics.hpp>
#include "../render/m_window.h"
#include "../render/renderable.h"

// Base class for all entities

class Entity : public Renderable {
public:
	int health;
	int maxHealth; // The maximum it can go up to - spawn health below

	// Entity coordinates need to be more precise!
	double x;
	double y;

	sf::Vector2f velocity; // x and y components

	double facing; // Direction facing - 0 to 2pi

	Entity(MWindow& window, double x, double y);
	virtual int getSpawnHealth() = 0;

};

#endif // M_ENTITY_H
