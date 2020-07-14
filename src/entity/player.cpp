#include "player.h"
#include "../world/world.h"

Player::Player(M2DWorld& world)
: Entity(&world, findSpawnLocation(world).x, findSpawnLocation(world).y + 0.1)
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

	inventory = new PlayerInventory(this);
}

void Player::render(MWindow& window) const {
	window.draw(facing ? headRight : headLeft); // Brilliance in a nutshell
	window.draw(body);
	renderHotbar(window, inventory->sections[0]); // Render the hotbar
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

sf::Vector2f** Player::getBottomCollisionPoints() {
	sf::Vector2f** result = new sf::Vector2f*[2];
	result[0] = new sf::Vector2f(x, y + (BLOCK_COLLISION_BUFFER));
	result[1] = new sf::Vector2f(x + (PLAYER_BODY_WIDTH / 200), y);
	return result;
}
sf::Vector2f** Player::getTopCollisionPoints() {
	sf::Vector2f** result = new sf::Vector2f*[2];
	if (facing) {
		// Left and right top points of head facing right
		result[0] = new sf::Vector2f(
			x, y + ((PLAYER_BODY_HEIGHT + PLAYER_HEAD_HEIGHT) / 200))
		;
		result[1] = new sf::Vector2f(
			x + (PLAYER_HEAD_WIDTH / 200), y + ((PLAYER_BODY_HEIGHT + PLAYER_HEAD_HEIGHT) / 200))
		;
	} else {
		// Right and left top points of head facing left
		result[0] = new sf::Vector2f(
			x + (PLAYER_BODY_WIDTH / 200), y + ((PLAYER_BODY_HEIGHT + PLAYER_HEAD_HEIGHT) / 200))
		;
		result[1] = new sf::Vector2f(
			x + ((PLAYER_BODY_WIDTH - PLAYER_HEAD_WIDTH)/200),
			y + ((PLAYER_BODY_HEIGHT + PLAYER_HEAD_HEIGHT) / 200))
		;
	}
	return result;
}
sf::Vector2f** Player::getLeftCollisionPoints() {
	sf::Vector2f** result = new sf::Vector2f*[4];
	result[0] = new sf::Vector2f(
		x, y + (PLAYER_BODY_HEIGHT / 200) + 0.1
	); // Top left corner of body
	result[1] = new sf::Vector2f(x, y + (0.1)); // Bottom left corner of body
	if (facing) {
		// Top left corner of head
		result[2] = new sf::Vector2f(
		x, y + (PLAYER_BODY_HEIGHT / 200) + 0.1
		); // Top left corner of body
		result[3] = new sf::Vector2f(
			x, y + ((PLAYER_BODY_HEIGHT + PLAYER_HEAD_HEIGHT) / 200) + 0.1
		);
	} else {
		// Bottom left corner of head, top left corner of head
		result[2] =
			new sf::Vector2f(
				x + ((PLAYER_BODY_WIDTH - PLAYER_HEAD_WIDTH) / 200),
				y + ((PLAYER_BODY_HEIGHT) / 200) + 0.1
			)
		;
		result[3] =
			new sf::Vector2f(
				x + ((PLAYER_BODY_WIDTH - PLAYER_HEAD_WIDTH) / 200),
				y + ((PLAYER_BODY_HEIGHT + PLAYER_HEAD_HEIGHT) / 200) + 0.1
			)
		;
	}
	return result;
}
sf::Vector2f** Player::getRightCollisionPoints() {
	sf::Vector2f** result = new sf::Vector2f*[4];
	result[0] = new sf::Vector2f(
		x + ((PLAYER_BODY_WIDTH) / 200),
		y + (PLAYER_BODY_HEIGHT / 200) + 0.1
	); // Top right corner of body
	result[1] = new sf::Vector2f(
		x + ((PLAYER_BODY_WIDTH) / 200), y + 0.1
	); // Bottom right corner of body
	if (facing) {
		// Top right corner of head
		result[2] = new sf::Vector2f(
			x + ((PLAYER_HEAD_WIDTH) / 200),
			y + ((PLAYER_BODY_HEIGHT + PLAYER_HEAD_HEIGHT) / 200 + 0.1
		));
		result[3] = new sf::Vector2f(
			x + ((PLAYER_BODY_WIDTH) / 200),
			y + (PLAYER_BODY_HEIGHT / 200) + 0.1
		); // Top right corner of body
	} else {
		// Bottom right corner of head, top right corner of head
		result[2] = 
			new sf::Vector2f(
				x + ((PLAYER_HEAD_WIDTH) / 200),
				y + ((PLAYER_BODY_HEIGHT) / 200) + 0.1
			)
		;
		result[3] = 
			new sf::Vector2f(
				x + ((PLAYER_HEAD_WIDTH) / 200),
				y + ((PLAYER_BODY_HEIGHT + PLAYER_HEAD_HEIGHT) / 200) + 0.1
			)
		;
	}
	return result;
}

bool Player::collidedBelow() {
	sf::Vector2f** colPoints = getBottomCollisionPoints();
	sf::Vector2f* point;
	for (int i = 0; i < 2; i++) {
		point = colPoints[i];
		if (!(point->y > WORLD_HEIGHT_LIMIT + 1 ||
			point->y < 0 ||
			point->x > WORLD_WIDTH + 1 ||
			point->x < 0
		)) {
			if (world->blocks[floorCoords(point)->x][floorCoords(point)->y]->str_type != "air") return true;
		}
	}
	return false;
}

bool Player::collidedAbove() {
	sf::Vector2f** colPoints = getTopCollisionPoints();
	sf::Vector2f* point;
	for (int i = 0; i < 2; i++) {
		point = colPoints[i];
		if (!(point->y > WORLD_HEIGHT_LIMIT + 1 ||
			point->y < 0 ||
			point->x > WORLD_WIDTH + 1 ||
			point->x < 0
		)) {
			if (world->blocks[floorCoords(point)->x][floorCoords(point)->y]->str_type != "air") return true;
		}
	}
	return false;
}

bool Player::collidedLeft() {
	sf::Vector2f** colPoints = getLeftCollisionPoints();
	sf::Vector2f* point;
	for (int i = 0; i < 4; i++) {
		point = colPoints[i];
		if (!(point->y > WORLD_HEIGHT_LIMIT + 1 ||
			point->y < 0 ||
			point->x > WORLD_WIDTH + 1 ||
			point->x < 0
		)) {
			if (world->blocks[floorCoords(point)->x][floorCoords(point)->y]->str_type != "air") return true;
		}
	}
	return false;
}

bool Player::collidedRight() {
	sf::Vector2f** colPoints = getRightCollisionPoints();
	sf::Vector2f* point;
	for (int i = 0; i < 4; i++) {
		point = colPoints[i];
		if (!(point->y > WORLD_HEIGHT_LIMIT + 1 ||
			point->y < 0 ||
			point->x > WORLD_WIDTH + 1 ||
			point->x < 0
		)) {
			if (world->blocks[floorCoords(point)->x][floorCoords(point)->y]->str_type != "air") return true;
		}
	}
	return false;
}

// Movement
void Player::moveLeft() {
	this->dx = -WALK_SPEED;
}

void Player::moveRight() {
	this->dx = WALK_SPEED;
}

void Player::jump() {
	this->dy += JUMP_HEIGHT;
}

void Player::sneak() {
	// Nothing needed here for now
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

sf::Vector2i* floorCoords(sf::Vector2f* coords) {
	return new sf::Vector2i((int) std::floor(coords->x), (int) std::floor(coords->y));
}

sf::Vector2f& findSpawnLocation(M2DWorld& world) {
	// For now, just returns a high spawn
	return *(new sf::Vector2f(1, 10));
}


void Player::updateBlock(int xPos, int yPos, bool destroy) {
	// Based on the mouse coordinates given, find the block to break

	// We only want to detect if in the main game
	if (getWindow()->state != MAIN_GAME) return;

	// The x and y differences
	float xDiff = xPos - PLAYER_HEAD_X;
	float yDiff = PLAYER_HEAD_Y - yPos;

	sf::Vector2f pos(xPos, yPos);

	// So we don't declare 100 times in a loop
	sf::Vector2f incrementedPosition = *screenToBlock(*getWindow(), pos);

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
		if (world->blocks[inX][inY]->str_type != "air") {
			if (destroy) {
				world->b_break(inX, inY + 1);
				return;
			}
		}
		// Increment the position
		incrementedPosition.x += xStep;
		incrementedPosition.y += yStep;
	}

}
