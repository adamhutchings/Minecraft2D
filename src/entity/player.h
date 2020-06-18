#ifndef PLAYER_H
#define PLAYER_H

#include <cmath>
#include <SFML/Graphics.hpp>
#include "entity.h"
#include "../render/m_window.h"
#include "../main.h"
#include "../item/inventory.h"

// Hardcoded player head coords for now
#define PLAYER_HEAD_X 1482
#define PLAYER_HEAD_Y 2772

inline sf::Texture HEAD_TEX_LEFT;
inline sf::Texture HEAD_TEX_RIGHT;
inline sf::Texture BODY_TEX;

class M2DWorld;

sf::Vector2f& findSpawnLocation(M2DWorld& world);

// Represents a player in the game.
class Player : public Entity {
private:
	sf::Sprite headLeft; sf::Sprite headRight; // both 80x80
	sf::Sprite body; // 46x280 (just the size I downloaded, may change)
public:

	PlayerInventory* inventory;

	// Is the player facing left (false) or right (true)?
	bool facing;

	Player(M2DWorld& world);
	void render(MWindow& window) const override;
	void updateSpritePosition(MWindow& relativeTo) override;
	int getSpawnHealth() override;
	void setCenter();
	void update() override;
};

#endif // PLAYER_H
