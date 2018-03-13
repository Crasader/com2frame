#pragma once
#include "BasePanel.h"

class TestButtons : public BasePanel {
public:
	TestButtons();
	virtual ~TestButtons();
	static TestButtons* create();
	
	void registUseEnergyA(std::function<void(int) > callback);
	void registUseEnergyB(std::function<void(int) > callback);
	
protected:
	void onButtonA(Ref* r);
	void onButtonB(Ref* r);


private:
	std::function<void(int)> buttonA_callback_;
	std::function<void(int)> buttonB_callback_;
	
}
