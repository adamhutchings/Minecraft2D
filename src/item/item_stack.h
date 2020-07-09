#ifndef ITEM_STACK_H
#define ITEM_STACK_H

#define ITEM_MAX_COUNT 64

#define ITEM_ENTITY_SIZE 0.4

#include <string>
#include "../render/renderable.h"
#include "../render/m_window.h"
#include "../world/block.h"

enum ItemStackState {
	ENTITY,
	BLOCK,
	INVENTORY
};

// Represents a stack of items in the inventory.

class ItemStack {
protected:
	ItemStackState itemStackState;
public:
	sf::Sprite spr; // This will get rendered in different contexts
	std::string name;
	int count;

	ItemStack(std::string name, ItemStackState i, int count=1);

	// When two item stacks combine (on ground or in-inventory)
	bool mergeWith(ItemStack& i);

	void loadTexture(std::string tex);

	ItemStackState& getItemState();
	void setItemState(const ItemStackState i);

};

#endif // ITEM_STACK_H