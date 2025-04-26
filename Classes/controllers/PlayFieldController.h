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

功能：管理主牌区（Playfield）的卡牌逻辑。

职责：处理主牌区卡牌的点击、匹配等逻辑，同步更新 PlayFieldModel 和 PlayFieldView，

使用场景：玩家点击主牌区的卡牌，触发匹配。

*/

class PlayFieldController : public Ref {
public:
    //默认构造函数，根据上层传递的控制器等初始化信息
    PlayFieldController(GameController* gameController, GameModel* gameModel, UndoManager* undoManager);
    
    //初始化函数
    void init();

    // 初始化视图，添加到父节点
    void initView(cocos2d::Node* root);

    // 用于接收卡牌点击事件
    void onCardClicked(int cardId);

    //实现卡牌的点击动画移动，以及点数的匹配
    void onPlayFieldCardClicked(int cardId);

  
private:
    // 视图层
    PlayFieldView* _playFieldView;
    
    std::vector<CardModel*> _playFieldCards;

    GameModel* _gameModel;
    GameController* _gameController;

    cocos2d::Node* _rootNode = nullptr;

    UndoManager* _undoManager;
};

#endif // __PLAY_FIELD_CONTROLLER_H__