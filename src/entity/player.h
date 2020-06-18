#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "entity.h"
#include "../render/m_window.h"
#include "../main.h"
#include "../item/inventory.h"

inline sf::Texture HEAD_TEX_LEFT;
inline sf::Texture HEAD_TEX_RIGHT;
inline sf::Texture BODY_TEX;

class M2DWorld;

sf::Vector2f& findSpawnLocation(M2DWorld& world);

// Represents a player in the game.
class Player : public Entity {
private:
	sf::Sprite headLeft; sf::Sprite headRight; // both 40x40
	sf::Sprite body; // 23x140 (just the size I downloaded, may change)
public:

	PlayerInventory* inventory;

	// Is the player facing left (false) or right (true)?
	bool facing;

	Player(M2DWorld& world);
	void render(MWindow& window) const override;
	void updateSpritePosition(MWindow& relativeTo) override;
	int getSpawnHealth() override;
	void setCenter();
};

#endif // PLAYER_H
