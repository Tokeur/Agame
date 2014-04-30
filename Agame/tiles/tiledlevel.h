#ifndef TILEDLEVEL_H
#define TILEDLEVEL_H

#include <string>

/* TiledLevel by Stan "DeinDall" (C) 2014 */

class TiledLevel {
public:
	TiledLevel();
	TiledLevel(unsigned long w, unsigned long h);
	~TiledLevel();

	void loadFromImage(std::string fname);

	unsigned char at(unsigned long x, unsigned long y) const;
	unsigned char& at(unsigned long x, unsigned long y);

	unsigned long width();
	unsigned long height();

	void reset();
	void reset(unsigned long w, unsigned long h);
protected:
	void init_();
	void free_();
private:
	unsigned char* _tiles;
	unsigned long _w, _h;
};

#endif // TILEDLEVEL_H
