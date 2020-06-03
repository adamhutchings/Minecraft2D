#include "main.h"

int main() {
	
	// For now, just create a new window
	MWindow wn(WN_WIDTH, WN_HEIGHT, "2D Minecraft");
	wn.color = WN_BG_COLOR;
	wn.cycle();

	return 0;

}
