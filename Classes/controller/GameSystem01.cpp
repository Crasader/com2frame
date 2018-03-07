#include "GameSystem01.h"

GameSystem01::GameSystem01():
	count(0) {

}

GameSystem01* create(std::function<void(void)> callback) {
	auto ret = new GameSystem01();
	if (ret && ret->init()) {
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return ret;
}

void GameSystem01::update(float time) {
	if (count++ > 100) {
		finish();
	}
}
