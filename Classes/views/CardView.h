#pragma once
#ifndef __CARD_VIEW_H
#define __CARD_VIEW_H

#include "cocos2d.h"
#include "models\CardModel.h"

/*

���ܣ����ſ��Ƶ���ʾ�����

ְ����ʾ�������֡���ɫ��

ʹ�ó������û��������ƥ��ʱ�����Ӿ�������

*/

class CardView : public cocos2d::Sprite {
public:

    // ͨ������� CardModel ������CardView������ӻص�����
    static CardView* create(CardModel* model);

    //ͨ������� CardModel ��ѡ��ͼƬ��Դ����������view����
    bool init(CardModel* model); 
    
    // ���ظ�view��Ӧ�� CardModel ����
    CardModel* getCardModel();
    
    //ע��Ļص��������û����ʱ������������controller����
    void setClickCallback(std::function<void(int)> callback);

    /*CREATE_FUNC(CardView);*/
private:
    CardModel* _model;
    std::function<void(int)> _clickCallback;
};
#endif // __CARD_VIEW_H
