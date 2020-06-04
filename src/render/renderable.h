#ifndef M_RENDERABLE_H
#define M_RENDERABLE_H

#include <SFML/Graphics.hpp>
#include "m_window.h"

// Defines a small extension class of sf::Drawable
class Renderable : public sf::Drawable {
	// We aren't going to need any blurring effects on main objects
public:

	// Coordinates of the object
	int x;
	int y;

	// Are the coords relative to the world (false) or the screen (true)?
	bool locked;

	Renderable(MWindow& window, bool l=false);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	virtual void render(sf::RenderTarget& window) const = 0;
};

#endif // M_RENDERABLE_H