#include "player.h"

Player::Player(MWindow& window, double x, double y)
: Entity(window, x, y) {

	// Load the textures.
	sf::Texture headTexLeft;
	sf::Texture headTexRight;
	sf::Texture bodyTex;
	if (!headTexLeft.loadFromFile("res/head_left.jpg" ) ||
		!headTexRight.loadFromFile("res/head_right.jpg") ||
		!bodyTex.loadFromFile("res/body.jpg")) {
		std::cout << "Player textures failed to load.\n";
	}
	headLeft.setTexture(headTexLeft, true);
	headRight.setTexture(headTexRight, true);
	body.setTexture(bodyTex, true);

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
