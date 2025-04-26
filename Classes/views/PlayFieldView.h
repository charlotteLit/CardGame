#ifndef PLAYFIELDVIEW_H
#define PLAYFIELDVIEW_H

#include "cocos2d.h"
#include "CardView.h"
#include "models/GameModel.h"

/*

���ܣ�����������ʾ���档

ְ�𣺹�������������������ͼ��

ʹ�ó������������������ɡ�λ�ò��֡��������š�

*/

class PlayFieldView : public cocos2d::Sprite {
public:
    // ��������ʼ�� PlayFieldView ʵ�����󶨵�ָ���� root �ڵ���
    static PlayFieldView* create(cocos2d::Node* root, GameModel* gameModel);
    
    // ��ʼ�� PlayFieldView������������ͼ����ӵ� root �ڵ㣬���ó�ʼ���֡�
    bool init(cocos2d::Node* root, GameModel* gameModel);

    // ���� cardId ���Ҳ����ض�Ӧ�� CardView ָ��
    CardView* getCardViewById(int cardId);

    // ���ÿ��Ƶ���ص�����
    void setClickCallback(std::function<void(int)> callback);

private:
    std::vector<CardView*> _cardViews;
    std::function<void(int)> _clickCallback; // ����ص�
};

#endif // PLAYFIELDVIEW_H

