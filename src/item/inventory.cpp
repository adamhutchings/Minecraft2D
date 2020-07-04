#include "inventory.h"

InventorySection::InventorySection(MWindow& renderOn, int width) {
	for (int i = 0; i < width; i++) {
		this->contents[width] = new ItemStack("empty", 0);
	}
}

void InventorySection::addItem(ItemStack& is, int pos) {
	if (pos >= sizeof(this->contents) / sizeof(this->contents[0])) {
		// Illegal move! Nooo!
		return;
	} else if (contents[pos]->name == "empty") {
		contents[pos] = &is;
	} else {
		contents[pos]->mergeWith(is);
	}
}

PlayerInventory::PlayerInventory(Player* p) {
	sections[0] = new InventorySection(*(p->world->i_window), 9); // Just the hotbar
}
