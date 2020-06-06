#ifndef M_ITEM_H
#define M_ITEM_H

#include <string>
#include "entity.h"

#define ITEM_HEALTH 4;

// Describes an item that can be picked up (later!)

class Item : public Entity {
public:
	std::string name;
	int count; // How many items there are

	// We'll need a special constructor later, but not yet

	int getSpawnHealth() override;
	virtual int getMaxCount();
};

#endif // M_ITEM_H
