#pragma once

#include "models/GameModel.h"
#include "managers/UndoManager.h"
#include "views/GameView.h"
#include "cocos2d.h"

USING_NS_CC;

class StackController;
class PlayFieldController;

/*

功能：游戏总控制器，负责初始化、启动关卡，协调各子控制器。

职责：加载关卡配置，创建 GameModel，初始化 PlayFieldController、StackController、UndoManager，处理关卡重置、回退等高层操作。

使用场景：玩家选择关卡后调用 startGame(levelId)，启动游戏流程。

*/

class GameController {
private:
    GameModel* _gameModel;
    UndoManager* _undoManager;
    GameView* _gameView;

public:
    // 构造函数，初始化类时默认调用
    GameController();
    // 根据传入的levelId，初始化各子控制器，回退类，并返回建立的游戏场景
    Scene* startGame(const std::string& levelId);
    
    //初始化
    void initControllers();

    // 获取游戏模型
    GameModel* getGameModel() { return _gameModel; }
    GameView* getGameView() { return _gameView; }

};
