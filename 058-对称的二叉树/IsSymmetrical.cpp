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
    bool isSymmetrical(TreeNode* pRoot)
    {
        // 判断二叉树是否对称，可以从前序遍历开始入手
        // 前序遍历是 父节点 --> 左子节点 --> 右子节点
        // 那么定义新的遍历规则为 父节点 --> 右子节点 --> 左子节点
        // 则得到的序列与前序遍历序列是对称的
        // 因此只要判断这两个序列是否一致即可判断二叉树是否对称
        return isSymmetrical(pRoot, pRoot);
    }
    
    bool isSymmetrical(TreeNode* pNode1, TreeNode* pNode2)
    {
        // 使用递归逐节点判断
        if(pNode1 == nullptr && pNode2 == nullptr)
            return true;
        if(pNode1 == nullptr || pNode2 == nullptr)
            return false;
        if(pNode1->val != pNode2->val)
            return false;
        return isSymmetrical(pNode1->left, pNode2->right) && isSymmetrical(pNode1->right, pNode2->left);
    }

};
