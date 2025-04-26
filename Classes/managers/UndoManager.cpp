// UndoManager.cpp
#include "UndoManager.h"
#include <iostream>


void UndoManager::addAction(std::function<void()> undoAction) {
    _undoStack.push_back(undoAction);  // 添加撤销操作到栈中
}

void UndoManager::undo() {
    if (!_undoStack.empty()) {
        auto action = _undoStack.back();
        _undoStack.pop_back();
        action();  // 执行撤销操作
    }
    else {
        std::cout << "No actions to undo" << std::endl;
    }
}
