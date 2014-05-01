#ifndef TILEDLEVEL_H
#define TILEDLEVEL_H

#include "tiledlevelarray.h"
#include <SFML/Graphics.hpp>

class TiledLevel : public TiledLevelArray, public sf::Drawable, public sf::Transformable {
public:
	TiledLevel();
	~TiledLevel();

	void loadFromImage(std::string fname);

	unsigned char& at(unsigned long x, unsigned long y);

	void reset();
	void reset(unsigned long w, unsigned long h);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
protected:
	void updateGraphics() const;
private:
	mutable sf::VertexArray _vertexArray;
	sf::Texture* _tilesetTexture;

	bool _graphicsNeedsUpdate;
};

#endif // TILEDLEVEL_H
