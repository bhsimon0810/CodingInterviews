class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        int length = sequence.size();
        if(length == 0) return false;
        return Verify(sequence, 0, length - 1);
    }
    
    bool Verify(vector<int> & sequence, int start, int end) {
        
        if(start == end) return true;
        
        int root = sequence[end];

        // 二叉搜索树的左子树
        int i = start;
        for(; i < end; i++) {
            if(sequence[i] > root)
                break;
        }

        // 二叉搜索树的右子树
        for(int j = i; j < end; j++) {
            if(sequence[j] < root)
                return false;
        }
        
        bool left, right = true;

        if(i - start > 0) {
            left = Verify(sequence, start, i - 1);
        }

        if(i < end) {
            right = Verify(sequence, i, end - 1);
        }

        return left && right;

    }
};
