#ifndef __ITEXTUREMANAGER__H_
#define __ITEXTUREMANAGER__H_

class ITextureManager
{
public:
	virtual ~ITextureManager() { };

	virtual void loadTexture()      const = 0;
	virtual void loadTextureAtlas() const = 0;
};

#endif