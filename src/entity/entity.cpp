#include "entity.h"
#include "../render/renderable.h"
#include "../world/world.h"
#include "../main.h"

// There will DEFINITELY be more code here later

Entity::Entity(M2DWorld* o_world, double x, double y)
: Renderable(*(o_world->i_window)) {
	this->x = x;
	this->y = y;
	world = o_world;
}

bool Entity::isCollided() {
	// Because worlds are simple right now, this doesn't need to be much.
	return y <= 10;
}

void Entity::update() {
	// Movement
	this->x += this->dx;
	this->y += this->dy;

	if (this->isCollided()) {
	// Friction doesn't just plain decrease, entities need to stop
		this->dx *= (this->dx > 0.01 || this->dx < -0.01) ? (1 - FRICTION) : 0;
		this->y = 10; // This will be replaced by a more permanent test later
	}

	// Gravity
	if (!(this->isCollided())) {
		this->dy -= GRAVITY_STRENGTH;
	} else {
		this->dy = 0;
	}
}
