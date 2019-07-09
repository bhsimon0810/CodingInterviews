class Solution {
public:
    int jumpFloorII(int number) {
        int result[2] = {1, 2};
        if(number <= 2) return result[number - 1];
        int sNMinusTwo = 2;
        int fNMinusOne = 2;
        int fN = 0;
        for(int i = 3; i <= number; i++) {
            fN = sNMinusTwo + fNMinusOne;
            sNMinusTwo += fNMinusOne;
            fNMinusOne = fN;
        }
        return fN;
    }
};
