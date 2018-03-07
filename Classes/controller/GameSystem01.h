#pragma once

#include "../setting/default.h"
#include "../comframe/GameLoopBase.h"

class GameSystem01 : public GameLoopBase {
public:
	GameSystem01();
	static GameSystem01* create(std::function<void(void)> callback);


	virtual void update(float time);

private:
	int count;


};