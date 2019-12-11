#include "CPaint.h"

CPaint::CPaint(const Color& color, const Vector2D& position, const Vector2D& size) : mColor(color)
{
	mPosition = position;
	mSize     = size; 
}

Color CPaint::getColor() const
{
	return mColor;
}

Vector2D CPaint::getPosition() const
{
	return mPosition;
}

Vector2D CPaint::getSize() const
{
	return mSize;
}