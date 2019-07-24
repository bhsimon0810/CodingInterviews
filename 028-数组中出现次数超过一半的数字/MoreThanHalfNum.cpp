class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.size() <= 0) return 0;
        
        int result = numbers[0];
        int times = 1;
        for(int i = 1; i < numbers.size(); i++) {
            if(times == 0) {
                result = numbers[i];
                times = 1;
            }
            else if(numbers[i] == result)
                times++;
            else
                times--;
        }
        if(!CheckMoreThanHalf(numbers, result))
            result = 0;
        return result;
    }
    
    bool CheckMoreThanHalf(vector<int> & numbers, int number) {
        int times = 0;
        for(int i = 0; i < numbers.size(); i++) {
            if(numbers[i] == number) {
                times++;
            }
        }
        if(2 * times <= numbers.size())
            return false;
        else
            return true;
    }
};
