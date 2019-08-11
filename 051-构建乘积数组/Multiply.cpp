class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        vector<int> B;
        if(A.size() > 1) {
            B.push_back(1);
            for(int i = 1; i < A.size(); i++) {
                B.push_back(B.back() * A[i-1]);
            }
            int tmp = 1;
            for(int i = A.size() - 2; i >= 0; i--) {
                tmp *= A[i+1];
                B[i] *= tmp;
            }
        }
        return B;
    }
};
