#pragma once
#include "BasePanel.h"

class TitlePanel : public BasePanel {
	/*
	体力情報とその回復までにかかる時間を表示する
	*/
	
publicd:
	TitlePanel();
	~TitlePanel();
	static TitlePanel* create();
	
	// 体力が更新された時にイベントを発生させる
	// これは本来Observerが持つべきなので、あくまで仮の機能
	void registEnergyCallback(std::function<void(void)> callback);
	
	void addEnergy(int point);
	int getEnergy();

protected:
	// 体力が最大以下になった時にタイマーを開始する
	// タイマーが一定値を超えたところで体力を一つ回復する
	// 回復した時に体力が最大値に到達したところでタイマーを停止する
	void refreshEnergy();

private:
	// 体力回復をカウントするためのアクションが入っているNode
	Node* update_timer_;
	std::function<void(int)> callback_energy_;

	
}
