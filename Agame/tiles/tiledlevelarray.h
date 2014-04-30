#ifndef TILEDLEVELARRAY_H
#define TILEDLEVELARRAY_H

#include <string>

class TiledLevelArray {
public:
	TiledLevelArray();
	TiledLevelArray(unsigned long w, unsigned long h);
	~TiledLevelArray();

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

#endif // TILEDLEVELARRAY_H
