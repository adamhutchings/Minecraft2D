#ifndef ITEM_STACK_H
#define ITEM_STACK_H

#define ITEM_MAX_COUNT 64

#include <string>
#include "../render/renderable.h"
#include "../render/m_window.h"

enum ItemStackState {
	ENTITY,
	BLOCK,
	INVENTORY
};

// Represents a stack of items in the inventory.

class ItemStack : public Renderable {
public:
	std::string name;
	int count;
	ItemStackState itemStackState;

	ItemStack(MWindow& window, std::string name, int count=1);

	// When two item stacks combine (on ground or in-inventory)
	bool mergeWith(ItemStack& i);

	void render(MWindow& window) const override;

};

#endif // ITEM_STACK_H