#include "hotbar_renderer.h"

InventoryFrame::InventoryFrame(MWindow& window, int x, int y)
: Renderable(window),
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

void InventoryFrame::render(MWindow& window) const {
	// Just draw all the rectangles
	window.draw(b);
	window.draw(t);
	window.draw(l);
	window.draw(r);

}

void renderHotbar(MWindow& window, InventorySection* section) {

}
