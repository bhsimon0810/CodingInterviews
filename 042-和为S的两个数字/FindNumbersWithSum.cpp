class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> result;
        if(array.size() < 2) return result;
        int plow = 0, phigh = array.size() - 1;
        while(plow < phigh) {
            if(array[plow] + array[phigh] == sum) {
                result.push_back(array[plow]);
                result.push_back(array[phigh]);
                break;
            }
            while(plow < phigh && array[plow] + array[phigh] < sum) plow++;
            while(plow < phigh && array[plow] + array[phigh] > sum) phigh--;
        }
        return result;
    }
};
