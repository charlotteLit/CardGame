#include "GameController.h"
#include "managers/LevelConfigLoader.h"
#include "PlayFieldController.h"
#include "StackController.h"

USING_NS_CC;

// ���캯�������� GameModel ʵ��
GameController::GameController() { _undoManager = new UndoManager(); }

Scene* GameController::startGame(const std::string& levelId) {
    
    // this->gameModel = gameModel;
    LevelConfigLoader::loadJsonFile("configs/level_config.json");
    _gameModel = LevelConfigLoader::getGameModel();

    auto playFieldController = new PlayFieldController(this, _gameModel, _undoManager);
    auto stackController = new StackController(this, _gameModel, _undoManager);

    _gameView = GameView::create(_gameModel, _undoManager);

    stackController->initView(_gameView);
    playFieldController->initView(_gameView);

    auto scene = Scene::create();
    scene->addChild(_gameView);
    return scene;
}


// ��ʼ�������ӿ�����
void GameController::initControllers() {

}

