#include "renderable.h"

Renderable::Renderable(MWindow& window) {
	window.add(this);
}

void Renderable::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	wn = &(dynamic_cast<MWindow&>(target));
	if (wn) {
		render(*wn);
	}
}

void Renderable::updateSpritePosition(MWindow& relativeTo) {
	spr.setPosition(x*200 + 100 - relativeTo.xShift,  -y*200 + 100 - relativeTo.yShift);
}
