#ifndef LEVEL_CONFIG_LOADER_H
#define LEVEL_CONFIG_LOADER_H

#include <string>
#include <vector>
#include "models/CardModel.h"
#include "models/GameModel.h"

/*

功能：负责读取并解析关卡配置文件（level_config.json）。

职责：读取 configs/level_config.json 文件。根据关卡 ID 返回对应的关卡数据（如牌堆排列、初始布局等）。对 JSON 文件中的数据格式进行解析，生成可以用于 GameModel 初始化的数据结构。

使用场景：游戏启动新关卡时，由 GameController 调用，加载关卡数据。若后续支持自定义关卡或编辑器，LevelConfigLoader 也负责解析新的关卡文件。

*/

class LevelConfigLoader {
public:
    // 根据配置文件名，解析关卡信息，生成 gamemodel 
    static void loadJsonFile(const std::string& filename);

    // 返回生成的 gameModel
    static GameModel* getGameModel() { return _gameModel; }

private:
    static std::vector<CardModel*> _playfieldCards;
    static std::vector<CardModel*> _stackCards;
    static GameModel* _gameModel;
};

#endif // LEVEL_CONFIG_LOADER_H
