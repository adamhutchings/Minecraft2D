#ifndef M_INV_H
#define M_INV_H

#include <string>
#include "item_stack.h"
#include "../render/renderable.h"
#include "../entity/player.h"

/* File with abstract inventory classes and inventories */

class InventorySection {
public:
	ItemStack** contents;
	InventorySection(MWindow& renderOn, int size);
	void addItem(ItemStack& is, int pos);
};

// Abstract class
class Inventory {
public:
	Inventory(int num);
	InventorySection** sections;
	void addItem(ItemStack& is);
};

class PlayerInventory : public Inventory {
public:
	Player* owner;
	PlayerInventory(Player* p);
};

// That's all we need for now, I believe.

#endif // M_INV_H