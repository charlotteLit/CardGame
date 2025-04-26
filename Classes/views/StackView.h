#ifndef STACK_VIEW_H
#define STACK_VIEW_H

#include "cocos2d.h"
#include "CardView.h"
#include "models/GameModel.h"

/*

���ܣ���������������ʾ���档

ְ�𣺹���ǰ�������Ƶ���ʾ�붯����

ʹ�ó����������������ƶѡ�����չʾ��

*/

class StackView : public cocos2d::Sprite {
public:
    // ��������ʼ�� StackView ʵ�����󶨵�ָ���� root �ڵ���
    static StackView* create(cocos2d::Node* root, GameModel* gameModel);

    // ��ʼ�� StackView������������ͼ����ӵ� root �ڵ㣬���ó�ʼ���֡�
    bool init(cocos2d::Node* root, GameModel* gameModel);

    // ��ȡָ�� cardId ��Ӧ�� CardView
    CardView* getCardViewById(int cardId);

    // ���ÿ��Ƶ���ص�����
    void setClickCallback(std::function<void(int)> callback); // ���ûص�


private:
    std::vector<CardView*> _remainingCards;  //������
    std::function<void(int)> _clickCallback; // ����ص�
};

#endif // STACK_VIEW_H

