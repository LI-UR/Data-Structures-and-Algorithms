#include <iostream>
#include "BiTree.h"
using namespace std;

BiTreeNode* getNextNode(BiTreeNode *pNode) {
    if(pNode == nullptr) {
        return nullptr;
    }

    BiTreeNode *ptr = nullptr;
    if(pNode->m_pRight) {
        ptr = pNode->m_pRight;
        while(ptr->m_pLeft) {
            ptr = ptr->m_pLeft;
        }
    }
    else {
        ptr = pNode;
        while()
    }
} 

int main() {

    return 0;
}

