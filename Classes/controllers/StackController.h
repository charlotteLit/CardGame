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

功能：管理备用手牌区（Stack）的卡牌逻辑。

职责：处理堆牌区的翻牌、补充新牌逻辑，同步更新 StackModel 和 StackView。

使用场景：玩家在没有可匹配牌时，点击 Stack 翻开新牌。

*/

class StackController : public Ref {
public:
    
    //默认构造函数，根据上层传递的控制器等初始化信息
    StackController(GameController* gameController, GameModel* gameModel, UndoManager* undoManager);

    // 初始化 StackController
    void init();

    // 初始化视图，添加到父节点
    void initView(cocos2d::Node* parent);

    // 用于接收卡牌点击事件
    void onCardClicked(int cardId);

    //实现卡牌的点击动画移动，以及点数的匹配
    void onStackCardClicked(int cardId);



private:
    // 视图层
    StackView* _stackView;

    std::vector<CardModel*> _stackCards;

    cocos2d::Node* _rootNode = nullptr;

    GameModel* _gameModel;
    GameController* _gameController;

    UndoManager* _undoManager;
};

#endif // __STACK_CONTROLLER_H__
