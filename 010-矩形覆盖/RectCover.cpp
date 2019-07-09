/*
class Solution {
public:
    int rectCover(int number) {
        if(number == 1)
            return 1;
        else if(number == 2)
            return 2;
        else
            return rectCover(number - 1) + rectCover(number - 2);
    }
};
 */

class Solution {
public:
    int rectCover(int number) {
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
