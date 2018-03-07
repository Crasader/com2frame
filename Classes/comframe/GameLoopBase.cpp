#include "GameLoopBase.h"

GameLoopBase::GameLoopBase():
	scheduler_action(NULL), callfunc(NULL){

}

GameLoopBase::~GameLoopBase() {

}

GameLoopBase* GameLoopBase::create() {
	auto ret = new GameLoopBase();
	if (ret && ret->init()) {
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return NULL;
}

void GameLoopBase::setCallback(std::function<void(void)> callback) {
	callfunc = callback;
}


void GameLoopBase::execute() {
	if (scheduler_action) return;
	// 1�t���[��1��update�����s����
	scheduler_action = Node::create();
	addChild(scheduler_action);
	systemLoad();
	scheduler_action->runAction(RepeatForever::create(Sequence::create(
		CallFunc::create([this]() {this->update(0); }),
		NULL)
	));
}

void GameLoopBase::systemLoad() {

}

void GameLoopBase::update(float time) {
	finish();
}

void GameLoopBase::finish() {
	if (scheduler_action) {
		scheduler_action->stopAllActions();
		scheduler_action->removeFromParent();
		scheduler_action = NULL;

		callfunc();
	}
}
