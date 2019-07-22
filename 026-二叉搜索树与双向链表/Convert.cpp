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
