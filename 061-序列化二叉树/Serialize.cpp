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
    string str;
    void Serialize(TreeNode *root, string& str) {
        if (root == NULL) {
            str = str + '#' + ',';
            return;
        }
        str = str + to_string(root->val) + ',';
        Serialize(root->left, str);
        Serialize(root->right, str);
    }
 
    void Deserialize(TreeNode** pRoot, char **str) {
        if (**str == '\0')
            return;
        if (**str == '#') {
            ++(*str);
            return;
        }
        if (**str == ',') 
            ++(*str);
        if (**str == '#') {
            ++(*str);
            return;
        }
        int num = 0;
        bool flag = false;
        while (**str != '\0' && **str != ','  && **str != '#') {
            num = num * 10 + (**str - '0');
            flag = true;
            ++(*str);
        }
        if (flag) {
            *pRoot = new TreeNode(num);
            Deserialize(&(*pRoot)->left, str);
            Deserialize(&(*pRoot)->right, str);
        }
        return;
    }
    
    char* Serialize(TreeNode *root) {    
        if (root == NULL) return NULL;
        str.clear();
        Serialize(root, str);
        str.pop_back();
        return  &str[0];
    }
    TreeNode* Deserialize(char *str) {
        if(*str=='\0' || str==NULL)
            return NULL;
        TreeNode* pRoot= new TreeNode(0);         
        Deserialize(&pRoot, &str);
        return pRoot;
    }
};
