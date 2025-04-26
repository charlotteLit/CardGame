#ifndef __GAME_VIEW_H__
#define __GAME_VIEW_H__

#include "models/GameModel.h"
#include "CardView.h"
#include "StackView.h"
#include "PlayFieldView.h"
#include "cocos2d.h"
#include "managers/UndoManager.h"

/*

功能：游戏主界面，组织各子界面布局。

职责：持有 PlayFieldView 和 StackView，统一管理整体布局和尺寸适配。

使用场景：游戏界面初始化与布局调整时使用。

*/

class GameView : public cocos2d::Node {
private:
    PlayFieldView* _playFieldView = nullptr;
    StackView* _stackView = nullptr;
    CardView* _topCardView = nullptr;

public:
    // 创建游戏场景，
    static GameView* create(GameModel* gameModel, UndoManager* undoManager);

    // 初始化函数，并添加必要的元素，如顶牌view，回退按钮，以及背景元素的添加
    virtual bool init(GameModel* gameModel, UndoManager* undoManager);

    // 需要定义的回调函数
    void menuCloseCallback(cocos2d::Ref* sender);

    // 返回PlayFieldView
    PlayFieldView* getPlayFieldView() const { return _playFieldView; }
    
    // 返回StackView
    StackView* getStackView() const { return _stackView; }
    
    // 返回TopCardView
    CardView* getTopCardView() const { return _topCardView; }
    
    // 设置TopCardView
    void setTopCardView(CardView* topCardView) { _topCardView = topCardView; }


    // 实现场景创建函数的宏
    // CREATE_FUNC(GameView);
};

#endif // __GAME_VIEW_H__
