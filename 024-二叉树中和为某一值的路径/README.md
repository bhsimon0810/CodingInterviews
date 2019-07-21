# 二叉树中和为某一值的路径

本文是[《剑指Offer》](https://www.nowcoder.com/ta/coding-interviews?page=1) 刷题笔记，记录刷题过程中的体会与收获。

## 题目描述

输入一颗二叉树的根节点和一个整数，打印出二叉树中节点值的和为输入整数的所有路径。路径定义为从树的根节点开始往下一直到叶节点所经过的节点形成一条路径。（注意: 在返回值的 `list` 中，数组长度大的数组靠前）

## 解题思路

首先需要明确路径的定义：从树的根节点开始往下一直到叶节点所经过的节点形成一条路径，因此需要访问到叶节点之后才能判断路径上所有节点数值之和是否与期望值相等。在访问某一节点时，首先要记录当前节点数值，计算当前正在访问路径中已访问的所有节点数值之和，然后才能继续访问当前节点的子节点，因此属于典型的前序遍历过程。

因为要统计整条路径的节点数值之和，因此需要借助容器（或者是栈）保存当前节点的数值之后再去遍历其子节点。在每次遍历到叶节点时，需要计算整条路径节点数只之和，如果等于期望值，则将整条路径添加进待返回的列表中；如果不等于期望值，则退回至叶节点的父节点，比较父节点的另一子节点。**退回过程需要注意当前容器要删除当前叶节点的数值**。

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

    vector<vector<int> > paths;
    vector<int> path;
    
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
    
        if(root == NULL) return paths;
        int currentNumber = 0;
        FindPath(root, expectNumber, path, currentNumber);
        return paths;
    }

    void FindPath(TreeNode *root, int expectNumber, vector<int> & path, int & currentNumber) {
        currentNumber += root->val;
        path.push_back(root->val);

        bool isLeaf = root->left == NULL && root->right == NULL;
        
        // 如果已经到叶节点并且路径之和等于期望值
        if(isLeaf && currentNumber == expectNumber) paths.push_back(path);

        // 如果不是叶节点继续递归进行
        if(root->left) FindPath(root->left, expectNumber, path, currentNumber);
        if(root->right) FindPath(root->right, expectNumber, path, currentNumber);

        // 回退需要减掉当前节点的值
        currentNumber -= root->val;
        path.pop_back();
    }
};
```

