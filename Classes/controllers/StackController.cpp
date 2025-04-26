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
        this->onCardClicked(cardId);  // 由 StackController 处理点击事件
        });
    _stackView->setLocalZOrder(0);
    _rootNode->addChild(_stackView);
}

void StackController::onCardClicked(int cardId) {
    // 处理卡牌点击事件的逻辑
    CCLOG("Card with ID: %d clicked in stack!", cardId);
    onStackCardClicked(cardId);
    
}


void StackController::onStackCardClicked(int cardId) {
    // 找到被点击的 model
    CardModel* clickedModel = nullptr;
    for (auto card : _stackCards) {
        if (card->cardId == cardId) {
            clickedModel = card;
            break;
        }
    }

    if (!clickedModel || clickedModel == _gameModel->getStackTopCard()) return;

    // 获取对应的卡牌视图
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


                // 进行撤销操作记录
                _undoManager->addAction([=]() {

                    _gameModel->setStackTopCard(oldTopModel);
                    _gameController->getGameView()->setTopCardView(oldTopView);

                    auto moveBack = MoveTo::create(0.2f, clickedModel->position);  // 移动动画，恢复到原始位置
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
