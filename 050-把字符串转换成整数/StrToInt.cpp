/*
class Solution {
public:
    int StrToInt(string str) {
        if(str.size() <= 0) return 0;
        int symbol = 1;
        int integer = 0;
        if(str[0] == '-') symbol = -1;
        for(int i = ((str[0] == '-' || str[0] == '+') ? 1 : 0); i < str.size(); i++) {
            if(str[i] < '0' || str[i] > '9')
                return 0;
            if(integer > INT_MAX / 10 ||(integer == INT_MAX / 10 && (str[i] & 0xf) > INT_MAX % 10))
                return symbol == 1 ? INT_MAX : INT_MIN;
            else
                integer = (integer << 1) + (integer << 3) + (str[i] & 0xf);
        }
        return integer * symbol;
    }
}; */

class Solution {
public:
    int StrToInt(string str) {
        if(str.size() <= 0) return 0;
        int symbol = 1;
        int integer = 0, index = 0;
        for(index = 0; index < str.size(); index++) {
            if(str[index] == '-' || str[index] == '+' || (str[index] >= '0' && str[index] <= '9'))
                break;
        }
        if(str[index] == '-') symbol = -1;
        for(int i = ((str[index] == '-' || str[index] == '+') ? index + 1 : index); i < str.size(); i++) {
            if(str[i] < '0' || str[i] > '9')
                return 0;
            if(integer > INT_MAX / 10 ||(integer == INT_MAX / 10 && (str[i] & 0xf) > INT_MAX % 10))
                return symbol == 1 ? INT_MAX : INT_MIN;
            else
                integer = (integer << 1) + (integer << 3) + (str[i] & 0xf);
        }
        return integer * symbol;
    }
};
