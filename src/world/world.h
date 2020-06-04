#ifndef M2D_WORLD_H
#define M2D_WORLD_H

#include "../render/block.h"
#include "../render/m_window.h"
#include "../render/renderable.h"

// Represents a world made up of blocks.

class M2DWorld : public Renderable {
public:

	// The array of blocks
	Block[10]* blocks[10];

	// For now, just a 10x10 world
	M2DWorld(MWindow& window);

	// Renders every component block
	void render(sf::RenderTarget& target) const override;
}

#endif // M2D_WORLD_H