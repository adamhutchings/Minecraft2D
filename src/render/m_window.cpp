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
		handleWindowEvents(event);

		// Centering
		if (player) player->setCenter();

		// Key presses
		if (state == MAIN_GAME && hasFocus()) {
			handleKeyPresses();
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
	breakBlock(*this, x, y);
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
	} if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		escape(*this);
	}
}

void breakBlock(MWindow& window, int xPos, int yPos) {
	// Based on the mouse coordinates given, find the block to break

	// We only want to detect if in the main game
	if (!(window.player) || (window.state != MAIN_GAME)) return;

	// The x and y differences
	float xDiff = xPos - PLAYER_HEAD_X;
	float yDiff = PLAYER_HEAD_Y - yPos;

	sf::Vector2f pos(xPos, yPos);

	// So we don't declare 100 times in a loop
	sf::Vector2f incrementedPosition = *screenToBlock(window, pos);

	// How much to increment x and y by
	double distance = sqrt((xDiff*xDiff) + (yDiff*yDiff));
	double xStep = (xDiff / distance) * PLAYER_REACH / BLOCK_BREAK_COMPARISONS;
	double yStep = (yDiff / distance) * PLAYER_REACH / BLOCK_BREAK_COMPARISONS;

	// I'll improve window.player->world some other time
	// We send out a ray from the player's head (actually increment a position)
	for (int i = 0; i < BLOCK_BREAK_COMPARISONS; i++) {
		int inX = (int) floor(incrementedPosition.x);
		int inY = (int) floor(incrementedPosition.y);
		if (inX > 0 && inX < WORLD_WIDTH && inY > 0 && inY < WORLD_HEIGHT_LIMIT)
		if (window.player->world->blocks[inX][inY]->str_type != "air") {
			window.player->world->b_break(*(window.player->world), inX, inY + 1);
			return;
		}
		// Increment the position
		incrementedPosition.x += xStep;
		incrementedPosition.y += yStep;
	}

}
