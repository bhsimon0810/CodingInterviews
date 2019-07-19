class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.size() == 0 || popV.size() == 0)
            return false;
        stack<int> s;
        for(int pushIndex, popIndex = 0; pushIndex < pushV.size(); pushIndex++) {
            s.push(pushV[pushIndex]);
            while(!s.empty() && popIndex < popV.size() && s.top() == popV[popIndex]) {
                s.pop();
                popIndex++;
            }
        }
        return s.empty();
    }
};
