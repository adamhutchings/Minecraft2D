#ifndef M_WINDOW_H
#define M_WINDOW_H

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

// Includes are weird
class Renderable;

// Contains code for a window class.
class MWindow : public sf::RenderWindow {
public:

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
};

#endif // M_WINDOW_H
