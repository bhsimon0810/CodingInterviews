class Solution {
public:
    bool match(char* str, char* pattern)
    {
        if(str == nullptr || pattern == nullptr)
            return false;
        return matchCore(str, pattern);
    }
    
    bool matchCore(char* str, char* pattern)
    {
        // str 和 pattern 全都匹配到尾部
        if(*str == '\0' && *pattern == '\0')
            return true;
        // pattern 已经匹配到尾
        if(*str != '\0' && *pattern == '\0')
            return false;
        // pattern 下一字符为'*'，分两种情况讨论：当前字符相等或者不等
        if(*(pattern + 1) == '*')
        {
            // 当前字符相等
            if(*pattern == *str || (*pattern == '.' && *str != '\0'))
            {
                // move to the next state || stay on the current state || ignore '*'
                return matchCore(str + 1, pattern + 2) || matchCore(str + 1, pattern) || matchCore(str, pattern + 2);
            }
            // 当前字符不等
            else
            {
                return matchCore(str, pattern + 2);
            }
        }
        else
        {
            if(*pattern == *str || (*pattern == '.' && *str != '\0'))
                return matchCore(str + 1, pattern + 1);
        }
        return false;
    }
};
