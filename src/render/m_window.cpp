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
	lastMousePressed = false;
	state = MAIN_MENU;
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

		// Centering
		if (player) player->setCenter();

		// Key presses
		if (state == MAIN_GAME) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && player->isCollided()) {
				if (player) player->dy += JUMP_HEIGHT;
			} if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) ||
				sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) {
				// Sneak later, but not yet
			} if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				if (player) player->dx = WALK_SPEED;
				player->facing = true;
			} if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				if (player) player->dx = -WALK_SPEED;
				player->facing = false;
			} if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				escape(*this);
			}
		}

		// Mouse presses
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && !lastMousePressed) {
			onClick(sf::Mouse::getPosition(*this).x, sf::Mouse::getPosition(*this).y);
			lastMousePressed = true;
		} else if (!(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) && lastMousePressed) {
			offClick(sf::Mouse::getPosition(*this).x, sf::Mouse::getPosition(*this).y);
			lastMousePressed = false;
		}

		// Display the screen
		clear(color);

		for (Renderable* object : objects) {
			object->updateSpritePosition(*this);
			if (!object->hidden) {
				draw(*object);
			}

			// Entity handling
			entity = dynamic_cast<Entity*>(object);
			if (entity) {
				if (state == MAIN_GAME) {
					entity->update();
				}
			}

		}

		display();

	}
}

void MWindow::add(Renderable* obj) {
	objects.push_back(obj);
}

void MWindow::onClick(int x, int y) {
	MButton* button;
	for (Renderable* object : objects) {
		button = dynamic_cast<MButton*>(object);
		if (button) {
			if (button->contains(x, y)) {
				button->onClick();
				return;
			}
		}
	}
}

void MWindow::offClick(int x, int y) {
	MButton* button;
	for (Renderable* object : objects) {
		button = dynamic_cast<MButton*>(object);
		if (button) {
			if (button->clicked) {
				button->offClick(*this);
				return;
			}
		}
	}
}

void changeState(MWindow& window, bool escape) {
	MButton* button;
	Player* player;
	Block* block;
	for (Renderable* object : window.objects) {
		button = dynamic_cast<MButton*>(object);
		player = dynamic_cast<Player*>(object);
		block = dynamic_cast<Block*>(object);
		if (button) {
			// There might be a better finding system here later, who knows
			if (button->getString() == "Resume" || button->getString() == "Quit") {
				button->hidden = !escape;
			}
		} else if (player) {
			player->hidden = escape;
		} else if (block) {
			block->hidden = escape;
		}
	}
}

void escape(MWindow& window) {
	window.state = ESCAPED;
	changeState(window, true);
}

void returnToGame(MWindow& window) {
	window.state = MAIN_GAME;
	changeState(window, false);
}
