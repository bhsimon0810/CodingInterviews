class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if(data.size() < 2) return;
        int tmp = 0;
        for(int i = 0; i < data.size(); i++)
            tmp ^= data[i];
        if(tmp == 0) return;
        int index = 0;
        while((tmp & 1) == 0) {
            tmp = tmp >> 1;
            index++;
        }
        *num1 = *num2 = 0;
        for(int i = 0; i < data.size(); i++) {
            if(IsBit(data[i], index))
                *num1 ^= data[i];
            else
                *num2 ^= data[i];
        }
    }
    
    bool IsBit(int num, int index) {
        num = num >> index;
        return (num & 1);
    }
};
