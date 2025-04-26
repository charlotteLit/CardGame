#ifndef LEVEL_CONFIG_LOADER_H
#define LEVEL_CONFIG_LOADER_H

#include <string>
#include <vector>
#include "models/CardModel.h"
#include "models/GameModel.h"

/*

���ܣ������ȡ�������ؿ������ļ���level_config.json����

ְ�𣺶�ȡ configs/level_config.json �ļ������ݹؿ� ID ���ض�Ӧ�Ĺؿ����ݣ����ƶ����С���ʼ���ֵȣ����� JSON �ļ��е����ݸ�ʽ���н��������ɿ������� GameModel ��ʼ�������ݽṹ��

ʹ�ó�������Ϸ�����¹ؿ�ʱ���� GameController ���ã����عؿ����ݡ�������֧���Զ���ؿ���༭����LevelConfigLoader Ҳ��������µĹؿ��ļ���

*/

class LevelConfigLoader {
public:
    // ���������ļ����������ؿ���Ϣ������ gamemodel 
    static void loadJsonFile(const std::string& filename);

    // �������ɵ� gameModel
    static GameModel* getGameModel() { return _gameModel; }

private:
    static std::vector<CardModel*> _playfieldCards;
    static std::vector<CardModel*> _stackCards;
    static GameModel* _gameModel;
};

#endif // LEVEL_CONFIG_LOADER_H
