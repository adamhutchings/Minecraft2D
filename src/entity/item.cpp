#include "item.h"
#include "../item/item_stack.h"
#include "player.h"

EntityItem::EntityItem(M2DWorld* o_world, ItemStack* is, double x, double y)
: Entity(o_world, x, y) {
	itemStackObj = is;
	itemStackObj->setItemState(ItemStackState::ENTITY);
}

int EntityItem::getSpawnHealth() {
	return ITEM_HEALTH;
}

void EntityItem::render(MWindow& window) const {
	window.draw(itemStackObj->spr);
}
bool EntityItem::collidedBelow() {
	return world->blocks[(int) floor(x)][(int) floor(y - 0.3)]->str_type != "air";
}

bool EntityItem::collidedAbove() {
	return false;
}

bool EntityItem::collidedLeft () {
	return false;
}

bool EntityItem::collidedRight() {
	return false;
}

void EntityItem::updateSpritePosition(MWindow& relativeTo) {
	itemStackObj->spr.setPosition(x*200 + 60 - relativeTo.xShift, -y*200 + 260 - relativeTo.yShift);
}

void EntityItem::update() {
	Entity::update();
	Player* player; // For later type casts
	for (Renderable* obj : world->i_window->objects) {
		player = dynamic_cast<Player*>(obj);
		if (player) {
			// Checking to see if the player is in bounds for pick up
			if (   abs(player->x - this->x) < PLAYER_ITEM_PICKUP_DISTANCE
				&& abs((player->y + 1) - this->y) < 1 + PLAYER_ITEM_PICKUP_DISTANCE) {
				player->inventory->addItem(*(this->itemStackObj));
				die();
				return;
			}
		}
	}
}
