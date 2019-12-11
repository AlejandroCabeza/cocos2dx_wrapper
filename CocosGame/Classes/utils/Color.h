#ifndef __COLOR_H__
#define __COLOR_H__

#include <string>

class Color
{
private:
	unsigned char mR;
	unsigned char mG;
	unsigned char mB;
	unsigned char mAlpha;

public:
	Color(unsigned char r, unsigned char g, unsigned char b, unsigned char alpha);
	Color(const Color& color);
	
	void setR    (unsigned char r);
	void setG    (unsigned char g);
	void setB    (unsigned char b);
	void setAlpha(unsigned char alpha);

	unsigned char getR()        const;
	unsigned char getG()        const;
	unsigned char getB()        const;
	unsigned char getAlpha()    const;

	unsigned long toHex()       const;
	std::string toHexInString() const;
};

#endif
