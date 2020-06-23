#ifndef MAIN_M2D_H
#define MAIN_M2D_H

#include <cstdlib>
#include "world/block.h"
#include "render/m_window.h"
#include "world/world.h"
#include "entity/player.h"
#include "gui/m_button.h"

// Window settings
#define WN_WIDTH 2000
#define WN_HEIGHT 2000
#define WN_BG_COLOR sf::Color(100, 175, 250)

// Physics settings
#define GRAVITY_STRENGTH 0.00003
#define FRICTION 0.05
#define JUMP_HEIGHT 0.005
#define WALK_SPEED 0.005
#define MINIMAL_JUMP_BUFFER 0.01

void loadButtonFont();
void loadTextures();

void startNewGame(MWindow& window);
void mExit(MWindow& window);

#endif // MAIN_M2D_H
