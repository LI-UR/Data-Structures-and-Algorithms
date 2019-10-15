#ifndef __BITREE_H__
#define __BITREE_H__

struct BiTreeNode {
    int m_data;
    BiTreeNode *m_pLeft = nullptr;
    BiTreeNode *m_pRight = nullptr;
};

typedef struct BiTreeNode* BiTree;

/*      3
      /   \
     5     4
    / \   /  
   1   6 2    */
BiTree BuildTree() {
      BiTree root = new BiTreeNode{3};

      BiTreeNode *pLeft, *pRight, *pTmp;

      pTmp = root;
      pTmp->m_pLeft = new BiTreeNode{5};
      pTmp->m_pRight = new BiTreeNode{4};

      pTmp = root->m_pLeft;
      pTmp->m_pLeft = new BiTreeNode{1};
      pTmp->m_pRight = new BiTreeNode{6};

      pTmp = root->m_pRight;
      pTmp->m_pLeft = new BiTreeNode{2};

      return root;
}

#endif /*__BITREE_H__*/
