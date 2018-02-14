#pragma once

#include "../setting/default.h"

class GameLoopBase : public Node {
public:
	GameLoopBase();
	~GameLoopBase();

	static GameLoopBase* create(std::function<void(void)> callback);

	virtual void execute();

protected:
	virtual void systemLoad();
	virtual void update(float time);
	virtual void finish();




};