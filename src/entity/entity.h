#ifndef M_ENTITY_H
#define M_ENTITY_H

#include <SFML/Graphics.hpp>
#include "../render/m_window.h"
#include "../render/renderable.h"

// A small error correction for block collision
#define BLOCK_COLLISION_BUFFER 0.005

class M2DWorld;

// Base class for all entities

class Entity : public Renderable {
public:
	M2DWorld* world;

	int health;
	int maxHealth; // The maximum it can go up to - spawn health below

	int height;

	// Entity coordinates need to be more precise!
	double x;
	double y;

	double dx;
	double dy;

	Entity(M2DWorld* world, double x, double y);
	virtual int getSpawnHealth() = 0;

	bool isCollided();

	virtual void update();

};

#endif // M_ENTITY_H
