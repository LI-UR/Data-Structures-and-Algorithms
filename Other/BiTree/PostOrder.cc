#include <iostream>
#include <stack>
#include "Bitree.h"
using namespace std;

void Postorder1(BiTree T) {
    if(T == nullptr) {
        return;
    }

    Postorder1(T->m_pLeft);
    Postorder1(T->m_pRight);
    cout << T->m_data << " ";
}

void Postorder2(BiTree root) {

    stack<BiTreeNode*> nodes;
    BiTreeNode *ptr = root, *last = nullptr;

    while(ptr != nullptr || !nodes.empty()) {
        if(ptr != nullptr) {
            nodes.push(ptr);
            ptr = ptr->m_pLeft;
        }
        else {  
            ptr = nodes.top();
            if(ptr->m_pRight != nullptr && last != ptr->m_pRight) {
                ptr = ptr->m_pRight;
            }
            else {
                ptr = nodes.top();
                nodes.pop();
                cout << ptr->m_data << " ";
                last = ptr;
                ptr = nullptr; //!!!
            }
        }
    }
}

int main() {
    BiTree T = BuildTree();
    Postorder1(T);
    cout << endl;

    Postorder2(T);
    cout << endl;

    return 0;
}

