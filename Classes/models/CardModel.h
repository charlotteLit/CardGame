#pragma once
#include "cocos2d.h"

// ��ɫ����
enum class CardSuitType {
    None = -1,
    Clubs,      // ÷��
    Diamonds,   // ����
    Hearts,     // ����
    Spades      // ����
};

/*

���ܣ����ſ��Ƶ�����ģ�͡�

ְ�𣺱������֡���ɫ���Ƿ񷭿���״̬��

ʹ�ó������κι��ڵ����Ƶ����ݲ�ѯ��״̬�����

*/

class CardModel {
public:
    int cardId;
    std::string face; // ����ֵ
    CardSuitType suit; // ��ɫ
    cocos2d::Vec2 position; // λ��
    bool isFaceUp; // �Ƿ���

    CardModel(int id = -1, std::string f = "0", CardSuitType s = CardSuitType::None, cocos2d::Vec2 pos = cocos2d::Vec2(0, 0), bool faceUp = true)
        :cardId(id), face(f), suit(s), position(pos), isFaceUp(faceUp) {}


};
