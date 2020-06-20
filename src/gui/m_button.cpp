#include "m_button.h"

MButton::MButton(MWindow& wn, void (*fn) (MWindow& wn), std::string str, sf::Color color, int x, int y)
: Renderable(wn),
rect(sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT)) {
	action = fn;
	clicked = hidden = false;

	// Setting up rectangle and text
	rect.setPosition(x - BUTTON_WIDTH / 2, y - BUTTON_HEIGHT / 2);
	rect.setFillColor(color);
	text.setCharacterSize(BUTTON_FONT_SIZE);
	text.setFont(M_BUTTON_FONT);
	text.setString(str);
}

bool MButton::contains(int xLoc, int yLoc) {
	return rect.getGlobalBounds().contains(sf::Vector2f(xLoc, yLoc));
}

void MButton::render(MWindow& wn) const {
	wn.draw(rect);
	wn.draw(text);
}

void MButton::updateSpritePosition(MWindow& relativeTo) {
	updateTextPosition();
}

void MButton::updateTextPosition() {
	// Might make these two lines into a function, who knows
	int w = clicked ? BUTTON_WIDTH * BUTTON_EXPANSION_FACTOR : BUTTON_WIDTH;
	int h = clicked ? BUTTON_HEIGHT * BUTTON_EXPANSION_FACTOR : BUTTON_HEIGHT;
	text.setPosition(rect.getPosition().x + w / 2, rect.getPosition().y + h / 2);
	sf::FloatRect textRect = text.getLocalBounds();
	text.setOrigin(
		textRect.left + textRect.width / 2,
		textRect.top + textRect.height / 2
	);
}

void MButton::onClick() {
	clicked = true;
	rect.setPosition(sf::Vector2f(rect.getPosition().x - (BUTTON_WIDTH * (BUTTON_EXPANSION_FACTOR - 1)) / 2,
		rect.getPosition().y - (BUTTON_HEIGHT * (BUTTON_EXPANSION_FACTOR - 1)) / 2
	));
	rect.setSize(
		sf::Vector2f(rect.getSize().x * BUTTON_EXPANSION_FACTOR, rect.getSize().y * BUTTON_EXPANSION_FACTOR)
	);
	text.setCharacterSize(text.getCharacterSize() * BUTTON_EXPANSION_FACTOR);
}

void MButton::offClick(MWindow& window) {
	clicked = false;
	rect.setPosition(sf::Vector2f(rect.getPosition().x + (BUTTON_WIDTH * (BUTTON_EXPANSION_FACTOR - 1)) / 2,
		rect.getPosition().y + (BUTTON_HEIGHT * (BUTTON_EXPANSION_FACTOR - 1)) / 2
	));
	rect.setSize(sf::Vector2f(rect.getSize().x / BUTTON_EXPANSION_FACTOR, rect.getSize().y / BUTTON_EXPANSION_FACTOR));
	text.setCharacterSize(text.getCharacterSize() / BUTTON_EXPANSION_FACTOR);
	action(window);
}
