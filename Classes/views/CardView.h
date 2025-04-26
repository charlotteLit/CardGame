#pragma once
#ifndef __CARD_VIEW_H
#define __CARD_VIEW_H

#include "cocos2d.h"
#include "models\CardModel.h"

/*

功能：单张卡牌的显示组件。

职责：显示卡牌数字、花色。

使用场景：用户点击卡牌匹配时进行视觉反馈。

*/

class CardView : public cocos2d::Sprite {
public:

    // 通过传入的 CardModel ，创建CardView对象，添加回调函数
    static CardView* create(CardModel* model);

    //通过传入的 CardModel ，选择图片资源，创建卡牌view对象
    bool init(CardModel* model); 
    
    // 返回该view对应的 CardModel 对象
    CardModel* getCardModel();
    
    //注册的回调函数，用户点击时触发，并交由controller处理
    void setClickCallback(std::function<void(int)> callback);

    /*CREATE_FUNC(CardView);*/
private:
    CardModel* _model;
    std::function<void(int)> _clickCallback;
};
#endif // __CARD_VIEW_H
