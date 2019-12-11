#ifndef __VECTOR2D__CPP_
#define __VECTOR2D__CPP_

#include "Vector2D.h"

Vector2D::Vector2D()
{
	mX = 0;
	mY = 0;
}

Vector2D::Vector2D(float x, float y)
{
	mX = x;
	mY = y;
}

float Vector2D::getX() const
{
	return mX;
}

float Vector2D::getY() const
{
	return mY;
}

void Vector2D::setX(float x)
{
	mX = x;
}

void Vector2D::setY(float y)
{
	mY = y;
}

#endif