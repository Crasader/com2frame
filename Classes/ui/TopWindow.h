#pragma once

#include "setting/default.h"

class TopWindow : public cocos2d::Node
{
public:
	static TopWindow* create();
	TopWindow();
	virtual ~TopWindow();

	virtual bool init();
	virtual void makeView();

};

