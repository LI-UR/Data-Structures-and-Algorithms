/*********************************************
 * file:   List.h
 * author: AIWWZ(wzj1524@qq.com)
 * date:   2019-07-18 04:35:41
 **********************************************/
#ifndef __LIST_H__
#define __LIST_H__
#include <iostream>
using std::cout;  using std::endl;

struct ListNode {
    int value;
    ListNode *next;
};

ListNode* CreateListNode(int value) {
    return new ListNode{value, nullptr};
}

void ConnectListNodes(ListNode* pCurrent, ListNode* pNext) {
    if(pCurrent == nullptr) {
        cout << "Error to connect two nodes." << endl;
        exit(1);
    }
    pCurrent->next = pNext;
}

void PrintListNode(ListNode* pNode) {
    if(nullptr == pNode) {
        cout << "This node is nullptr" << endl;
    }
    else {
        cout << "The key in node is " << pNode->value << endl;
    }
}

void PrintList(ListNode* pHead) {
    cout << "PrintList starts." << endl;

    ListNode *pNode = pHead;
    while(nullptr != pNode) {
        cout << pNode->value << "\t";
        pNode = pNode->next;
    }

    cout << "\nPrintList ends." << endl;
}

void DestroyList(ListNode* pHead) {
    ListNode *pNode = pHead;
    while(nullptr != pNode) {
        pHead = pHead->next;
        delete pNode;
        pNode = pHead;
    }
}

void AddToTail(ListNode** pHead, int value) {
    ListNode *pNew = new ListNode{value, nullptr};
    if(nullptr == pHead) {
        *pHead = pNew;
    }
    else {
        ListNode *pNode = *pHead;
        while(nullptr != pNode->next) {
            pNode = pNode->next;
        }
        pNode->next = pNew;
    }
}

void RemoveNode(ListNode** pHead, int value) {
    if(nullptr == pHead || nullptr == *pHead) {
        return;
    }

    ListNode *pToBeDeleted = nullptr;
    if((*pHead)->value == value) {
        pToBeDeleted = *pHead;
        *pHead = (*pHead)->next;

    }
    else {
        ListNode* pNode = *pHead;
        while(pNode->next != nullptr && pNode->next->value != value)
            pNode = pNode->next;

        if(pNode->next != nullptr && pNode->next->value == value) {
            pToBeDeleted = pNode->next;
            pNode->next = pNode->next->next;
        }

    }

    if(pToBeDeleted != nullptr) {
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
    }
}

#endif /* __LIST_H__ */
