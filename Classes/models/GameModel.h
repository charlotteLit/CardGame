#pragma once

#include "cocos2d.h"
#include "CardModel.h"

/*

功能：存储整个游戏的状态数据。

职责：持有 PlayFieldModel、StackModel、UndoModel，记录当前关卡信息。

使用场景：游戏进行中，查询或更新全局状态。

*/

class GameModel {
private:
    CardModel* _stackTopCard;  // 堆牌区的顶牌
    std::vector<CardModel*> _stackCards;  // 堆牌区的卡牌
    std::vector<CardModel*> _playFieldCards;  // 主牌区的卡牌

public:
    // 构造函数
    GameModel() : _stackTopCard(nullptr) {}

    // 获取堆牌区顶牌，返回值为 CardModel
    CardModel* getStackTopCard() { return _stackTopCard; }

    // 获取堆牌区的卡牌向量，返回值为 CardModel 向量
    std::vector<CardModel*> getStackCards() { return _stackCards; }

    // 获取主牌区的卡牌向量，返回值为 CardModel 向量
    std::vector<CardModel*> getPlayFieldCards() { return _playFieldCards; }

    // 设置堆牌区的卡牌
    void setStackCards(const std::vector<CardModel*>& cards) { _stackCards = cards; }

    // 设置主牌区的卡牌
    void setPlayFieldCards(const std::vector<CardModel*>& cards) { _playFieldCards = cards; }

    // 设置堆牌区顶牌
    void setStackTopCard(CardModel* topCard) { _stackTopCard = topCard; }

};
