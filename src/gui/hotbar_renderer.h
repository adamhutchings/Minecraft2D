#ifndef M_HB_RENDERER_H
#define M_HB_RENDERER_H

#include <SFML/Graphics.hpp>
#include "../render/m_window.h"
#include "../item/inventory.h"
#include "../render/renderable.h"
#include "../main.h"

#define FRAME_THICKNESS 20
#define FRAME_SIZE 160

#define HOTBAR_DISPLAY_HEIGHT 1400

#define FONT_SIZE 20

#define FONT_X_OFFSET 120
#define FONT_Y_OFFSET 120

inline sf::Font INVENTORY_FONT;

class InventorySection;

class InventoryFrame {
public:
	sf::RectangleShape b, t, l, r; // The four sides
	InventoryFrame(MWindow& window, int xPos, int yPos);
	void render(MWindow& window);
};

// This provides a method to render an inventory section in a straight line
// at the bottom of the screen.
void renderHotbar(MWindow& window, InventorySection* section);

#endif // M_HB_RENDERER_H
