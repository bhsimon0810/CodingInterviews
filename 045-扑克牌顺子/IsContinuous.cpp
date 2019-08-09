/* 
class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.size() != 5) return false;
        sort(numbers.begin(), numbers.end());
        int numberOfZero = 0, numberOfGap = 0;
        
        for(int i = 0; i < numbers.size() && numbers[i] == 0; i++)
            numberOfZero++;
        
        int low = numberOfZero, high = numberOfZero + 1;
        while(high < numbers.size()) {
            if(numbers[low] == numbers[high]) return false;
            numberOfGap += numbers[high] - numbers[low] - 1;
            low = high;
            high++;
        }
        return numberOfGap > numberOfZero ? false : true;
    }
};*/

// 题目要求不可能输入 5 个零，因此可以使用这种方法
class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.size() != 5) return false;
        vector<int> vec(14, 0);
        vec[0] = -5;
        int max = -1, min = 14;
        for(int i = 0; i < numbers.size(); i++) {
            vec[numbers[i]] ++;
            if(vec[numbers[i]] > 1) return false;
            if(numbers[i] == 0) continue;
            if(numbers[i] > max) max = numbers[i];
            if(numbers[i] < min) min = numbers[i];
        }
        return max - min < 5 ? true : false;
    }
};
