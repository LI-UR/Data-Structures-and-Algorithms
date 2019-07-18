/*********************************************
 * file:   BiTree.h
 * author: AIWWZ(wzj1524@qq.com)
 * date:   2019-07-18 05:38:53
 **********************************************/
#ifndef __BITREE_H__
#define __BITREE_H__
#include <stdio.h>

struct BiTreeNode {
    int value;
    BiTreeNode *left;
    BiTreeNode *right;
};

BiTreeNode* CreateBinaryTreeNode(int value) {
    return new BiTreeNode{value, nullptr, nullptr};
}

void ConnectTreeNodes(BiTreeNode* pParent, BiTreeNode* pLeft, BiTreeNode* pRight) {
    if(nullptr != pParent) {
        pParent->left = pLeft;
        pParent->right = pRight;
    }
}

void PrintTreeNode(const BiTreeNode* pNode) {
    if(nullptr != pNode) {
        printf("value of this node is: %d\n", pNode->value);

        if(pNode->left != nullptr)
            printf("value of its left child is: %d.\n", pNode->left->value);
        else
            printf("left child is nullptr.\n");

        if(pNode->right != nullptr)
            printf("value of its right child is: %d.\n", pNode->right->value);
        else
            printf("right child is nullptr.\n");
    }
    else {
        printf("this node is nullptr.\n");
    }

    printf("\n");
}

void PrintTree(const BiTreeNode* pRoot) {
    PrintTreeNode(pRoot);

    if(pRoot != nullptr) {
        if(pRoot->left != nullptr)
            PrintTree(pRoot->left);

        if(pRoot->right != nullptr)
            PrintTree(pRoot->right);
    }
}

void DestroyTree(BiTreeNode* pRoot) {
    if(nullptr != pRoot) {
        DestroyTree(pRoot->left);
        DestroyTree(pRoot->right);

        delete pRoot;
        pRoot = nullptr;
    }
}

#endif /* __BITREE_H__ */
