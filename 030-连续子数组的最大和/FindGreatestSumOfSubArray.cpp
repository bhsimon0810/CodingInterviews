/*

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.size() <= 0) return 0;

        int nCurSum = array[0];
        int nGreatestSum = array[0];
        for(int i = 1; i < array.size(); i++) {
            if(nCurSum < 0)
                nCurSum = array[i];
            else 
                nCurSum += array[i];
            
            if(nCurSum > nGreatestSum)
                nGreatestSum = nCurSum;
        }
        return nGreatestSum;
    }
}; */

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.size() <= 0) return 0;

        int nCurSum = array[0];
        int nGreatestSum = array[0];

        for(int i = 1; i < array.size(); i++) {
            nCurSum = max(nCurSum + array[i], array[i]);
            nGreatestSum = max(nCurSum, nGreatestSum);
        }
        return nGreatestSum;
    }
};
