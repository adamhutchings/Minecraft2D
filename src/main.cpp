#include "main.h"

int main() {

	// Setup
	loadTextures();
	
	// For now, just create a new window
	MWindow wn(WN_WIDTH, WN_HEIGHT, "2D Minecraft");
	wn.color = WN_BG_COLOR;

	// Let's make a world and a player!
	M2DWorld world(wn);
	Player player(wn, 0, 0);

	wn.cycle();

	return 0;

}
