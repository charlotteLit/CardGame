#include "PlayFieldController.h"
#include "cocos2d.h"

USING_NS_CC;

int getRank(const std::string& face);

PlayFieldController::PlayFieldController(GameController* gameController, GameModel* gameModel, UndoManager* undoManager) :
    _gameController(gameController),
    _gameModel(gameModel),
    _undoManager(undoManager){
    _playFieldCards = gameModel->getPlayFieldCards();
}

void PlayFieldController::init() {}

void PlayFieldController::initView(cocos2d::Node* root) {
    _rootNode = root;

    // ���� PlayFieldView ����ӵ� GameView ��
    _playFieldView = PlayFieldView::create(_rootNode, _gameModel);
    _playFieldView->setClickCallback([this](int cardId) {
        this->onCardClicked(cardId);  // ������ Controller ����
    });
    _playFieldView->setPosition(Vec2(0, 580));
    _playFieldView->setLocalZOrder(0);
    _rootNode->addChild(_playFieldView);
    
}

void PlayFieldController::onCardClicked(int cardId) {
    // �����Ƶ���¼����߼�
    CCLOG("Card with ID: %d clicked in stack!", cardId);
    onPlayFieldCardClicked(cardId);

}

void PlayFieldController::onPlayFieldCardClicked(int cardId) {
    CardModel* clickedModel = nullptr;
    for (auto card : _playFieldCards) {
        if (card->cardId == cardId) {
            clickedModel = card;
            break;
        }
    }
    if (!clickedModel) {
        CCLOG("cant find (ID: %d)", cardId);
        return;
    }

    if (clickedModel == _gameModel->getStackTopCard()) return;


    CardView* clickedView = _playFieldView->getCardViewById(cardId);
    CardView* oldTopView = _gameController->getGameView()->getTopCardView();
    CardModel* oldCardModel = _gameModel->getStackTopCard();


    int diff = std::abs(getRank(clickedModel->face) - getRank(oldCardModel->face));

    if (diff > 1) {  //���󶶶�
        auto move1 = MoveBy::create(0.05f, Vec2(10, 0));
        auto move2 = MoveBy::create(0.05f, Vec2(-20, 0));
        auto move3 = MoveBy::create(0.05f, Vec2(20, 0));
        auto move4 = MoveBy::create(0.05f, Vec2(-10, 0));
        auto shake = Sequence::create(move1, move2, move3, move4, nullptr);
        clickedView->runAction(shake);
    }
    else {

        Vec2 targetPos = oldTopView->getPosition();

        auto moveToTop = MoveTo::create(0.2f, targetPos);

        clickedView->runAction(Sequence::create(
            moveToTop,
            CallFunc::create([=]() {

                _gameModel->setStackTopCard(clickedModel);
                _gameController->getGameView()->setTopCardView(clickedView);
                int clickedZOrder = clickedView->getLocalZOrder();

                clickedView->setLocalZOrder(oldTopView->getLocalZOrder() + 1);

                // ���г���������¼
                _undoManager->addAction([=]() {
                    _gameModel->setStackTopCard(oldCardModel);
                    _gameController->getGameView()->setTopCardView(oldTopView);

                    auto moveBack = MoveTo::create(0.2f, clickedModel->position);  // �ƶ��������ָ���ԭʼλ��
                    clickedView->runAction(Sequence::create(
                        moveBack,
                        CallFunc::create([=]() {

                            clickedView->setLocalZOrder(clickedZOrder);
                            }),
                        nullptr
                    ));
                    });

                }),
            nullptr
        ));
    }
}

static int getRank(const std::string& face) {
    if (face == "A") return 1;
    if (face == "T" || face == "10") return 10;  // ����"T"����"10"
    if (face == "J") return 11;
    if (face == "Q") return 12;
    if (face == "K") return 13;
    // ����������ַ��������� "2" ~ "9"
    try {
        return std::stoi(face);
    }
    catch (...) {
        return -1; // �޷����������ش���
    }
}


