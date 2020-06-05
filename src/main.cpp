#include "main.h"

int main() {

	// Setup
	loadTextures();
	
	// For now, just create a new window
	MWindow wn(WN_WIDTH, WN_HEIGHT, "2D Minecraft");
	wn.color = WN_BG_COLOR;

	// Let's make a test block!
	M2DWorld world(wn);

	wn.cycle();

	return 0;

}
