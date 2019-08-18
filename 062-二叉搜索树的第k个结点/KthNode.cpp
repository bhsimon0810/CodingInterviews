/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    int count = 0;
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        // 中序遍历得到的二叉搜索树序列正好是一排序序列，因此可直接返回第 k 小的节点
        if(pRoot)
        {
            TreeNode *ret = KthNode(pRoot->left, k);
            if(ret != nullptr) 
                return ret;
            if(++count == k)
                return pRoot;
            ret = KthNode(pRoot->right, k);
            if(ret)
                return ret;
        }
        return nullptr;
    }

    
};
