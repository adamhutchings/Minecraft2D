#ifndef M_BUTTON_H
#define M_BUTTON_H

#include <iostream>
#include <string>
#include "../render/renderable.h"
#include "../render/m_window.h"

#define BUTTON_WIDTH 200
#define BUTTON_HEIGHT 100
#define BUTTON_EXPANSION_FACTOR 1.25

#define BUTTON_FONT_SIZE 30

// Source code for GUI buttons.

inline sf::Font M_BUTTON_FONT;

class MButton : public Renderable {
private:
	sf::RectangleShape rect;
	sf::Text text;
public:
	void (*action) (MWindow& wn);

	// Will be used in updateSpritePosition
	int x;
	int y;

	bool clicked;

	bool hidden;

	MButton(MWindow& wn, void (*fn) (MWindow& wn), std::string str, sf::Color color, int x, int y);
	bool contains(int xLoc, int yLoc);
	void render(MWindow& window) const override;
	void updateSpritePosition(MWindow& relativeTo) override;
	void updateTextPosition(); // For button resizes

	// Clicking
	void onClick();
	void offClick(MWindow& window);
};

#endif // M_BUTTON_H
