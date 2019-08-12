class Solution {
public:
    bool isNumeric(char* string)
    {
        // 数字格式为 A[.[B]][e|EC] 或者 .B[e|EC]
        // 其中 A 和 C 都是有符号整数，B 是无符号整数
        if(string == nullptr)
            return false;
        // 扫描 A 部分
        bool numeric = scanInteger(&string);
        // 判断小数点并处理 B 部分
        if(*string == '.')
        {
            ++string;
            // 小数点没有整数部分 .123 || 小数点后面没有数字 123. || 小数点前后都有数字
            numeric = scanUnsignedInteger(&string) || numeric;
        }
        // 判断指数并处理 C 部分
        if(*string == 'e' || *string == 'E')
        {
            ++string;
            // 字符 e|E 前面没有数字或者后面没有整数时，字符串不能表示数字
            numeric = scanInteger(&string) && numeric;
        }
        // 扫描结束
        return numeric && *string == '\0';
    }
    
    bool scanUnsignedInteger(char** string) 
    {
        const char * orig = *string;
        while(**string != '\0' && **string >= '0' && **string <= '9') 
            ++(*string);
        return *string > orig;
    }

    bool scanInteger(char** string)
    {
        if(**string == '+' || **string == '-')
            ++(*string);
        return scanUnsignedInteger(string);
    }

};
