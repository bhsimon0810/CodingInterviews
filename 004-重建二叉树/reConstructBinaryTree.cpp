/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        return createBinTree(pre, 0, pre.size()-1, vin, 0, vin.size()-1);
    }

    TreeNode* createBinTree(vector<int>& preorder, int pleft, int pright, vector<int>& inorder, int ileft, int iright) {
        if(pleft > pright || ileft > iright) return nullptr;
        TreeNode *root = new TreeNode(preorder[pleft]);
        for(int k = ileft; k <= iright; k++) {
            if(inorder[k] == preorder[pleft]) {
                root->left = createBinTree(preorder, pleft+1, pleft+k-ileft, inorder, ileft, k-1);
                root->right = createBinTree(preorder, pleft+k-ileft+1, pright, inorder, k+1, iright);
            }
        }
        return root;
    }
};
