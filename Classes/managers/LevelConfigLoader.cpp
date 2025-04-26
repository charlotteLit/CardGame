#include "LevelConfigLoader.h"
#include "json/document.h"
#include "json/filereadstream.h"
#include "cocos2d.h"

using namespace rapidjson;
using namespace cocos2d;

std::vector<CardModel*> LevelConfigLoader::_playfieldCards;
std::vector<CardModel*> LevelConfigLoader::_stackCards;
GameModel* LevelConfigLoader::_gameModel = nullptr;

void LevelConfigLoader::loadJsonFile(const std::string& filename) {
    _playfieldCards.clear();
    _stackCards.clear();

    std::string fullPath = FileUtils::getInstance()->fullPathForFilename(filename);
    CCLOG("Full path: %s", fullPath.c_str());

    FILE* fp = fopen(fullPath.c_str(), "rb");
    if (!fp) {
        CCLOG("Failed to open JSON file: %s", filename.c_str());
        return;
    }

    char buffer[65536];
    FileReadStream is(fp, buffer, sizeof(buffer));
    Document doc;
    doc.ParseStream(is);
    fclose(fp);
    int globalCardId = 0;

    auto parseCardArray = [&globalCardId](const rapidjson::Value& array, std::vector<CardModel*>& container, bool flag) {
        for (SizeType i = 0; i < array.Size(); ++i) {
            const rapidjson::Value& item = array[i];
            auto model = new CardModel();

            int faceInt = item["CardFace"].GetInt();
            std::string faceStr;
            switch (faceInt) {
            case 1: faceStr = "A"; break;
            case 10: faceStr = "10"; break;
            case 11: faceStr = "J"; break;
            case 12: faceStr = "Q"; break;
            case 13: faceStr = "K"; break;
            default: faceStr = std::to_string(faceInt); break;
            }
            model->face = faceStr;

            // 解析花色枚举
            int suitValue = item["CardSuit"].GetInt();
            switch (suitValue) {
            case 0: model->suit = CardSuitType::Clubs; break;
            case 1: model->suit = CardSuitType::Diamonds; break;
            case 2: model->suit = CardSuitType::Hearts; break;
            case 3: model->suit = CardSuitType::Spades; break;
            default: model->suit = CardSuitType::None; break;
            }

            float x = item["Position"]["x"].GetFloat();
            float y = item["Position"]["y"].GetFloat();
            if (flag) y += 580;
            model->position = Vec2(x, y);
            model->cardId = globalCardId++;
            container.push_back(model);
        }
        };

    if (doc.HasMember("Playfield") && doc["Playfield"].IsArray()) {
        parseCardArray(doc["Playfield"], _playfieldCards, true);
    }

    if (doc.HasMember("Stack") && doc["Stack"].IsArray()) {
        parseCardArray(doc["Stack"], _stackCards, false);
    }
    if(!_gameModel) _gameModel = new GameModel();
    _gameModel->setPlayFieldCards(_playfieldCards);
    _gameModel->setStackCards(_stackCards);

    CardModel* topCardModel = _stackCards[_stackCards.size() - 1];
    _gameModel->setStackTopCard(topCardModel);
}
