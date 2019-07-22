# 二叉搜索树与双向链表

本文是[《剑指Offer》](https://www.nowcoder.com/ta/coding-interviews?page=1) 刷题笔记，记录刷题过程中的体会与收获。

## 题目描述

输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。

## 解题思路

二叉搜索树是左子树节点数值均小于根节点并且右子树节点数值均大于根节点的有序二叉树，可以看到若转化为有序链表，则显然使用中序遍历可以得到排序序列。重点在于如何将中序遍历序列转换为双向链表。

![Convert](http://wx3.sinaimg.cn/mw690/a9d96161ly1g58eql8rdhj20jc05zwel.jpg)

设置指针 `pLastNodeInList` 表示有序双向链表的尾节点，设置指针 `pNode` 指向当前待插入节点。递归过程首先将根节点的左子树转换为有序双向链表，然后添加根节点，再将右子树转换为有序双向链表。由树结构到双向链表的转换是通过两个指针左右互指实现的。递归过程中注意对边界条件的判断。

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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == NULL) return NULL;

        TreeNode *pLastNodeInList = NULL;
        ConvertNode(pRootOfTree, pLastNodeInList);

        TreeNode *pHeadOfTree = pRootOfTree;
        while(pHeadOfTree->left) {
            pHeadOfTree = pHeadOfTree->left;
        }
        return pHeadOfTree;
    }
    
    void ConvertNode(TreeNode* pNode, TreeNode* & pLastNodeInList) {
        if(pNode == NULL) return;

        ConvertNode(pNode->left, pLastNodeInList);

        pNode->left = pLastNodeInList;
        if(pLastNodeInList) {
            pLastNodeInList->right = pNode;
        }
        pLastNodeInList = pNode;

        ConvertNode(pNode->right, pLastNodeInList);
    }
};
```



