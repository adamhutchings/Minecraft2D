#ifndef M_HB_RENDERER_H
#define M_HB_RENDERER_H

#include <SFML/Graphics.hpp>
#include "../render/m_window.h"
#include "../item/inventory.h"
#include "../render/renderable.h"

#define FRAME_THICKNESS 20
#define FRAME_SIZE 160

inline sf::Font INVENTORY_FONT;

class InventoryFrame : public Renderable {
public:
	sf::RectangleShape b, t, l, r; // The four sides
	InventoryFrame(MWindow& window, int xPos, int yPos);
	void render(MWindow& window) const override;
};

// This provides a method to render an inventory section in a straight line
// at the bottom of the screen.
void renderHotbar(MWindow& window, InventorySection* section);

#endif // M_HB_RENDERER_H