#ifndef __IPAINT__H_
#define __IPAINT__H_

#include "Classes/utils/Color.h"
#include "Classes/utils/Vector2D.h"

typedef unsigned char byte;

class IPaint
{
public:
	virtual ~IPaint() { };

	virtual Vector2D getPosition() const = 0;
	virtual Vector2D getSize()     const = 0;
	virtual Color    getColor()    const = 0;
};

#endif 