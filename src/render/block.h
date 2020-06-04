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

void loadTextures();

class Block : public Renderable {
private:
	sf::Sprite tex;
public:
	Block(MWindow& window, std::string type="");
	void render(sf::RenderTarget& window) const override;
};

#endif // M_BLOCK_H