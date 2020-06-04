#include "m_window.h"
#include "renderable.h"

MWindow::MWindow(int x, int y, std::string title)
: sf::RenderWindow(sf::VideoMode(x, y), title),
color(0, 0, 0) {
	xShift = yShift = 0;
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

		// Display the screen
		clear(color);

		for (Renderable* object : objects) {
			draw(*object);
		}

		display();

	}
}

void MWindow::add(Renderable* obj) {
	objects.push_back(obj);
}
