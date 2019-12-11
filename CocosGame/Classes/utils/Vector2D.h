#ifndef __VECTOR2D__H_
#define __VECTOR2D__H_

class Vector2D
{
private:
	float mX;
	float mY;

public:
	Vector2D();
	Vector2D(float x, float y);

	float getX() const;
	float getY() const;

	void setX(float x);
	void setY(float y);
};

#endif 