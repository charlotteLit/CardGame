#ifndef __GAME_VIEW_H__
#define __GAME_VIEW_H__

#include "models/GameModel.h"
#include "CardView.h"
#include "StackView.h"
#include "PlayFieldView.h"
#include "cocos2d.h"
#include "managers/UndoManager.h"

/*

���ܣ���Ϸ�����棬��֯���ӽ��沼�֡�

ְ�𣺳��� PlayFieldView �� StackView��ͳһ�������岼�ֺͳߴ����䡣

ʹ�ó�������Ϸ�����ʼ���벼�ֵ���ʱʹ�á�

*/

class GameView : public cocos2d::Node {
private:
    PlayFieldView* _playFieldView = nullptr;
    StackView* _stackView = nullptr;
    CardView* _topCardView = nullptr;

public:
    // ������Ϸ������
    static GameView* create(GameModel* gameModel, UndoManager* undoManager);

    // ��ʼ������������ӱ�Ҫ��Ԫ�أ��綥��view�����˰�ť���Լ�����Ԫ�ص����
    virtual bool init(GameModel* gameModel, UndoManager* undoManager);

    // ��Ҫ����Ļص�����
    void menuCloseCallback(cocos2d::Ref* sender);

    // ����PlayFieldView
    PlayFieldView* getPlayFieldView() const { return _playFieldView; }
    
    // ����StackView
    StackView* getStackView() const { return _stackView; }
    
    // ����TopCardView
    CardView* getTopCardView() const { return _topCardView; }
    
    // ����TopCardView
    void setTopCardView(CardView* topCardView) { _topCardView = topCardView; }


    // ʵ�ֳ������������ĺ�
    // CREATE_FUNC(GameView);
};

#endif // __GAME_VIEW_H__
