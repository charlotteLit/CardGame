#include "StackView.h"
#include "CardView.h"
#include "models/CardModel.h"
#include "cocos2d.h"

USING_NS_CC;

StackView* StackView::create(cocos2d::Node* root, GameModel* gameModel) {
    StackView* ret = new StackView();
    if (ret && ret->init(root, gameModel)) {
        ret->autorelease();
        return ret;
    }
    else {
        delete ret;
        return nullptr;
    }
}

bool StackView::init(cocos2d::Node* root, GameModel* gameModel) {
    if (!Node::init()) {
        return false;
    }

    const auto& models = gameModel->getStackCards();
    for (size_t i = 0; i < models.size() - 1; ++i) {
        auto cardView = CardView::create(models[i]);

        // 注册备用牌的点击事件回调
        cardView->setClickCallback([this](int cardId) {
            if (_clickCallback) {
                _clickCallback(cardId); // 把点击传递给 Controller
            }
        });
        cardView->setPosition(models[i]->position);
        cardView->setScale(5);
        _remainingCards.push_back(cardView);
        root->addChild(cardView);
    }


    return true;
}


CardView* StackView::getCardViewById(int cardId) {
    for (auto cardView : _remainingCards) {
        if (cardView->getCardModel()->cardId == cardId) {
            return cardView;
        }
    }
    return nullptr; // 没找到返回空指针
}


void StackView::setClickCallback(std::function<void(int)> callback) {
    _clickCallback = callback;
}