#pragma once

#include "cocos2d.h"
#include <string>
#include <iterator>
#include <algorithm>
#include <functional>
#include <map>
#include <vector>
#include "common_function.h"

using namespace cocos2d;
using namespace std;

#define SYSTEM_FRAME_RATE 60
#define SYSTEM_WINDOW_WIDTH 800
#define SYSTEM_WINDOW_HEIGHT 600

#define SCREEN_SIZE (Director::getInstance()->getVisibleSize())


enum StatusType {
	statusHP = 0x01001000,
	statusATC,
	statusDEF,
	statusSPD,
};

enum ActionCommandCode {
	CMD_ATTACK = 0x02001001,
	CMD_RAND_ATTACK,
	CMD_ATTACK_SP1,

};

namespace CommonMethod {

	Label* GameLabel(string str);

	MenuItemImage* ButtonWhite(string str, const ccMenuCallback& callback);


}

