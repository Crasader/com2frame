#pragma once

#include "setting/default.h"

class SystemCore : public cocos2d::Scene
{
	Node* active_window_;
public:
	SystemCore();
	~SystemCore();

	static cocos2d::Scene* createScene();
	static SystemCore* instance();

	virtual bool init();

	/// ウィンドウ切り替え
	void changeWindow(Node* window);

	/// アプリ終了
	void applicationClose();


	// implement the "static create()" method manually
	CREATE_FUNC(SystemCore);
};


