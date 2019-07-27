/* 
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int count = 0; // 出现 1 的次数
        int i = 1; // 当前位数
        int current = 0, before = 0, after = 0;
        
        while(n / i) 
        {
            current = (n / i) % 10;
            before = n / (i * 10);
            after = n - (n / i) * i;

            if(current == 0)
                count += before * i;
            else if(current == 1)
                count += before * i + after + 1;
            else 
                count += (before + 1) * i;
            
            i *= 10;
        }

        return count;
    }
};*/

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n) {
        if(n <= 0) return 0;
        int count = 0;
        for(int i = 1; i <= n; i *= 10) {
            int div = i * 10;
            count += (n / div) * i + min(max(n % div - i + 1, 0), i);
        }
        return count;
    }
};
