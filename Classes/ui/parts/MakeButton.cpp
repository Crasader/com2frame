#include "MakeButton.h"

TTFConfig ttfDefault("fonts/Marker Felt.ttf",
	30,
	GlyphCollection::DYNAMIC);

Label* GameLabel(string str) {
	auto label = Label::createWithTTF(ttfDefault, str);
	label->setColor(Color3B::BLACK);
	return label;
}


MakeButton::MakeButton() :
btn_default("btn/box_grey.png"),
btn_press("btn/box_red.png"),
label_color(),
label_text(""),
target(NULL),
selector(NULL),
callback(NULL)
{

}

MakeButton* MakeButton::label(string label) {
	label_text = label;
	return this;
}

MakeButton* MakeButton::callfunc(Ref* _target, SEL_MenuHandler _selector) {
	target = _target;
	selector = _selector;
	return this;
}

MakeButton* MakeButton::callfunc(const ccMenuCallback & _callback){
	callback = _callback;
	return this;
}

MenuItemSprite* MakeButton::create() {
	MenuItemImage* item;
	if (callback) {
		item = MenuItemImage::create(btn_default, btn_press, callback);
	}else {
		item = MenuItemImage::create(btn_default, btn_press, target, selector);
	}
	// label
	if (label_text.size()) {
		auto label = GameLabel(label_text);
		label->setPosition(item->getContentSize() / 2);
		item->addChild(label);
	}

	return item;
}
