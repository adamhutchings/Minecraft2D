#ifndef M_INV_H
#define M_INV_H

#include <string>
#include "item_stack.h"

/* File with abstract inventory classes and inventories */

class InventorySection {
public:
	ItemStack** contents;
	InventorySection(int size);
	void addItem(ItemStack& is, int pos);
};

// Abstract class
class Inventory {
public:
	InventorySection** sections;
};

class PlayerInventory : public Inventory {
public:
	PlayerInventory();
};

// That's all we need for now, I believe.

#endif // M_INV_H