#pragma once
#include "cocos2d.h"

// 花色类型
enum class CardSuitType {
    None = -1,
    Clubs,      // 梅花
    Diamonds,   // 方块
    Hearts,     // 红桃
    Spades      // 黑桃
};

/*

功能：单张卡牌的数据模型。

职责：保存数字、花色、是否翻开等状态。

使用场景：任何关于单张牌的数据查询与状态变更。

*/

class CardModel {
public:
    int cardId;
    std::string face; // 牌面值
    CardSuitType suit; // 花色
    cocos2d::Vec2 position; // 位置
    bool isFaceUp; // 是否翻面

    CardModel(int id = -1, std::string f = "0", CardSuitType s = CardSuitType::None, cocos2d::Vec2 pos = cocos2d::Vec2(0, 0), bool faceUp = true)
        :cardId(id), face(f), suit(s), position(pos), isFaceUp(faceUp) {}


};
