#include "GameLoop01.h"
#include "ui/parts/MakeButton.h"
#include "comframe/GameLoopBase.h"

struct CallWindowSetting2 {
	string name;
	cocos2d::SEL_MenuHandler callfunc;

	CallWindowSetting2(string name, SEL_MenuHandler method) : name(name), callfunc(method) {
	};

};

vector<CallWindowSetting2> event_list = {
	CallWindowSetting2("Start", menu_selector(GameLoop01Window::systemStart)),

};



GameLoop01Window* GameLoop01Window::create() {
	auto ret = new GameLoop01Window();
	if (ret && ret->init()) {
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return NULL;
}

GameLoop01Window::GameLoop01Window() {

}

GameLoop01Window::~GameLoop01Window() {

}

bool GameLoop01Window::init() {
	makeView();
	return true;
}

void GameLoop01Window::makeView() {

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto menu = Menu::create();
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	int count = 0;
	for (auto event : event_list) {
		auto item = (new MakeButton())->label(event.name)->callfunc(this, event.callfunc)->create();
		menu->addChild(item);
		float x = item->getContentSize().width / 2 + 10;
		float y = visibleSize.height - item->getContentSize().height / 2;
		auto size = Vec2(10, 10) + item->getContentSize();
		item->setPosition(Vec2(x, y) + Vec2(size.x * (count % 4), size.y * (count / 4)));
		CCLOG("%d %d", size.x, size.y);

		count++;
	}
}

// テスト用のゲームループを開始する
void GameLoop01Window::systemStart(Ref* ref) {
	CCLOG("systemStart");

	auto game = GameLoopBase::create([this]() { this->gameFinish(); });
	addChild(game);
	game->execute();

	/*
	ログを表示するエリアを作る
	ゲームループを開始する
	ログ表示エリアにゲームループの今の状態を逐一更新する


	*/

}

// ゲームループ終了
void GameLoop01Window::gameFinish() {

}

