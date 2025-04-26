#include "CardView.h"

USING_NS_CC;

CardView* CardView::create(CardModel* model) {
    CardView* ret = new (std::nothrow) CardView();
    if (ret && ret->init(model)) {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return nullptr;
}

bool CardView::init(CardModel* model) {
    if (!Sprite::initWithFile("card_bg.png")) {
        return false;
    }

    this->_model = model;
    std::string color = "";
    if (model->suit == CardSuitType::Clubs || model->suit == CardSuitType::Spades) color = "black";
    else color = "red";
    auto mface = model->face;

    std::string smallFaceImg = StringUtils::format("numbers/small_%s_%s.png", color.c_str(), mface.c_str());
    auto smallFaceSprite = Sprite::create(smallFaceImg);
    if (!smallFaceSprite) {
        CCLOG("无法加载面值图片: %s", smallFaceImg.c_str());
        return false;
    }
    float x = smallFaceSprite->getContentSize().width / 2 + 5;
    float y = this->getContentSize().height - smallFaceSprite->getContentSize().height / 2 - 5;
    smallFaceSprite->setPosition(Vec2(x, y));
    // smallFaceSprite->setPosition(Vec2(this->getContentSize().width / 2, this->getContentSize().height / 2 - 10));
    this->addChild(smallFaceSprite);


    std::string faceImg = StringUtils::format("numbers/big_%s_%s.png", color.c_str(), mface.c_str());
    auto faceSprite = Sprite::create(faceImg);
    if (!faceSprite) {
        CCLOG("无法加载面值图片: %s", faceImg.c_str());
        return false;
    }
    // faceSprite->setScale(1.5);  // 调整大小
    faceSprite->setPosition(Vec2(this->getContentSize().width / 2, this->getContentSize().height / 2 - 5));
    this->addChild(faceSprite);


    std::string suitImg;
    switch (model->suit) {
    case CardSuitType::Clubs:      suitImg = "suits/club.png"; break;
    case CardSuitType::Diamonds:   suitImg = "suits/diamond.png"; break;
    case CardSuitType::Hearts:     suitImg = "suits/heart.png"; break;
    case CardSuitType::Spades:     suitImg = "suits/spade.png"; break;
    default:
        suitImg = "";
        break;
    }
    if (!suitImg.empty()) {
        auto suitSprite = Sprite::create(suitImg);
        if (suitSprite) {
            // suitSprite->setScale(0.5);
            float x = this->getContentSize().width - suitSprite->getContentSize().width / 2 - 5;
            float y = this->getContentSize().height - suitSprite->getContentSize().height / 2 - 5;
            suitSprite->setPosition(Vec2(x, y));
            //suitSprite->setPosition(Vec2(this->getContentSize().width / 2, this->getContentSize().height / 2 - 30));
            this->addChild(suitSprite);
        }
        else {
            CCLOG("Failed to load suit image: %s", suitImg.c_str());
        }
    }
    else {
        CCLOG("Invalid suit value: %d", static_cast<int>(model->suit));
    }

    //listening click
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = [this](Touch* touch, Event* event) {
        if (this->getBoundingBox().containsPoint(this->getParent()->convertToNodeSpace(touch->getLocation()))) {
            if (_clickCallback) {
                _clickCallback(this->_model->cardId); // 调用回调，传递 cardId
            }
            return true;
        }
        return false;
        };
    listener->setSwallowTouches(true);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    return true;
}

CardModel* CardView::getCardModel() {
    return this->_model;
}

void CardView::setClickCallback(std::function<void(int)> callback) {
    _clickCallback = callback;
}
