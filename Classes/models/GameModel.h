#pragma once

#include "cocos2d.h"
#include "CardModel.h"

/*

���ܣ��洢������Ϸ��״̬���ݡ�

ְ�𣺳��� PlayFieldModel��StackModel��UndoModel����¼��ǰ�ؿ���Ϣ��

ʹ�ó�������Ϸ�����У���ѯ�����ȫ��״̬��

*/

class GameModel {
private:
    CardModel* _stackTopCard;  // �������Ķ���
    std::vector<CardModel*> _stackCards;  // �������Ŀ���
    std::vector<CardModel*> _playFieldCards;  // �������Ŀ���

public:
    // ���캯��
    GameModel() : _stackTopCard(nullptr) {}

    // ��ȡ���������ƣ�����ֵΪ CardModel
    CardModel* getStackTopCard() { return _stackTopCard; }

    // ��ȡ�������Ŀ�������������ֵΪ CardModel ����
    std::vector<CardModel*> getStackCards() { return _stackCards; }

    // ��ȡ�������Ŀ�������������ֵΪ CardModel ����
    std::vector<CardModel*> getPlayFieldCards() { return _playFieldCards; }

    // ���ö������Ŀ���
    void setStackCards(const std::vector<CardModel*>& cards) { _stackCards = cards; }

    // �����������Ŀ���
    void setPlayFieldCards(const std::vector<CardModel*>& cards) { _playFieldCards = cards; }

    // ���ö���������
    void setStackTopCard(CardModel* topCard) { _stackTopCard = topCard; }

};
