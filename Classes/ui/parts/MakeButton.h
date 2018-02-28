#pragma once
#include "../../setting/default.h"

class MakeButton {
public:
	MakeButton();

	MakeButton* label(string label);
	MakeButton* callfunc(Ref* _target, SEL_MenuHandler _selector);
	MakeButton* callfunc(const ccMenuCallback & _callback);

	MenuItemSprite* create();


private:
	string btn_default;
	string btn_press;
	Color3B label_color;
	string label_text;
	Ref* target;
	SEL_MenuHandler selector;
	ccMenuCallback callback;

};

