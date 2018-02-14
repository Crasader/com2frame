#include "default.h"

TTFConfig ttfDefault("fonts/Marker Felt.ttf",
	30,
	GlyphCollection::DYNAMIC);

Label* CommonMethod::GameLabel(string str) {
	auto label = Label::createWithTTF(ttfDefault, str);
	label->setColor(Color3B::BLACK);
	return label;
}
MenuItemImage * CommonMethod::ButtonWhite(string str, const ccMenuCallback & callback)
{
	auto item = MenuItemImage::create(
		"btn/box_grey.png",
		"btn/box_red.png",
		callback
	);
	// label
	auto label = CommonMethod::GameLabel(str);
	label->setPosition(item->getContentSize() / 2);
	item->addChild(label);

	return item;
};



