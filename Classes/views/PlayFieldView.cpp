#include "PlayFieldView.h"
#include "CardView.h"
#include "models/CardModel.h"
#include "cocos2d.h"

USING_NS_CC;

PlayFieldView* PlayFieldView::create(cocos2d::Node* root, GameModel* gameModel) {
    PlayFieldView* ret = new PlayFieldView();
    if (ret && ret->init(root, gameModel)) {
        ret->autorelease();
        return ret;
    }
    else {
        delete ret;
        return nullptr;
    }
}

bool PlayFieldView::init(cocos2d::Node* root, GameModel* gameModel) {
    if (!Node::init()) {
        return false;
    }


    const auto& models = gameModel->getPlayFieldCards();
    for (auto model : models) {
        auto cardView = CardView::create(model);

        // 注册点击事件的回调
        cardView->setClickCallback([this](int cardId) {
            if (_clickCallback) {
                _clickCallback(cardId); // 把点击传递给 Controller
            }
        });
        cardView->setPosition(model->position);
        cardView->setScale(5);
        _cardViews.push_back(cardView);
        root->addChild(cardView);
    }


    return true;
}

CardView* PlayFieldView::getCardViewById(int cardId) {
    for (auto cardView : _cardViews) {
        if (cardView->getCardModel()->cardId == cardId) {
            return cardView;
        }
    }
    return nullptr; // 没找到返回空指针
}

void PlayFieldView::setClickCallback(std::function<void(int)> callback) {
    _clickCallback = callback;
}