#include "player.h"
#include "../world/world.h"

Player::Player(M2DWorld& world)
: Entity(&world, findSpawnLocation(world).x, findSpawnLocation(world).y)
, inventory() {

	world.i_window->player = this;

	height = 2;
	width = 0.2;

	headLeft.setTexture(HEAD_TEX_LEFT, true);
	headRight.setTexture(HEAD_TEX_RIGHT, true);
	body.setTexture(BODY_TEX, true);

	// So rotations work more smoothly, rotation is relative to bottom middle
	sf::Vector2f origin(40, 80);
	headLeft.setOrigin(origin);
	headRight.setOrigin(origin);

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

	headLeft.setPosition(xPos + 5, yPos - 80);
	headRight.setPosition(xPos + 40, yPos - 80);
	body.setPosition(xPos, yPos - 80);
}

int Player::getSpawnHealth() {
	return 20;
} 

void Player::setCenter() {
	// Set the window to be centered on the player
	world->i_window->xShift =  x*200 + 100 - WN_WIDTH / 2;
	world->i_window->yShift = -y*200 + 100 - WN_HEIGHT / 2;
}

bool Player::collidedBelow() {
	return world->blocks[(int) x][(int) (y - BLOCK_COLLISION_BUFFER)]->str_type != "air";
}

bool Player::collidedAbove() {
	return world->blocks[(int) x][(int) (y - BLOCK_COLLISION_BUFFER) + 2]->str_type != "air";
}

bool Player::collidedLeft() {
	// Check blocks to the lower left and to the upper left
	return (
		world->blocks[(int) x - 1][(int) (y - BLOCK_COLLISION_BUFFER) + 1]->str_type != "air" ||
		world->blocks[(int) x - 1][(int) (y - BLOCK_COLLISION_BUFFER) + 2]->str_type != "air"
	);
}

bool Player::collidedRight() {
	// Check blocks to the lower right and to the upper right
	return (
		world->blocks[(int) std::floor(x + 0.2)][(int) (y - BLOCK_COLLISION_BUFFER) + 1]->str_type != "air" ||
		world->blocks[(int) std::floor(x + 0.2)][(int) (y - BLOCK_COLLISION_BUFFER) + 2]->str_type != "air"
	);
}

void Player::update(){
	Entity::update();

	/* Update head location */

	sf::Vector2i pos = sf::Mouse::getPosition(*(world->i_window));

	double pi = 2 * acos(0.0);

	float xDiff = pos.x - PLAYER_HEAD_X;
	float yDiff = PLAYER_HEAD_Y - pos.y; // This one goes up and down normally now

	double rotation = (xDiff == 0) ? (yDiff > 0 ? -pi/4 : pi/4) : atan(yDiff / xDiff);

	// Right head only faces right (-pi/2 to pi/2), left head left(-pi/2 to -pi/4, pi/4 to pi/2)
	// Also, if the player isn't moving, make them face the direction of the mouse
	if (xDiff < 0) {
		if (dx == 0) {
			facing = false;
		}
		// Mouse is left
		headLeft.setRotation(- rotation * 360 / (2 * pi));
	} else {
		if (dx == 0) {
			facing = true;
		}
		headRight.setRotation(- rotation * 360 / (2 * pi));
	}

}

sf::Vector2f& findSpawnLocation(M2DWorld& world) {
	// For now, just returns a high spawn
	return *(new sf::Vector2f(1, 10));
}
