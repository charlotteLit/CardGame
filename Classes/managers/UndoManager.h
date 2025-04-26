// UndoManager.h
#ifndef __UNDOMANAGER_H__
#define __UNDOMANAGER_H__

#include <vector>
#include <functional>

/*

功能：统一管理回退（Undo）操作。

职责：记录每次有效操作。支持一键回退最近一次操作。

使用场景：玩家点击“back”按钮时，恢复上一步状态。

*/

class UndoManager {
public:
    // 添加一个操作记录
    void addAction(std::function<void()> undoAction);

    // 撤销上一个操作
    void undo();

private:
    std::vector<std::function<void()>> _undoStack;  // 存储撤销操作的栈
};

#endif // __UNDOMANAGER_H__
