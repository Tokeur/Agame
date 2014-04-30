#include "tiledlevel.h"
#include "utility/logger.h"

TiledLevel::TiledLevel() : _vertexArray(sf::Triangles){
	_tilesetTexture = new sf::Texture;

	if (!_tilesetTexture->loadFromFile("resources/textures/tileset.png"))
		Logger::log("ERROR: Unable to load tileset texture");

	_graphicsNeedsUpdate=true;
}

TiledLevel::~TiledLevel() {
	delete _tilesetTexture;
}

void TiledLevel::loadFromImage(std::string fname) {
	_graphicsNeedsUpdate=true;
	TiledLevelArray::loadFromImage(fname);
}

unsigned char& TiledLevel::at(unsigned long x, unsigned long y) {
	_graphicsNeedsUpdate=true;
	return TiledLevelArray::at(x, y);
}

void TiledLevel::reset() {
	_graphicsNeedsUpdate=true;
	TiledLevelArray::reset();
}

void TiledLevel::reset(unsigned long w, unsigned long h) {
	_graphicsNeedsUpdate=true;
	TiledLevelArray::reset(w, h);
}

void TiledLevel::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	if (_graphicsNeedsUpdate)
		updateGraphics();

	states.transform = getTransform();
	states.texture = _tilesetTexture;

	target.draw(_vertexArray, states);
}

void TiledLevel::updateGraphics() {
	_vertexArray.clear();
	_vertexArray.resize(width()*height()*6);

	for (unsigned long i=0;i<width()*height();++i) {
		unsigned int tx = i%width();
		unsigned int ty = i/width();

		unsigned int tu = rawAt(i)%16;
		unsigned int tv = rawAt(i)/16;

		unsigned int ap = i*6;

		// triangle 1 position
		_vertexArray[ap+0].position = sf::Vector2f(tx*16, ty*16);
		_vertexArray[ap+1].position = sf::Vector2f(tx*16+16, ty*16);
		_vertexArray[ap+2].position = sf::Vector2f(tx*16, ty*16+16);

		// triangle 2 position
		_vertexArray[ap+3].position = sf::Vector2f(tx*16+16, ty*16+16);
		_vertexArray[ap+4].position = sf::Vector2f(tx*16+16, ty*16);
		_vertexArray[ap+5].position = sf::Vector2f(tx*16, ty*16+16);

		// triangle 1 texture
		_vertexArray[ap+0].texCoords = sf::Vector2f(tu*16, tv*16);
		_vertexArray[ap+1].texCoords = sf::Vector2f(tu*16+16, tv*16);
		_vertexArray[ap+2].texCoords = sf::Vector2f(tu*16, tv*16+16);

		// triangle 2 texture
		_vertexArray[ap+3].texCoords = sf::Vector2f(tu*16+16, tv*16+16);
		_vertexArray[ap+4].texCoords = sf::Vector2f(tu*16+16, tv*16);
		_vertexArray[ap+5].texCoords = sf::Vector2f(tu*16, tv*16+16);
	}
}
