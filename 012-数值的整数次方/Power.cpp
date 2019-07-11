class Solution {
public:
    double Power(double base, int exponent) {
        if(equal(base, 0.0) && exponent < 0) {
            throw "invalid input";
        }
        if(exponent > 0) {
            if(exponent == 1) {
                return base;
            }
            else if(exponent % 2 == 0) {
                return Power(base, exponent / 2) * Power(base, exponent / 2);
            }
            else {
                return Power(base, exponent / 2) * Power(base, exponent / 2 + 1);
            }
        }
        else if(exponent == 0) {
            return 1.0;
        }
        else {
            return 1.0 / Power(base, - exponent);
        }
    }
    bool equal(double d1, double d2) {
        if(d1 - d2 < 0.00001 && d1 - d2 > -0.00001)
            return true;
        else
            return false;
    }
};
