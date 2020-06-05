#ifndef M_RENDERABLE_H
#define M_RENDERABLE_H

#include <SFML/Graphics.hpp>
#include "m_window.h"

class MWindow;

// For type casting
inline MWindow* wn;

// Defines a small extension class of sf::Drawable
class Renderable : public sf::Drawable {
	// We aren't going to need any blurring effects on main objects
public:

	// Coordinates of the object
	int x;
	int y;

	Renderable(MWindow& window);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	virtual void render(MWindow& window) const = 0;
};

#endif // M_RENDERABLE_H
