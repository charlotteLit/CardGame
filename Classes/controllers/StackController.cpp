#include "StackController.h"
#include "cocos2d.h"

USING_NS_CC;

StackController::StackController(GameController* gameController, GameModel* gameModel, UndoManager* undoManager): 
    _gameController(gameController),
    _gameModel(gameModel),
    _undoManager(undoManager){
    _stackCards = gameModel->getStackCards();
}

void StackController::init() {}

void StackController::initView(cocos2d::Node* root) {
    _rootNode = root;

    _stackView = StackView::create(_rootNode, _gameModel);
    _stackView->setClickCallback([this](int cardId) {
        this->onCardClicked(cardId);  // �� StackController �������¼�
        });
    _stackView->setLocalZOrder(0);
    _rootNode->addChild(_stackView);
}

void StackController::onCardClicked(int cardId) {
    // �����Ƶ���¼����߼�
    CCLOG("Card with ID: %d clicked in stack!", cardId);
    onStackCardClicked(cardId);
    
}


void StackController::onStackCardClicked(int cardId) {
    // �ҵ�������� model
    CardModel* clickedModel = nullptr;
    for (auto card : _stackCards) {
        if (card->cardId == cardId) {
            clickedModel = card;
            break;
        }
    }

    if (!clickedModel || clickedModel == _gameModel->getStackTopCard()) return;

    // ��ȡ��Ӧ�Ŀ�����ͼ
    CardView* clickedView = _stackView->getCardViewById(cardId);
    CardView* oldTopView = _gameController->getGameView()->getTopCardView();
    CardModel* oldTopModel = _gameModel->getStackTopCard();

    if (clickedView && oldTopView) {

        Vec2 targetPos = oldTopView->getPosition();

        auto moveToTop = MoveTo::create(0.2f, targetPos);

        clickedView->runAction(Sequence::create(
            moveToTop,
            CallFunc::create([=]() {

                _gameModel->setStackTopCard(clickedModel);
                _gameController->getGameView()->setTopCardView(clickedView);

                int clickedZOrder = clickedView->getLocalZOrder();

                clickedView->setLocalZOrder(10);


                // ���г���������¼
                _undoManager->addAction([=]() {

                    _gameModel->setStackTopCard(oldTopModel);
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
