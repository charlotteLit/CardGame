#pragma once
#ifndef __STACK_CONTROLLER_H__
#define __STACK_CONTROLLER_H__

#include <vector>
#include "GameController.h"
#include "views/StackView.h"
#include "models/CardModel.h"
#include "models/GameModel.h"
#include "views/CardView.h"
#include "managers/UndoManager.h"

USING_NS_CC;

/*

���ܣ���������������Stack���Ŀ����߼���

ְ�𣺴���������ķ��ơ����������߼���ͬ������ StackModel �� StackView��

ʹ�ó����������û�п�ƥ����ʱ����� Stack �������ơ�

*/

class StackController : public Ref {
public:
    
    //Ĭ�Ϲ��캯���������ϲ㴫�ݵĿ������ȳ�ʼ����Ϣ
    StackController(GameController* gameController, GameModel* gameModel, UndoManager* undoManager);

    // ��ʼ�� StackController
    void init();

    // ��ʼ����ͼ����ӵ����ڵ�
    void initView(cocos2d::Node* parent);

    // ���ڽ��տ��Ƶ���¼�
    void onCardClicked(int cardId);

    //ʵ�ֿ��Ƶĵ�������ƶ����Լ�������ƥ��
    void onStackCardClicked(int cardId);



private:
    // ��ͼ��
    StackView* _stackView;

    std::vector<CardModel*> _stackCards;

    cocos2d::Node* _rootNode = nullptr;

    GameModel* _gameModel;
    GameController* _gameController;

    UndoManager* _undoManager;
};

#endif // __STACK_CONTROLLER_H__
