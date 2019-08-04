class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        return IsBalanced(pRoot) != -1;
    }
    
    int IsBalanced(TreeNode* pRoot) {
        if(pRoot == NULL) return 0;
        int leftDepth = IsBalanced(pRoot->left);
        if(leftDepth == -1) return -1;
        int rightDepth = IsBalanced(pRoot->right);
        if(rightDepth == -1) return -1;
        return abs(leftDepth - rightDepth) > 1 ? -1 : 1 + max(leftDepth, rightDepth);
    }
};
