#ifndef MAIN_M2D_H
#define MAIN_M2D_H

#include "world/block.h"
#include "render/m_window.h"
#include "world/world.h"
#include "entity/player.h"

// Window settings
#define WN_WIDTH 2000
#define WN_HEIGHT 2000
#define WN_BG_COLOR sf::Color(100, 175, 250)

// Physics settings
#define GRAVITY_STRENGTH 0.005
#define FRICTION 0.05
#define JUMP_HEIGHT 0.01
#define WALK_SPEED 0.005

void loadTextures();

#endif // MAIN_M2D_H
