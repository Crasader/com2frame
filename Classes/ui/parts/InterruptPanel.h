#pragma once
#include "BasePanel.h"

class InterruptPanel : public BasePanel {
public:
	InterruptPanel();
	virtual ~InterruptPanel();
	static InterruptPanel* create();
	
	/// overwrite CCNode::setParent
	virtual void setParent(Node* parent);

protected:
    virtual MenuItem* getItemForTouch(Touch * touch, const Camera *camera);

}
