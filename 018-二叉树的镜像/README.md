# 二叉树的镜像

本文是[《剑指Offer》](https://www.nowcoder.com/ta/coding-interviews?page=1) 刷题笔记，记录刷题过程中的体会与收获。

## 题目描述

操作给定的二叉树，将其变换为源二叉树的镜像。

## 输入描述

```
源二叉树 
    	    8
    	   /  \
    	  6   10
    	 / \  / \
    	5  7 9 11
镜像二叉树
    	    8
    	   /  \
    	  10   6
    	 / \  / \
    	11 9 7  5
```

## 解题思路

将给定的二叉树变换为镜像的过程如下所示，即按照前序遍历的方式交换左右子树，首先交换根结点的左右子树（即左右子结点），再分别交换根结点左右子结点的孩子结点。递归交换即可完成镜像变换。

![MirrorOfBinaryTree](http://wx2.sinaimg.cn/mw690/a9d96161ly1g52vkub6jmj20m9063gml.jpg)

显然若树的根结点为空或结点左右子结点都为空（说明交换完成）时递归停止。

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
    void Mirror(TreeNode *pRoot) {
        if(pRoot == NULL || pRoot->left == NULL && pRoot->right == NULL) {
            return;
        }
        TreeNode *temp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = temp;
        
        if(pRoot->left) {
            Mirror(pRoot->left);
        }
        
        if(pRoot->right) {
            Mirror(pRoot->right);
        }
    }
};
```

