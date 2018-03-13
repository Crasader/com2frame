#include "BasePanel.h"


BasePanel::BasePanel(){
}

BasePanel::~BasePanel(){
}

void BasePanel::setParent(Node* parent){
	Menu::setParent(parent);
	parent_menu_ = dynamic_cast<Menu*>(parent);
}

MenuItem* BasePanel::getItemForTouch(Touch * touch, const Camera *camera){
    // 親が無効な場合にはタップを無効にする
	if(!(parent_menu_ && parent_menu_->getTouchEnabled())) return nullptr;
	return Menu::getItemForTouch(touch, camera);
}


