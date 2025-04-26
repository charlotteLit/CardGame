#pragma once
#ifndef __PLAY_FIELD_CONTROLLER_H__
#define __PLAY_FIELD_CONTROLLER_H__

#include <vector>
#include "GameController.h"
#include "views/PlayFieldView.h"
#include "views/CardView.h"
#include "models/CardModel.h"
#include "models/GameModel.h"
#include "managers/UndoManager.h"

USING_NS_CC;

/*

���ܣ�������������Playfield���Ŀ����߼���

ְ�𣺴������������Ƶĵ����ƥ����߼���ͬ������ PlayFieldModel �� PlayFieldView��

ʹ�ó�������ҵ���������Ŀ��ƣ�����ƥ�䡣

*/

class PlayFieldController : public Ref {
public:
    //Ĭ�Ϲ��캯���������ϲ㴫�ݵĿ������ȳ�ʼ����Ϣ
    PlayFieldController(GameController* gameController, GameModel* gameModel, UndoManager* undoManager);
    
    //��ʼ������
    void init();

    // ��ʼ����ͼ����ӵ����ڵ�
    void initView(cocos2d::Node* root);

    // ���ڽ��տ��Ƶ���¼�
    void onCardClicked(int cardId);

    //ʵ�ֿ��Ƶĵ�������ƶ����Լ�������ƥ��
    void onPlayFieldCardClicked(int cardId);

  
private:
    // ��ͼ��
    PlayFieldView* _playFieldView;
    
    std::vector<CardModel*> _playFieldCards;

    GameModel* _gameModel;
    GameController* _gameController;

    cocos2d::Node* _rootNode = nullptr;

    UndoManager* _undoManager;
};

#endif // __PLAY_FIELD_CONTROLLER_H__