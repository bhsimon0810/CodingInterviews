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
        vector<vector<int> > v;
        if(pRoot == nullptr)
            return v;
        // 使用栈分别存储奇数层和偶数层的节点，在中序遍历基础上得到之字形序列
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        // 先从第一层根节点开始打印
        s1.push(pRoot);
        bool isOdd = true;
        while(!s1.empty() || !s2.empty()) {
            // 奇数层
            if(isOdd) {
                vector<int> v1;
                while(!s1.empty()) {
                    TreeNode * pNode = s1.top();
                    v1.push_back(pNode->val);
                    s1.pop();
                    if(pNode->left != nullptr)
                        s2.push(pNode->left);
                    if(pNode->right != nullptr)
                        s2.push(pNode->right);
                }
                v.push_back(v1);
                isOdd = false;
            }
            else {
                // 偶数层
                vector<int> v2;
                while(!s2.empty()) {
                    TreeNode *pNode = s2.top();
                    v2.push_back(pNode->val);
                    s2.pop();
                    // 注意入栈的顺序
                    if(pNode->right != nullptr)
                        s1.push(pNode->right);
                    if(pNode->left != nullptr)
                        s1.push(pNode->left);
                }
                v.push_back(v2);
                isOdd = true;
            }
        }
        return v;
    }
    
};
