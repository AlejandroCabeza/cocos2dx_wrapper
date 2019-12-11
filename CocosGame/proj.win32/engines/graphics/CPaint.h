#ifndef __CPAINT_H__
#define __CPAINT_H__

#include "IPaint.h"

class CPaint : public IPaint
{
private:
	Color    mColor;
	Vector2D mPosition;
	Vector2D mSize;

public:
	CPaint(const Color& color, const Vector2D& position, const Vector2D& size);

	virtual Color    getColor()    const override;
	virtual Vector2D getPosition() const override;
	virtual Vector2D getSize()     const override;
};

#endif