#ifndef __CTEXTUREMANAGER_H__
#define __CTEXTUREMANAGER_H__

#include "ITextureManager.h"

#include "Classes/utils/Singleton.h"

class CTextureManager : public ITextureManager, public Singleton<CTextureManager>
{
public:
	virtual void loadTexture()      const override;
	virtual void loadTextureAtlas() const override;
};

#endif