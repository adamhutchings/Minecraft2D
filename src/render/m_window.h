#ifndef M_WINDOW_H
#define M_WINDOW_H

#include <cmath>
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

// I'll separate these into a separate file later. Maybe.
#define MAIN_MENU 0
#define MAIN_GAME 1
#define ESCAPED 2

#define PLAYER_REACH 5

#define BLOCK_BREAK_COMPARISONS 100

// Includes are weird
class Renderable;
class Player;

// Contains code for a window class.
class MWindow : public sf::RenderWindow {
public:

	// The state of the game
	int state;

	// For mouse press handling
	bool lastMousePressedLeft;
	bool lastMousePressedRight;

	Player* player;

	// Offsets from being a centered window
	int xShift;
	int yShift;

	sf::Color color;

	// For rendering
	std::vector<Renderable*> objects;

	// x and y are dimensions
	MWindow(int x, int y, std::string title);

	// The main loop
	void cycle();

	// Some functions just to make stuff easier to handle
	void handleWindowEvents(sf::Event event);
	void handleKeyPresses();

	void add(Renderable* obj);

	void onClick(int x, int y, bool m);
	void offClick(int x, int y, bool m); // x and y might be useful here, who knows?
};

void changeState(MWindow& window, bool escape = true);
void escape(MWindow& window);
void returnToGame(MWindow& window);

sf::Vector2f* screenToBlock(MWindow& relativeTo, sf::Vector2f& coords);
void breakBlock(MWindow& window, int xPos, int yPos);

#endif // M_WINDOW_H
