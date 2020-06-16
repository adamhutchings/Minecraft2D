#include "entity.h"
#include "../render/renderable.h"
#include "../world/world.h"

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
