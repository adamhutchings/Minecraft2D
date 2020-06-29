#include "world.h"
#include "../render/m_window.h"
#include "block.h"

M2DWorld::M2DWorld(MWindow& window) {

	i_window = &window;

	// Double array
	blocks = new Block** [WORLD_WIDTH];

	for (int i = 0; i < WORLD_WIDTH; i++) {
		blocks[i] = new Block* [WORLD_HEIGHT_LIMIT];
		for (int j = 0; j < WORLD_HEIGHT_LIMIT; j++) {
			// Some really basic world gen - to change later
			if (j < 7) {
				blocks[i][j] = new Block(window, i, j, "stone");
			} else if (j < 9) {
				blocks[i][j] = new Block(window, i, j, "dirt");
			} else if (j == 9) {
				blocks[i][j] = new Block(window, i, j, "grass");
			} else {
				blocks[i][j] = new Block(window, i, j, "air");
			}
		}
	}
}

void M2DWorld::render(MWindow& target) const {
	for (int i = 0; i < WORLD_WIDTH; i++) {
		for (int j = 0; j < 10; j++) {
			blocks[i][j]->render(target);
		}
	}
}

void M2DWorld::b_break(int xPos, int yPos) {
	delete (blocks[xPos][yPos]);
	blocks[xPos][yPos] = new Block(*i_window, xPos, yPos, "air");
}
