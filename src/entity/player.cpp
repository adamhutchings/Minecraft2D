#include "player.h"
#include "../world/world.h"

Player::Player(M2DWorld& world)
: Entity(&world, findSpawnLocation(world).x, findSpawnLocation(world).y)
, inventory() {

	world.i_window->player = this;

	height = 2;

	headLeft.setTexture(HEAD_TEX_LEFT, true);
	headRight.setTexture(HEAD_TEX_RIGHT, true);
	body.setTexture(BODY_TEX, true);

	// Facing right by default
	this->facing = true;

	// (To change later) set the window to be centered on the player

	// Window has player at upper left
	world.i_window->xShift =  x*200 + 100 - world.i_window->xShift;
	world.i_window->yShift = -y*200 + 100 - world.i_window->yShift;

	// Window has player in center
	world.i_window->xShift -= WN_WIDTH / 2;
	world.i_window->yShift -= WN_HEIGHT / 2;
}

void Player::render(MWindow& window) const {
	window.draw(facing ? headRight : headLeft); // Brilliance in a nutshell
	window.draw(body);
}

void Player::updateSpritePosition(MWindow& relativeTo) {
	int xPos = x * 200 + 100 - relativeTo.xShift;
	int yPos = -y * 200 + 100 - relativeTo.yShift;

	headLeft.setPosition(xPos - 35, yPos - 160);
	headRight.setPosition(xPos, yPos - 160);
	body.setPosition(xPos, yPos - 80);
}

int Player::getSpawnHealth() {
	return 20;
}

sf::Vector2f& findSpawnLocation(M2DWorld& world) {
	// For now, just returns a high spawn
	return *(new sf::Vector2f(0, 10));
}
