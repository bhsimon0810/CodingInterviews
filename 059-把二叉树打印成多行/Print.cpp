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
    vector<vector<int> > Print(TreeNode* pRoot) {
        // 典型的二叉树层序遍历
        vector<vector<int> > vecs;
        if(pRoot == nullptr)
            return vecs;
        queue<TreeNode* > q;
        q.push(pRoot);
        while(!q.empty()) {
            vector<int> vec;
            // 二叉树每一层的节点数
            int size = q.size();
            for(int i = 0; i < size; i++) {
                TreeNode *pNode = q.front();
                q.pop();
                vec.push_back(pNode->val);
                if(pNode->left)
                    q.push(pNode->left);
                if(pNode->right)
                    q.push(pNode->right);
            }
            vecs.push_back(vec);
        }
        return vecs;
    } 
};
