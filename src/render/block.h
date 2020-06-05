#ifndef M_BLOCK_H
#define M_BLOCK_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include "m_window.h"
#include "renderable.h"

inline sf::Texture GRASS_TEX;
inline sf::Texture DEFAULT_TEX; // For an errored-out block
// More textures here later

class MWindow;

void loadTextures();

class Block : public Renderable {
private:
	sf::Sprite spr;
public:
	Block(MWindow& window, int x, int y, std::string type="");
	void render(MWindow& window) const override;
	void updateSpritePosition(MWindow& relativeTo);
};

#endif // M_BLOCK_H
