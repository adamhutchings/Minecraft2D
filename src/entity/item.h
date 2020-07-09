#ifndef M_ITEM_H
#define M_ITEM_H

#include <string>
#include "entity.h"
#include "../render/m_window.h"

#define ITEM_HEALTH 4;

class ItemStack;

// Describes an item that can be picked up (later!)

class EntityItem : public Entity {

public:
	
	// Internal item
	ItemStack* itemStackObj;

	// Constructor
	EntityItem(M2DWorld* o_world, ItemStack* is, double x, double y);

	int getSpawnHealth() override;

	void render(MWindow& window) const override;

	bool collidedBelow() override;
	bool collidedAbove() override;
	bool collidedLeft()  override;
	bool collidedRight() override;

	void updateSpritePosition(MWindow& relativeTo) override;
};

#endif // M_ITEM_H
