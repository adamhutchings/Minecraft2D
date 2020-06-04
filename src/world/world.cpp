#include "world.cpp"

M2DWorld::M2DWorld(MWindow& window)
: Renderable(window) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			blocks[i][j] = new Block(window, "grass");
		}
	}
}

void M2DWorld::render(sf::RenderTarget& target) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			block[i][j].render(target);
		}
	}
}
