#ifndef M_WINDOW_H
#define M_WINDOW_H

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

// Includes are weird
class Renderable;
class Player;

// Contains code for a window class.
class MWindow : public sf::RenderWindow {
public:

	// For mouse press handling
	bool lastMousePressed;

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

	void add(Renderable* obj);

	void onClick(int x, int y);
	void offClick(int x, int y); // x and y might be useful here, who knows?
};

#endif // M_WINDOW_H
