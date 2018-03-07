#pragma once

#include "../setting/default.h"

class GameLoopBase : public Node {
public:
	GameLoopBase();
	~GameLoopBase();

	static GameLoopBase* create();

	void setCallback(std::function<void(void)> callback);
	virtual void execute();

protected:
	virtual void systemLoad();
	virtual void update(float time);
	virtual void finish();

private:
	Node* scheduler_action;
	std::function<void(void)> callfunc;



};