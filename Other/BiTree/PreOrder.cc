#include <iostream>
#include <stack>
#include "Bitree.h"
using namespace std;

void Preorder1(BiTree T) {
    if(T == nullptr) {
        return;
    }

    cout << T->m_data << " ";
    Preorder1(T->m_pLeft);
    Preorder1(T->m_pRight);
}

void Preorder2(BiTree root) {

    stack<BiTreeNode*> nodes;
    BiTreeNode *ptr = root;

    while(ptr != nullptr || !nodes.empty()) {
        if(ptr != nullptr) {
            cout << ptr->m_data << " ";
            nodes.push(ptr);
            ptr = ptr->m_pLeft;
        }
        else {
            ptr = nodes.top();
            nodes.pop();
            ptr = ptr->m_pRight; //转向右
        }
    }
}

int main() {
    BiTree T = BuildTree();
    Preorder1(T);
    cout << endl;

    Preorder2(T);
    cout << endl;

    return 0;
}

