#ifndef M2D_WORLD_H
#define M2D_WORLD_H

#include <iostream>
#include "block.h"
#include "../render/renderable.h"

class MWindow;

// Represents a world made up of blocks.

class M2DWorld : public Renderable {
public:

	// The array of blocks
	Block*** blocks;

	// For now, just a 10x10 world
	M2DWorld(MWindow& window);

	// Renders every component block
	void render(MWindow& target) const override;
};

#endif // M2D_WORLD_H
