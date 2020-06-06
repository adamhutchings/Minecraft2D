#include "entity.h"

// There will DEFINITELY be more code here later

Entity::Entity(MWindow& window, double x, double y)
: Renderable(window) {
	this->x = x;
	this->y = y;
}
