#include "world.h"
#include "../render/m_window.h"

M2DWorld::M2DWorld(MWindow& window)
: Renderable(window) {

	// Double array
	blocks = new Block** [10];

	for (int i = 0; i < 10; i++) {
		blocks[i] = new Block* [10];
		for (int j = 0; j < 10; j++) {
			blocks[i][j] = new Block(window, i, j, "grass");
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
