class Solution {
public:
    int Fibonacci(int n) {
        int result[2] = {0, 1};
        if(n < 2) {
            return result[n];
        }
        int fibNMinusTwo = 0;
        int fibNMinusOne = 1;
        int fibN = 0;
        for(int i = 2; i <= n; i++) {
            fibN = fibNMinusTwo + fibNMinusOne;
            fibNMinusTwo = fibNMinusOne;
            fibNMinusOne = fibN;
        }
        return fibN;
    }
};
