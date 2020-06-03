#include "m_window.h"

MWindow::MWindow(int x, int y, std::string title)
: sf::RenderWindow(sf::VideoMode(x, y), title),
color(0, 0, 0) {
	// Color defaults to black
}

void MWindow::cycle() {

	// Simply for events
	sf::Event event;

	while (isOpen()) {

		// Handle window close event
		while (pollEvent(event)) {
			if (event.type == sf::Event::EventType::Closed) {
				close();
			}
		}

		// Other handling stuff here later

		// Repainting the screen
		clear(color);

		display();

	}
}
