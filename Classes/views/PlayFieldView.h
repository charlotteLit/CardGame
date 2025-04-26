#ifndef PLAYFIELDVIEW_H
#define PLAYFIELDVIEW_H

#include "cocos2d.h"
#include "CardView.h"
#include "models/GameModel.h"

/*

功能：主牌区的显示界面。

职责：管理所有主牌区卡牌视图。

使用场景：主牌区卡牌生成、位置布局、动画播放。

*/

class PlayFieldView : public cocos2d::Sprite {
public:
    // 创建并初始化 PlayFieldView 实例，绑定到指定的 root 节点上
    static PlayFieldView* create(cocos2d::Node* root, GameModel* gameModel);
    
    // 初始化 PlayFieldView，创建卡牌视图并添加到 root 节点，设置初始布局。
    bool init(cocos2d::Node* root, GameModel* gameModel);

    // 根据 cardId 查找并返回对应的 CardView 指针
    CardView* getCardViewById(int cardId);

    // 设置卡牌点击回调函数
    void setClickCallback(std::function<void(int)> callback);

private:
    std::vector<CardView*> _cardViews;
    std::function<void(int)> _clickCallback; // 点击回调
};

#endif // PLAYFIELDVIEW_H

