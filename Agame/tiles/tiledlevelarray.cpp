#include "tiledlevelarray.h"
#include "utility/logger.h"

#include <SFML/Graphics.hpp>

TiledLevelArray::TiledLevelArray() {
	_w=_h=0;
	_tiles=0;
}

TiledLevelArray::TiledLevelArray(unsigned long w, unsigned long h) {
	_w=w;
	_h=h;

	init_();
}

TiledLevelArray::~TiledLevelArray() {
	free_();
}

void TiledLevelArray::loadFromImage(std::string fname) {
	sf::Image img;

	if (!img.loadFromFile(fname)) {
		Logger::log("ERROR when loading TiledLevelArray from image file ", fname);
	}

	_w=img.getSize().x;
	_h=img.getSize().y;

	reset();

	for (unsigned long ix=0;ix<_w;ix++) {
		for (unsigned long iy=0;iy<_h;iy++) {
			at(ix, iy) = img.getPixel(ix, iy).r;
		}
	}
}

void TiledLevelArray::saveToImage(std::string fname) const {
	sf::Image img;

	img.create(_w, _h);

	for (unsigned long ix=0;ix<_w;ix++) {
		for (unsigned long iy=0;iy<_h;iy++) {
			img.setPixel(ix, iy, sf::Color(at(ix, iy), 128, 128));
		}
	}

	if (!img.saveToFile(fname)) {
		Logger::log("ERROR when loading TiledLevelArray from image file ", fname);
	}
}

unsigned char& TiledLevelArray::at(unsigned long x, unsigned long y) {
	if (_w!=0 && _h!=0)
		if (x<_w && y<_h)
			return _tiles[y*_w+x];
	return _tiles[-1];
}

unsigned char TiledLevelArray::at(unsigned long x, unsigned long y) const {
	if (_w!=0 && _h!=0)
		if (x<_w && y<_h)
			return _tiles[y*_w+x];
	return 0;
}

unsigned long TiledLevelArray::width() const {
	return _w;
}

unsigned long TiledLevelArray::height() const {
	return _h;
}

void TiledLevelArray::reset() {
	if (_w!=0 && _h!=0) {
		free_();
		init_();
	}
}

void TiledLevelArray::reset(unsigned long w, unsigned long h) {
	_w=w;
	_h=h;

	reset();
}

void TiledLevelArray::init_() {
	_tiles = new unsigned char[_w*_h];

	for (unsigned long long i=0;i<_w*_h;i++)
		_tiles[i]=0;
}

void TiledLevelArray::free_() {
	delete[] _tiles;
	_tiles=0;
}

unsigned char TiledLevelArray::rawAt(unsigned long long n) const {
	return _tiles[n];
}

unsigned char& TiledLevelArray::rawAt(unsigned long long n) {
	return _tiles[n];
}
