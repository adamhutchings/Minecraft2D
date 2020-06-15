#include <cmath>
#include "m_window.h"
#include "../world/block.h"
#include "renderable.h"
#include "../entity/entity.h"
#include "../main.h"
#include "../entity/player.h"

class Block;

MWindow::MWindow(int x, int y, std::string title)
: sf::RenderWindow(sf::VideoMode(x, y), title),
color(0, 0, 0) {
	xShift = yShift = 0;
	player = nullptr;
}

void MWindow::cycle() {

	// For handling
	Entity* entity;

	// Simply for events
	sf::Event event;

	while (isOpen()) {

		// Handle window close event
		while (pollEvent(event)) {
			if (event.type == sf::Event::EventType::Closed) {
				close();
			}
		}

		// Key presses
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			if (player) player->dy += JUMP_HEIGHT;
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) {
			// Sneak later, but not yet
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			if (player) player->dx = WALK_SPEED;
			player->facing = true;
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			if (player) player->dx = -WALK_SPEED;
			player->facing = false;
		}

		// Other handling stuff here later

		// Display the screen
		clear(color);

		for (Renderable* object : objects) {
			object->updateSpritePosition(*this);
			draw(*object);

			// Entity handling
			entity = dynamic_cast<Entity*>(object);
			if (entity) {
				// Movement
				entity->x += entity->dx;
				entity->y += entity->dy;

				// Friction doesn't just plain decrease, entities need to stop
				entity->dx *= abs(entity->dx) > 0.01 ? (1 - FRICTION) : 0;
				entity->dy *= abs(entity->dy) > 0.01 ? (1 - FRICTION) : 0;

				// Gravity
				if (!(entity->isCollided())) {
					entity->dy -= GRAVITY_STRENGTH;
				}
			}

		}

		display();

	}
}

void MWindow::add(Renderable* obj) {
	objects.push_back(obj);
}
