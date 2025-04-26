#include "GameView.h"
#include "models/GameModel.h"
#include "views/CardView.h"

USING_NS_CC;


GameView* GameView::create(GameModel* gameModel, UndoManager* undoManager){
    GameView* view = new (std::nothrow) GameView();
    if (view && view->init(gameModel, undoManager)) {
        view->autorelease();
        return view;
    }
    CC_SAFE_DELETE(view);
    return nullptr;
}

bool GameView::init(GameModel* gameModel, UndoManager* undoManager) {
    if (!Node::init())
        return false;


    auto upperBackground = LayerColor::create(Color4B(173, 116, 57, 255));
    upperBackground->setContentSize(Size(1080, 1500));
    upperBackground->setPosition(Vec2(0, 580)); 
    this->addChild(upperBackground, -1);


    auto lowerBackground = LayerColor::create(Color4B(150, 50, 150, 255));
    lowerBackground->setContentSize(Size(1080, 580));
    lowerBackground->setPosition(Vec2(0, 0)); 
    this->addChild(lowerBackground, -1);


    // 2. 初始化 topCardView
    CardModel* topCardModel = gameModel->getStackTopCard();
    if (topCardModel) {
        _topCardView = CardView::create(topCardModel);
        _topCardView->setScale(5);
        _topCardView->setLocalZOrder(0);
        _topCardView->setPosition(cocos2d::Vec2(800, 290));
        setTopCardView(_topCardView);
        this->addChild(_topCardView);
    }

    // 创建“回退”按钮
    auto undoLabel = Label::createWithSystemFont("BACK", "Microsoft YaHei", 36);  // 创建标签
    auto undoMenuItem = MenuItemLabel::create(undoLabel, CC_CALLBACK_0(UndoManager::undo, undoManager));  // 使用回调函数

    undoMenuItem->setPosition(Vec2(900, 580));  // 设置回退按钮的位置

    // 创建菜单并将菜单项加入其中
    auto menu = Menu::create(undoMenuItem, nullptr);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu);  // 将菜单添加到场景中

    return true;
}

void GameView::menuCloseCallback(Ref* sender) {
    Director::getInstance()->end();
}



