#include "item.h"

int Item::getSpawnHealth() {
	return ITEM_HEALTH;
}

int Item::getMaxCount() {
	// Just like the MC default
	return 64;
}
