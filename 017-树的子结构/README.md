# 树的子结构

本文是[《剑指Offer》](https://www.nowcoder.com/ta/coding-interviews?page=1) 刷题笔记，记录刷题过程中的体会与收获。

## 题目描述

输入两棵二叉树 A，B，判断 B 是不是 A 的子结构。（PS：我们约定空树不是任意一个树的子结构）

## 解题思路

判断树 B 是否为树 A 的子结构，则首先需要判断树 B 的根结点是否包含在树 A，若包含于树 A 则再判断左右子树是否包含在树 A 内。因此可以采用递归的方法解决此问题。

题目规定空树不是任意一棵树的子结构，而且任意树结构也不可能是空树的子结构，因此首先需要对两棵树判空。

若两棵树根结点一致，则需要判断两棵树的左右子树；若不一致，则需要在树 A 的左子树和右子树中寻找是否包含子树 B，这是递归的过程。

若树 A 某一结点与树 B 根结点一致，需要判断左右子树是否一致。这个过程同样可以通过递归实现，递归结束的条件是树 B 达到叶结点，则查找成功；否则如果树 A 达到叶结点，则查找失败。

## 代码示例

```C++
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot1 == NULL || pRoot2 == NULL) return false;
        return IsSubTree(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
    }
    
    bool IsSubTree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot2 == NULL)
            return true;
        if(pRoot1 == NULL)
            return false;
        if(pRoot1->val == pRoot2->val)
            return IsSubTree(pRoot1->left, pRoot2->left) && IsSubTree(pRoot1->right, pRoot2->right);
        else 
            return false;
    }
};
```

