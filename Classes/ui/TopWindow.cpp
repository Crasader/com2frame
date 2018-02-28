#include "TopWindow.h"
#include "ui/window/GameLoop01.h"
#include "../SystemCore.h"
#include "ui/parts/MakeButton.h"

struct CallWindowSetting {
	string name;
	std::function<void(Ref*)> callfunc;

	CallWindowSetting(string name, ccMenuCallback method) : name(name), callfunc(method) {
		};
};

vector<CallWindowSetting> event_list = {
	CallWindowSetting("Loop1", [](Ref* r) { SystemCore::instance()->changeWindow(GameLoop01Window::create()); }),
	CallWindowSetting("test2", [](Ref* r) {  }),
	CallWindowSetting("test3", [](Ref* r) { CCLOG("CCC"); }),

};



TopWindow* TopWindow::create() {
	auto ret = new TopWindow();
	if (ret && ret->init()) {
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return NULL;
}

TopWindow::TopWindow() {

}

TopWindow::~TopWindow() {

}

bool TopWindow::init() {
	makeView();
	return true;
}

void TopWindow::makeView() {

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto menu = Menu::create();
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	int count = 0;
	for (auto event : event_list) {
		auto item = (new MakeButton())->label(event.name)->callfunc(event.callfunc)->create();
		menu->addChild(item);
		float x = item->getContentSize().width/2 + 10;
		float y = visibleSize.height - item->getContentSize().height/2;
		auto size = Vec2(10,10) + item->getContentSize();
		item->setPosition(Vec2(x, y) + Vec2(size.x * (count%4), size.y * (count/4)));
		CCLOG("%d %d", size.x, size.y);

		count++;
	}


}
