#pragma once

#include "setting/default.h"

class GameLoop01Window : public cocos2d::Node
{
public:
	static GameLoop01Window* create();
	GameLoop01Window();
	virtual ~GameLoop01Window();

	virtual bool init();
	virtual void makeView();

	// �e�X�g�p�̃Q�[�����[�v���J�n����
	void systemStart();

};

