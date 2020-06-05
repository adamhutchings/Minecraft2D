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
