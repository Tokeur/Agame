#ifndef TILEDLEVEL_H
#define TILEDLEVEL_H

class TiledLevel {
public:
	TiledLevel();
	TiledLevel(unsigned long w, unsigned long h);
	~TiledLevel();
	unsigned char at(unsigned long x, unsigned long y);
	unsigned long width();
	unsigned long height();
protected:
	void init_();
	void free_();
private:
	unsigned char* _tiles;
	unsigned long _w, _h;
};

#endif // TILEDLEVEL_H
