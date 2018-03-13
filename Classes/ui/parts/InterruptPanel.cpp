#include "InterruptPanel.h"


InterruptPanel::InterruptPanel(){
}

InterruptPanel::~InterruptPanel(){
}

void InterruptPanel::setParent(Node* parent){
	if(auto menu = dynamic_cast<Menu*>(parent)){
		menu->setTouchEnabled(false);
		// 画面操作を管理するシステムに干渉して、
		// 優先されているパネル数をカウントアップ
	}
	Menu::setParent(parent);
}

void InterruptPanel::getParent(){
	auto parent = Menu::getParent();
	if(parent == NULL) return nullptr;
	if(auto menu = dynamic_cast<Menu*>(parent)){
		// 画面操作を管理するシステムに干渉して、
		// 優先されているパネル数をカウントダウン
		// 0になったらTrueにする（※厳密にやると失敗するので、別解を考える）
		menu->setTouchEnabled(true);
	}
	return parent;
}

MenuItem* InterruptPanel::getItemForTouch(Touch * touch, const Camera *camera){
	return Menu::getItemForTouch(touch, camera);
}


