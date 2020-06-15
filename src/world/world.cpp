#include "world.h"
#include "../render/m_window.h"
#include "block.h"

M2DWorld::M2DWorld(MWindow& window)
: Renderable(window) {

	i_window = &window;

	// Double array
	blocks = new Block** [10];

	for (int i = 0; i < 10; i++) {
		blocks[i] = new Block* [10];
		for (int j = 0; j < 10; j++) {
			// Some really basic world gen - to change later
			if (j == 9) {
				blocks[i][j] = new Block(window, i, j, "grass");
			} else if (j > 7) {
				blocks[i][j] = new Block(window, i, j, "dirt");
			} else {
				blocks[i][j] = new Block(window, i, j, "stone");
			}
		}
	}
}

void M2DWorld::render(MWindow& target) const {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			blocks[i][j]->render(target);
		}
	}
}
