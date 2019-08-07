class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > results;
        if(sum < 3) return results;
        int plow = 1, phigh = 2;
        int middle = (1 + sum) / 2;
        while(plow < middle) {
            int cur = (plow + phigh) * (phigh - plow + 1) / 2;
            if(cur == sum) {
                vector<int> result;
                for(int i = plow; i <= phigh; i++)
                    result.push_back(i);
                results.push_back(result);
                plow++;
            }
            else if(cur < sum)
                phigh++;
            else
                plow++;
        }
        return results;
    }
};
