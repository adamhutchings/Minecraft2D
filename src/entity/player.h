#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "entity.h"
#include "../render/m_window.h"

// Represents a player in the game.
class Player : public Entity {
private:
	sf::Sprite headLeft; sf::Sprite headRight; // both 40x40
	sf::Sprite body; // 23x140 (just the size I downloaded, may change)
public:

	// Is the player facing left (false) or right (true)?
	bool facing;

	Player(MWindow& window, double x, double y);
	void render(MWindow& window) const override;
	void updateSpritePosition(MWindow& relativeTo) override;
	int getSpawnHealth() override;
};

#endif // PLAYER_H
