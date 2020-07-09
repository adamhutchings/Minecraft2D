#include "entity.h"
#include "../render/renderable.h"
#include "../world/world.h"
#include "../main.h"

Entity::Entity(M2DWorld* o_world, double x, double y)
: Renderable(*(o_world->i_window)) {
	this->x = x;
	this->y = y;
	world = o_world;
}

CollisionState Entity::isCollided() {

	// Testing if out of world bounds
	if (x <= -width || x >= 10) return CollisionState::COLLIDED_NONE; // Will change  -0.2 later
	if (y < BLOCK_COLLISION_BUFFER || y > 16 + BLOCK_COLLISION_BUFFER) return CollisionState::COLLIDED_NONE;

	if (x >= 1) {
		if (collidedLeft()) return CollisionState::COLLIDED_LEFT;
	} if (x <= WORLD_WIDTH - 2) {
		if (collidedRight()) return CollisionState::COLLIDED_RIGHT;
	} if (y >= BLOCK_COLLISION_BUFFER) {
		if (collidedBelow()) return CollisionState::COLLIDED_BELOW;
	} if (y - BLOCK_COLLISION_BUFFER <= WORLD_HEIGHT_LIMIT - 1) {
		if (collidedAbove()) return CollisionState::COLLIDED_ABOVE;
	}

	return CollisionState::COLLIDED_NONE;
}

void Entity::update() {
	// Movement
	this->x += this->dx;
	this->y += this->dy;

	CollisionState collisionState = this->isCollided();

	if (collisionState != COLLIDED_NONE) {
		// Friction doesn't just plain decrease, entities need to stop
		this->dx *= (this->dx > 0.01 || this->dx < -0.01) ? (1 - FRICTION) : 0;
		if (collisionState == COLLIDED_BELOW) this->y += 2 * BLOCK_COLLISION_BUFFER;
		else if (collisionState == COLLIDED_ABOVE) this->y -= 2 * BLOCK_COLLISION_BUFFER;
		else if (collisionState == COLLIDED_LEFT)  this->x += 2 * BLOCK_COLLISION_BUFFER;
		else if (collisionState == COLLIDED_RIGHT) this->x -= 2 * BLOCK_COLLISION_BUFFER;
	}

	// Gravity
	if (!(this->isCollided())) {
		this->dy -= GRAVITY_STRENGTH;
	} else {
		this->dy = 0;
	}
}

void Entity::die() {
	for (int i = 0; i < world->i_window->objects.size(); i++) {
		if (world->i_window->objects.at(i) == this) {
			world->i_window->objects.erase(world->i_window->objects.begin() + i);
			delete this;
			return;
		}
	}
}
