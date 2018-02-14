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

	/// �E�B���h�E�؂�ւ�
	void changeWindow(Node* window);

	/// �A�v���I��
	void applicationClose();


	// implement the "static create()" method manually
	CREATE_FUNC(SystemCore);
};


