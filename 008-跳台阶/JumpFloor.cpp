class Solution {
public:
    int jumpFloor(int number) {
        int result[2] = {1, 2};
        if(number <= 2) return result[number - 1];

        int fibNMinusTwo = 1;
        int fibNMinusOne = 2;
        int fibN = 0;
        for(int i = 3; i <= number; i++) {
            fibN = fibNMinusTwo + fibNMinusOne;
            fibNMinusTwo = fibNMinusOne;
            fibNMinusOne = fibN;
        }
        return fibN;
    }
};
