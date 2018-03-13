#pragma once
#include "../../setting/default.h"

class BasePanel : public Menu {
public:
	BasePanel();
	virtual ~BasePanel();
	static BasePanel* create();
	
	/// overwrite CCNode::setParent
	virtual void setParent(Node* parent);

protected:
    /// overwrite CCMenu::itemForTouch
	// virtual CCMenuItem* itemForTouch(CCTouch * touch);
    virtual MenuItem* getItemForTouch(Touch * touch, const Camera *camera);

private:
	Menu* parent_menu_;
	
}
