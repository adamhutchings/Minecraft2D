#ifndef M_WINDOW_H
#define M_WINDOW_H

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

// Contains code for a window class.
class MWindow : public sf::RenderWindow {
public:

	sf::Color color;

	// For rendering
	std::vector<sf::Drawable*> objects;

	// x and y are dimensions
	MWindow(int x, int y, std::string title);

	// The main loop
	void cycle();

	void add(sf::Drawable* obj);
};

#endif // M_WINDOW_H