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
	lastMousePressedLeft = lastMousePressedRight = false;
	state = MAIN_MENU;
}

void MWindow::cycle() {

	// For handling
	Entity* entity;

	// Simply for events
	sf::Event event;

	while (isOpen()) {

		// Handle window close event
		handleWindowEvents(event);

		// Centering
		if (player) player->setCenter();

		// Key presses
		if (state == MAIN_GAME && hasFocus()) {
			handleKeyPresses();
		}

		// Mouse presses

		// Left
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && !lastMousePressedLeft) {
			onClick(sf::Mouse::getPosition(*this).x, sf::Mouse::getPosition(*this).y, true);
			lastMousePressedLeft = true;
		} else if (!(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) && lastMousePressedLeft) {
			offClick(sf::Mouse::getPosition(*this).x, sf::Mouse::getPosition(*this).y, true);
			lastMousePressedLeft = false;
		}

		// Right
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right) && !lastMousePressedRight) {
			onClick(sf::Mouse::getPosition(*this).x, sf::Mouse::getPosition(*this).y, false);
			lastMousePressedRight = true;
		} else if (!(sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)) && lastMousePressedRight) {
			offClick(sf::Mouse::getPosition(*this).x, sf::Mouse::getPosition(*this).y, false);
			lastMousePressedRight = false;
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

void MWindow::onClick(int x, int y, bool m) {
	if (m) {
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
		if (player) {
			this->player->updateBlock(x, y, true);
		}
	} else {
		// Right click
		if (player) {
			player->updateBlock(x, y, false);
		}
	}
}

void MWindow::offClick(int x, int y, bool m) {
	if (m) {
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
}

void changeState(MWindow& window, bool escape) {
	MButton* button;
	Player* player;
	Block* block;
	Entity* entity;
	for (Renderable* object : window.objects) {
		button = dynamic_cast<MButton*>(object);
		player = dynamic_cast<Player*>(object);
		block = dynamic_cast<Block*>(object);
		entity = dynamic_cast<Entity*>(object);
		if (button) {
			// There might be a better finding system here later, who knows
			if (button->getString() == "Resume" || button->getString() == "Quit") {
				button->hidden = !escape;
			}
		} else if (player) {
			player->hidden = escape;
		} else if (block) {
			block->hidden = escape;
		} else if (entity) {
			entity->hidden = escape;
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

sf::Vector2f* screenToBlock(MWindow& relativeTo, sf::Vector2f& coords) {
	return new sf::Vector2f(
		 (coords.x + relativeTo.xShift - 100) / 200,
		-(coords.y + relativeTo.yShift - 100) / 200
	);
}

void MWindow::handleWindowEvents(sf::Event event) {
	while (pollEvent(event)) {
		if (event.type == sf::Event::EventType::Closed) {
			close();
		}
	}
}

void MWindow::handleKeyPresses() {
	// Player movement
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && player->isCollided()) {
		if (player) player->jump();
	} if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) {
		if (player) player->sneak();
	} if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		if (player) player->moveRight();
		player->facing = true;
	} if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		if (player) player->moveLeft();
		player->facing = false;
	} if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		if (player->facing && player) player->moveRight(); else if (player) player->moveLeft();
	} if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		if (player->facing && player) player->moveLeft(); else if (player) player->moveRight();

	// Escape menu
	} if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		escape(*this);
	}

	// Maybe I can do this better? Who knows?
	if (player) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
			player->hotbarPosition = 0;
		} if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
			player->hotbarPosition = 1;
		} if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
			player->hotbarPosition = 2;
		} if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {
			player->hotbarPosition = 3;
		} if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5)) {
			player->hotbarPosition = 4;
		} if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6)) {
			player->hotbarPosition = 5;
		} if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7)) {
			player->hotbarPosition = 6;
		} if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8)) {
			player->hotbarPosition = 7;
		} if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9)) {
			player->hotbarPosition = 8;
		}
	}

}
