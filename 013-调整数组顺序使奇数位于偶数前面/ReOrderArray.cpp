/*
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int k = 0;
        for(int i = 0; i < array.size(); i++) {
            if(array[i] % 2 == 1) {
                int j = i;
                while(j > k) {
                    int tmp = array[j];
                    array[j] = array[j - 1];
                    array[j - 1] = tmp;
                    j--;
                }
                k++;
            }
        }
    }
};
 */

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int> res;
        for(int i = 0; i < array.size(); i++) {
            if(array[i] % 2 == 1)
                res.push_back(array[i]);
        }
        for(int i = 0; i < array.size(); i++) {
            if(array[i] % 2 == 0)
                res.push_back(array[i]);
        }
        array = res;
    }
};
