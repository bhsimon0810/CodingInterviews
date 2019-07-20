# 从上到下打印二叉树

本文是[《剑指Offer》](https://www.nowcoder.com/ta/coding-interviews?page=1) 刷题笔记，记录刷题过程中的体会与收获。

## 题目描述

从上往下打印出二叉树的每个节点，同层节点从左至右打印。

## 解题思路

这道题其实就是考察二叉树的层次遍历。借助队列即可实现，从根节点开始入队，然后进入循环，若队列不空，弹出队首元素并将左右子节点入队。循环结束的条件是队列为空，此时二叉树所有的节点打印完毕。

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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> result;
        if(root == NULL) {
            return result;
        }
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode *node = q.front();
            result.push_back(node->val);
            q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        return result;
    }
};
```

