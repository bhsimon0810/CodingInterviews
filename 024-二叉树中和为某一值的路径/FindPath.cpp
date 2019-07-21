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
