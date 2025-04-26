// UndoManager.cpp
#include "UndoManager.h"
#include <iostream>


void UndoManager::addAction(std::function<void()> undoAction) {
    _undoStack.push_back(undoAction);  // ��ӳ���������ջ��
}

void UndoManager::undo() {
    if (!_undoStack.empty()) {
        auto action = _undoStack.back();
        _undoStack.pop_back();
        action();  // ִ�г�������
    }
    else {
        std::cout << "No actions to undo" << std::endl;
    }
}
