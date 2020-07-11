#ifndef M_ENTITY_H
#define M_ENTITY_H

#include <SFML/Graphics.hpp>
#include "../render/m_window.h"
#include "../render/renderable.h"

// A small error correction for block collision
#define BLOCK_COLLISION_BUFFER 0.005

class M2DWorld;

// Base class for all entities

// For collision
enum CollisionState {
	COLLIDED_NONE,
	COLLIDED_BELOW,
	COLLIDED_ABOVE,
	COLLIDED_LEFT,
	COLLIDED_RIGHT
};

class Entity : public Renderable {
public:
	M2DWorld* world;

	int health;
	int maxHealth; // The maximum it can go up to - spawn health below

	double width;
	double height;

	// Entity coordinates need to be more precise!
	double x;
	double y;

	double dx;
	double dy;

	Entity(M2DWorld* world, double x, double y);
	virtual int getSpawnHealth() = 0;

	// Collision stuff
	virtual bool collidedBelow() = 0;
	virtual bool collidedAbove() = 0;
	virtual bool collidedLeft()  = 0;
	virtual bool collidedRight() = 0;

	CollisionState isCollided();

	virtual void update();

	virtual void die();

};

#endif // M_ENTITY_H
