#ifndef M_BLOCK_H
#define M_BLOCK_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include "../render/m_window.h"
#include "../render/renderable.h"
#include "../item/item_stack.h"
#include "world.h"
#include "../entity/item.h"

inline sf::Texture GRASS_TEX;
inline sf::Texture DIRT_TEX;
inline sf::Texture STONE_TEX;
inline sf::Texture DEFAULT_TEX; // For an errored-out block

class MWindow;
class ItemStack;

class Block : public Renderable {
public:
	std::string str_type;
	ItemStack* itemStack;
	Block(MWindow& window, int x, int y, std::string type="");
	void render(MWindow& window) const override;
	void updateSpritePosition(MWindow& relativeTo) override;
	EntityItem* destroy(M2DWorld& world);
	void setTypeTo(std::string type);
};

#endif // M_BLOCK_H
