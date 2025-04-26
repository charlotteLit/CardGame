#pragma once

#include "models/GameModel.h"
#include "managers/UndoManager.h"
#include "views/GameView.h"
#include "cocos2d.h"

USING_NS_CC;

class StackController;
class PlayFieldController;

/*

���ܣ���Ϸ�ܿ������������ʼ���������ؿ���Э�����ӿ�������

ְ�𣺼��عؿ����ã����� GameModel����ʼ�� PlayFieldController��StackController��UndoManager������ؿ����á����˵ȸ߲������

ʹ�ó��������ѡ��ؿ������ startGame(levelId)��������Ϸ���̡�

*/

class GameController {
private:
    GameModel* _gameModel;
    UndoManager* _undoManager;
    GameView* _gameView;

public:
    // ���캯������ʼ����ʱĬ�ϵ���
    GameController();
    // ���ݴ����levelId����ʼ�����ӿ������������࣬�����ؽ�������Ϸ����
    Scene* startGame(const std::string& levelId);
    
    //��ʼ��
    void initControllers();

    // ��ȡ��Ϸģ��
    GameModel* getGameModel() { return _gameModel; }
    GameView* getGameView() { return _gameView; }

};
