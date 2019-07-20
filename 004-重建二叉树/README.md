# 重建二叉树

本文是[《剑指Offer》](https://www.nowcoder.com/ta/coding-interviews?page=1) 刷题笔记，记录刷题过程中的体会与收获。

不能为了刷题而刷题，因此在这里对二叉树基本知识做一下简单的小结，包括递归和循环实现前序遍历、中序遍历、后序遍历和层次遍历，以及经典的二叉树题目，包括镜像二叉树和从前/后序遍历序列和中序遍历序列中重建二叉树等。这些题目在剑指和 [LeetCode](https://leetcode-cn.com/) 中均有涉及，因此是非常重要的基础知识，需要牢牢掌握，也趁此机会结合相关题目进行总结。

## 1. 二叉树的遍历

下图所示为二叉树示例，二叉树的遍历就是按照不同的规则将二叉树所有节点访问且仅访问一次。根据访问规则的不同，可以分为

- 前序遍历：先访问根节点，再访问左子节点，最后访问右子结点
- 中序遍历：先访问左子节点，再访问根节点，最后访问右子结点
- 后序遍历：先访问左子节点，再访问右子结点，最后访问根节点
- 层次遍历：先访问第一层节点，再访问第二层节点...直至最后一层节点

![BinTree](http://wx4.sinaimg.cn/mw690/a9d96161ly1g562cxxbtcj205y05ymx0.jpg)

按照上述遍历规则，不难得到上图所示二叉树的遍历序列分别为

- 10-6-4-8-14-12-16
- 4-6-8-10-12-14-16
- 4-8-6-12-16-14-10
- 10-6-14-4-8-12-16

### 1.1 前序遍历

[前序遍历](https://leetcode-cn.com/problems/binary-tree-preorder-traversal/)可以很直观地通过递归实现，但也因为过于简单题目常常要求使用循环实现。下面分别使用递归和循环给出相应的代码示例。

递归方法直接粗暴，就是按照节点访问规则，首先访问根节点，再依次访问左子节点和右子结点。代码示例就直接按照上述规则即可，如下所示

```C++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == nullptr) return result;
        result.push_back(root->val);
        vector<int> tmp1 = preorderTraversal(root->left);
        vector<int> tmp2 = preorderTraversal(root->right);
        if(!tmp1.empty())
            result.insert(result.end(), tmp1.begin(), tmp1.end());
        if(!tmp2.empty())
            result.insert(result.end(), tmp2.begin(), tmp2.end());
        return result;
    }
};
```

迭代方法需要借助栈来实现，首先将根节点入栈，然后进入循环体。循环体内部将弹出栈顶元素并对其进行访问，然后再**分别将其右左子节点入栈**。这样做的目的是利用栈后进先出的数据存取规则，达到先访问父节点、再访问左右子结点的前序遍历规则。代码示例如下

```C++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:    
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode* > TreeNodeStack;
        vector<int> result;
        TreeNode* p = root;
        TreeNodeStack.push(p);
        while(!TreeNodeStack.empty() && p) {
            p = TreeNodeStack.top();
            result.push_back(p->val);
            TreeNodeStack.pop();
            if(p->right != nullptr) TreeNodeStack.push(p->right);
            if(p->left != nullptr) TreeNodeStack.push(p->left);
        }
        return result;
    }
};
```

### 1.2 中序遍历

[中序遍历](https://leetcode-cn.com/problems/binary-tree-inorder-traversal/)的访问规则不再赘述，但要注意的是迭代算法中，同样需要借助栈沿着二叉树的左子树一直迭代直至叶节点，然后回退至父节点再访问右子结点，完成中序遍历。递归算法和迭代算法代码示例分别如下所示

```C++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == nullptr) return result;
        vector<int> tmp1 = inorderTraversal(root->left);
        if(!tmp1.empty())
            result.insert(result.end(), tmp1.begin(), tmp1.end());
        result.push_back(root->val);
        vector<int> tmp2 = inorderTraversal(root->right);
        if(!tmp2.empty())
            result.insert(result.end(), tmp2.begin(), tmp2.end());
        return result;
    }
};
```



```C++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode* > TreeNodeStack;
        vector<int> result;
        TreeNode*p = root;
        do {
            while(p != nullptr) {
                TreeNodeStack.push(p);
                p = p->left;
            }
            if(!TreeNodeStack.empty()) {
                p = TreeNodeStack.top();
                result.push_back(p->val);
                TreeNodeStack.pop();
                p = p->right;
            }
        } while(p!= nullptr || !TreeNodeStack.empty());
        return result;
    }
};
```

### 1.3 后序遍历

[后序遍历](https://leetcode-cn.com/problems/binary-tree-postorder-traversal/)的递归算法同样简单直观，代码示例如下

```C++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == nullptr) return result;
        vector<int> tmp1 = postorderTraversal(root->left);
        if(!tmp1.empty())
            result.insert(result.end(), tmp1.begin(), tmp1.end());
        vector<int> tmp2 = postorderTraversal(root->right);
        if(!tmp2.empty())
            result.insert(result.end(), tmp2.begin(), tmp2.end());
        result.push_back(root->val);
        return result;
    }
};
```

但迭代算法相对来说有些难度。可行的方法同样借助栈存放二叉树的节点，但同时为每个结点指派标签，另外再定义栈存放相应标签来指示是否访问过右子结点，同时设置标志位 `continuel` 来指示是否回退至父节点。代码示例如下 

```C++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode* > TreeNodeStack;
        stack<int> TagStack;
        vector<int> v; int tag;
        TreeNode* p = root;
        do {
            while(p != nullptr) {
                TreeNodeStack.push(p);
                TagStack.push(tag=0);
                p = p->left;
            }
            int continuel = 1;
            while(continuel && !TreeNodeStack.empty() && !TagStack.empty()) {
                p = TreeNodeStack.top();
                tag = TagStack.top();
                TreeNodeStack.pop();
                TagStack.pop();
                switch(tag) {
                    case 0: TreeNodeStack.push(p);
                            TagStack.push(tag=1);
                            continuel = 0;
                            p = p->right;
                            break;
                    case 1: v.push_back(p->val);
                            break;
                }
            }
        } while(!TreeNodeStack.empty() && !TagStack.empty());
        return v;
    }
};
```

### 1.4 层次遍历



## 2. 重建二叉树

二叉树重构就是根据前序遍历序列和中序遍历序列 / 后序遍历序列重构出原始二叉树。其原理是

- 前序序列：根节点-左子树-右子树
- 中序序列：左子树-根节点-右子树
- 后序序列：左子树-右子树-根节点

