#ifndef M_ITEM_H
#define M_ITEM_H

#include <string>
#include "entity.h"
#include "../item/item_stack.h"

#define ITEM_HEALTH 4;

// Describes an item that can be picked up (later!)

class EntityItem : public Entity {
public:
	
	// Internal item
	ItemStack* itemStackObj;

	// Constructor
	EntityItem(M2DWorld* o_world, ItemStack* is, double x, double y);

	int getSpawnHealth() override;
};

#endif // M_ITEM_H
