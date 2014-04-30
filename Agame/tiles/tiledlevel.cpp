#include "tiledlevel.h"
#include <SFML/Graphics.hpp>

TiledLevel::TiledLevel() {
	_w=_h=0;
	_tiles=0;
}

TiledLevel::TiledLevel(unsigned long w, unsigned long h) {
	_w=w;
	_h=h;

	init_();
}

TiledLevel::~TiledLevel() {
	free_();
}

void TiledLevel::loadFromImage(std::string fname) {
	sf::Image img;

	if (!img.loadFromFile(fname)) {
		// TODO: handle error lol
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

void TiledLevel::saveToImage(std::string fname) const {
	sf::Image img;

	img.create(_w, _h);

	for (unsigned long ix=0;ix<_w;ix++) {
		for (unsigned long iy=0;iy<_h;iy++) {
			img.setPixel(ix, iy, sf::Color(at(ix, iy), 128, 128));
		}
	}

	img.saveToFile(fname);
}

unsigned char& TiledLevel::at(unsigned long x, unsigned long y) {
	if (_w!=0 && _h!=0)
		if (x<_w && y<_h)
			return _tiles[y*_w+x];
	return _tiles[-1];
}

unsigned char TiledLevel::at(unsigned long x, unsigned long y) const {
	if (_w!=0 && _h!=0)
		if (x<_w && y<_h)
			return _tiles[y*_w+x];
	return 0;
}

unsigned long TiledLevel::width() const {
	return _w;
}

unsigned long TiledLevel::height() const {
	return _h;
}

void TiledLevel::reset() {
	if (_w!=0 && _h!=0) {
		free_();
		init_();
	}
}

void TiledLevel::reset(unsigned long w, unsigned long h) {
	_w=w;
	_h=h;

	reset();
}

void TiledLevel::init_() {
	_tiles = new unsigned char[_w*_h];

	for (unsigned long long i=0;i<_w*_h;i++)
		_tiles[i]=0;
}

void TiledLevel::free_() {
	delete[] _tiles;
	_tiles=0;
}

unsigned char TiledLevel::rawAt(unsigned long long n) const {
	return _tiles[n];
}

unsigned char& TiledLevel::rawAt(unsigned long long n) {
	return _tiles[n];
}
