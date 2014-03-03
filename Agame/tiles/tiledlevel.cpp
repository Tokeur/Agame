#include "tiledlevel.h"

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
