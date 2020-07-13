#include "hotbar_renderer.h"

InventoryFrame::InventoryFrame(MWindow& window, int x, int y)
:
// Initialize the rects
b(sf::Vector2f(FRAME_SIZE, FRAME_THICKNESS)),
t(sf::Vector2f(FRAME_SIZE, FRAME_THICKNESS)),
l(sf::Vector2f(FRAME_THICKNESS, FRAME_SIZE)),
r(sf::Vector2f(FRAME_THICKNESS, FRAME_SIZE)) {
	// Giving positions to the various elements
	b.setPosition(sf::Vector2f(x - (FRAME_SIZE / 2), y + (FRAME_SIZE / 2) - FRAME_THICKNESS));
	t.setPosition(sf::Vector2f(x - (FRAME_SIZE / 2), y - (FRAME_SIZE / 2)));
	l.setPosition(sf::Vector2f(x - (FRAME_SIZE / 2), y - (FRAME_SIZE / 2)));
	r.setPosition(sf::Vector2f(x + (FRAME_SIZE / 2) - (FRAME_THICKNESS / 2), y - FRAME_SIZE / 2));
}

void InventoryFrame::render(MWindow& window) {
	// Just draw all the rectangles
	window.draw(b);
	window.draw(t);
	window.draw(l);
	window.draw(r);
}

void renderHotbar(MWindow& window, InventorySection* section) {
	int centerX;
	sf::Text text; // For later
	for (int i = 0; i < section->size; i++) {
		centerX = WN_WIDTH / 2 - (section->size * FRAME_SIZE / 2) + (i * FRAME_SIZE);
		InventoryFrame(window, centerX, HOTBAR_DISPLAY_HEIGHT).render(window);
		section->contents[i]->spr.setPosition(
			centerX - (200 * 0.4 / 2), HOTBAR_DISPLAY_HEIGHT - (200 * 0.4 / 2)
		);
		if (section->contents[i]->name != "empty") {
			window.draw(section->contents[i]->spr);
			if (section->contents[i]->count > 1) {
				// The item counter display
				text.setCharacterSize(FONT_SIZE);
				text.setFont(INVENTORY_FONT);
				text.setPosition(
					centerX - 100 + FONT_X_OFFSET,
					HOTBAR_DISPLAY_HEIGHT - 100 + FONT_Y_OFFSET
				);
				text.setString(std::to_string(section->contents[i]->count));
				window.draw(text);
			}	
		}
	}
}
