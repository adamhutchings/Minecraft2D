#ifndef M2D_WORLD_H
#define M2D_WORLD_H

#include <iostream>
#include "../render/renderable.h"
#include "../item/item_stack.h"

#define WORLD_HEIGHT_LIMIT 16
#define WORLD_WIDTH 10 // Temporary

class MWindow;
class Block;
class ItemStack;

// Represents a world made up of blocks.

class M2DWorld {
public:

	MWindow* i_window;

	// The array of blocks
	Block*** blocks;

	// For now, just a 10x10 world
	M2DWorld(MWindow& window);

	// Renders every component block
	void render(MWindow& target) const;

	// Block updates
	void b_break(int xPos, int yPos);
	void b_place(int xPos, int yPos, ItemStack* i);
};

#endif // M2D_WORLD_H
