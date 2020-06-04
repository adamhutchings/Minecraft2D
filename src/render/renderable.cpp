#include "renderable.h"

Renderable::Renderable(MWindow& window, bool l) {
	window.add(this);
	locked = l;
}

void Renderable::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	render(target);
}
