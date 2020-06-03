#ifndef M_WINDOW_H
#define M_WINDOW_H

#include <SFML/Graphics.hpp>
#include <string>

// Contains code for a window class.
class MWindow : public sf::RenderWindow {
public:

	// x and y are dimensions
	MWindow(int x, int y, std::string title);

	// The main loop
	void cycle();
};

#endif // M_WINDOW_H