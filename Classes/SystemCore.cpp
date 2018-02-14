#include "SystemCore.h"
#include "SimpleAudioEngine.h"
#include "ui/TopWindow.h"

USING_NS_CC;

static SystemCore* instance_ = NULL;

SystemCore::SystemCore(){
	
}

SystemCore::~SystemCore() {
	instance_ = NULL;
}


Scene* SystemCore::createScene()
{
	auto ret = SystemCore::create();
	instance_ = ret;
	return ret;
}

SystemCore* SystemCore::instance() {
	return instance_;
}


// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in SystemCore.cpp\n");
}

// on "init" you need to initialize your instance
bool SystemCore::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}

	// TODO: window切り替え拡張の時に、細かい切り替え制御をできるようにする
	active_window_ = TopWindow::create();
	addChild(active_window_);

	return true;
}

/// ウィンドウ切り替え
void SystemCore::changeWindow(Node* window)
{
	// TODO: window切り替え拡張の時に、細かい切り替え制御をできるようにする
	active_window_->removeFromParent();
	addChild(window);
	active_window_ = window;
}

/// アプリ終了
void SystemCore::applicationClose()
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif

	/*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

	//EventCustom customEndEvent("game_scene_close_event");
	//_eventDispatcher->dispatchEvent(&customEndEvent);


}

