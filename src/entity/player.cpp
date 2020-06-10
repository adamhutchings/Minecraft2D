#include "player.h"

Player::Player(MWindow& window, double x, double y)
: Entity(window, x, y) {

	headLeft.setTexture(HEAD_TEX_LEFT, true);
	headRight.setTexture(HEAD_TEX_RIGHT, true);
	body.setTexture(BODY_TEX, true);

	// Facing right by default
	this->facing = true;
}

void Player::render(MWindow& window) const {
	window.draw(facing ? headRight : headLeft); // Brilliance in a nutshell
	window.draw(body);
}

void Player::updateSpritePosition(MWindow& relativeTo) {
	int xPos = x * 200 + 100 - relativeTo.xShift;
	int yPos = -y * 200 + 100 - relativeTo.yShift;

	headLeft.setPosition(xPos, yPos - 160);
	headRight.setPosition(xPos, yPos - 160);
	body.setPosition(xPos, yPos - 70);
}

int Player::getSpawnHealth() {
	return 20;
}
