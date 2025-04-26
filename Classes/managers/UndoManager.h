// UndoManager.h
#ifndef __UNDOMANAGER_H__
#define __UNDOMANAGER_H__

#include <vector>
#include <functional>

/*

���ܣ�ͳһ������ˣ�Undo��������

ְ�𣺼�¼ÿ����Ч������֧��һ���������һ�β�����

ʹ�ó�������ҵ����back����ťʱ���ָ���һ��״̬��

*/

class UndoManager {
public:
    // ���һ��������¼
    void addAction(std::function<void()> undoAction);

    // ������һ������
    void undo();

private:
    std::vector<std::function<void()>> _undoStack;  // �洢����������ջ
};

#endif // __UNDOMANAGER_H__
