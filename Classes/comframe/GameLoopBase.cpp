#include "GameLoopBase.h"

GameLoopBase::GameLoopBase() {

}

GameLoopBase::~GameLoopBase() {

}

GameLoopBase* GameLoopBase::create(std::function<void(void)> callback) {
	return NULL;
}

void GameLoopBase::execute() {

}

void GameLoopBase::systemLoad() {

}

void GameLoopBase::update(float time) {

}

void GameLoopBase::finish() {

}
