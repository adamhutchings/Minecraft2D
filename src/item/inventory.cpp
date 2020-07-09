#include "inventory.h"

InventorySection::InventorySection(MWindow& renderOn, int width) {
	this->contents = new ItemStack*[width];
	for (int i = 0; i < width; i++) {
		this->contents[i] = new ItemStack("empty", ItemStackState::INVENTORY, 0);
	}
}

void InventorySection::addItem(ItemStack& is, int pos) {
	if ((pos >= sizeof(this->contents) / sizeof(this->contents[0]))
		|| ((is.name != contents[pos]->name) && contents[pos]->name != "empty")){
		// Illegal move! Nooo!
		return;
	} else if (contents[pos]->name == "empty") {
		contents[pos] = &is;
	} else {
		contents[pos]->mergeWith(is);
	}
}

Inventory::Inventory(int num) {
	sections = new InventorySection* [num];
}

void Inventory::addItem(ItemStack& is) {

	InventorySection* inventorySection;
	ItemStack* itemStack; // for later

	// See if there are any matching item stacks
	for (int i = 0; i < sizeof(sections) / sizeof(sections[0]); i++) {
		inventorySection = sections[i];
		for (int j = 0; j < sizeof(inventorySection) / sizeof(inventorySection[0]); j++) {
			itemStack = inventorySection->contents[j];
			if ((itemStack->count != 0) && (itemStack->name == is.name)) {
				inventorySection->addItem(is, j);
				return;
			}
		}
	}

	// If there was no available slot
	for (int i = 0; i < sizeof(sections) / sizeof(sections[0]); i++) {
		inventorySection = sections[i];
		for (int j = 0; j < sizeof(inventorySection) / sizeof(inventorySection[0]); j++) {
			itemStack = inventorySection->contents[j];
			if ((itemStack->count == 0) && (itemStack->name == "empty")) {
				inventorySection->addItem(is, j);
			}
		}
	}

}

PlayerInventory::PlayerInventory(Player* p)
: Inventory(1) {
	owner = p;
	sections[0] = new InventorySection(*(p->world->i_window), 9); // Just the hotbar
}
