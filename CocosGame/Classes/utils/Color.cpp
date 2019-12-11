#ifndef __COLOR_CPP__
#define __COLOR_CPP__

#include "Color.h"

#include <iostream>
#include <sstream>
#include <iomanip>

Color::Color(unsigned char r, unsigned char g, unsigned char b, unsigned char alpha)
{
	mR = r;
	mG = g;
	mB = b;
	mAlpha = alpha;
}

Color::Color(const Color& color)
{
	mR     = color.getR();
	mG     = color.getG();
	mB     = color.getB();
	mAlpha = color.getAlpha();
}

void Color::setR(unsigned char r)
{
	mR = r;
}

void Color::setG(unsigned char g)
{
	mG = g;
}

void Color::setB(unsigned char b)
{
	mB = b;
}

void Color::setAlpha(unsigned char alpha)
{
	mAlpha = alpha;
}

unsigned char Color::getR() const
{
	return mR;
}

unsigned char Color::getG() const
{
	return mG;
}

unsigned char Color::getB() const
{
	return mB;
}

unsigned char Color::getAlpha() const
{
	return mAlpha;
}

unsigned long Color::toHex() const
{
	return ((mR & 0xff) << 24) + ((mG & 0xff) << 16) + ((mB & 0xff) << 8) + (mAlpha & 0xff);
}

std::string Color::toHexInString() const
{
	std::stringstream stream;
	stream << std::hex << toHex();
	std::string result(stream.str());
	return result;
}

#endif