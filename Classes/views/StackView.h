#ifndef STACK_VIEW_H
#define STACK_VIEW_H

#include "cocos2d.h"
#include "CardView.h"
#include "models/GameModel.h"

/*

功能：备用手牌区的显示界面。

职责：管理当前备用手牌的显示与动画。

使用场景：堆牌区补充牌堆、动画展示。

*/

class StackView : public cocos2d::Sprite {
public:
    // 创建并初始化 StackView 实例，绑定到指定的 root 节点上
    static StackView* create(cocos2d::Node* root, GameModel* gameModel);

    // 初始化 StackView，创建卡牌视图并添加到 root 节点，设置初始布局。
    bool init(cocos2d::Node* root, GameModel* gameModel);

    // 获取指定 cardId 对应的 CardView
    CardView* getCardViewById(int cardId);

    // 设置卡牌点击回调函数
    void setClickCallback(std::function<void(int)> callback); // 设置回调


private:
    std::vector<CardView*> _remainingCards;  //备用牌
    std::function<void(int)> _clickCallback; // 点击回调
};

#endif // STACK_VIEW_H

