class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if(input.size() <= 0 || input.size() < k) 
            return vector<int> ();
        
        multiset<int, greater<int> > leastNums;
        vector<int>::iterator iter = input.begin();
        for(; iter != input.end(); iter++) {
            if(leastNums.size() < k)
                leastNums.insert(*iter);
            else {
                multiset<int, greater<int> >::iterator iterGreatest = leastNums.begin();
                if(*iter < *(leastNums.begin())) {
                    leastNums.erase(iterGreatest);
                    leastNums.insert(*iter);
                }
            }
        }

        return vector<int> (leastNums.begin(), leastNums.end());
    }
};
