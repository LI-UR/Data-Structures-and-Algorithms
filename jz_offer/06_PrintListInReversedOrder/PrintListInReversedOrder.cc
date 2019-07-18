/*********************************************
 * file:   PrintListInReversedOrder.cc
 * author: AIWWZ(wzj1524@qq.com)
 * date:   2019-07-18 04:29:22
 **********************************************/
#include <iostream>
#include "../Utilities/List.h"
#include <stack>
using namespace std;

// 面试题6：从尾到头打印链表
// 题目：输入一个链表的头结点，从尾到头反过来打印出每个结点的值。
void PrintListReversingly_Iteratively(ListNode *pHead) {
    stack<ListNode*> st;

    ListNode *pNode = pHead;
    while(nullptr != pNode) {
        st.push(pNode);
        pNode = pNode->next;
    }

    while(!st.empty()) {
        cout << st.top()->value << "\t";
        st.pop();
    }
}

void PrintListReversingly_Recursively(ListNode *pHead) {
    if(nullptr == pHead) {
        return;
    }

    if(nullptr != pHead->next) {
        PrintListReversingly_Recursively(pHead->next);
    }
    cout << pHead->value << "\t";
}

// ====================测试代码====================
void Test(ListNode* pHead)
{
    PrintList(pHead);
    PrintListReversingly_Iteratively(pHead);
    printf("\n");
    PrintListReversingly_Recursively(pHead);
    printf("\n");
}

// 1->2->3->4->5
void Test1()
{
    printf("\nTest1 begins.\n");

    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    Test(pNode1);

    DestroyList(pNode1);
}

// 只有一个结点的链表: 1
void Test2()
{
    printf("\nTest2 begins.\n");

    ListNode* pNode1 = CreateListNode(1);

    Test(pNode1);

    DestroyList(pNode1);
}

// 空链表
void Test3()
{
    printf("\nTest3 begins.\n");

    Test(nullptr);
}

int main(int argc, char* argv[]) {
    Test1();
    Test2();
    Test3();

    return 0;
}
