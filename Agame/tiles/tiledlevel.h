#ifndef TILEDLEVEL_H
#define TILEDLEVEL_H

#include <string>

class TiledLevel {
public:
	TiledLevel();
	TiledLevel(unsigned long w, unsigned long h);
	~TiledLevel();

	void loadFromImage(std::string fname);
	void saveToImage(std::string fname) const;

	unsigned char at(unsigned long x, unsigned long y) const;
	unsigned char& at(unsigned long x, unsigned long y);

	unsigned long width() const;
	unsigned long height() const;

	void reset();
	void reset(unsigned long w, unsigned long h);
protected:
	void init_();
	void free_();

	unsigned char rawAt(unsigned long long n) const;
	unsigned char& rawAt(unsigned long long n);
private:
	unsigned char* _tiles;
	unsigned long _w, _h;
};

#endif // TILEDLEVEL_H
