#ifndef M2D_WORLD_H
#define M2D_WORLD_H

#include <iostream>
#include "../render/renderable.h"

#define WORLD_HEIGHT_LIMIT 16
#define WORLD_WIDTH 10 // Temporary

class MWindow;
class Block;

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

	// Breaking a block
	void b_break(M2DWorld& world, int xPos, int yPos);
};

#endif // M2D_WORLD_H
