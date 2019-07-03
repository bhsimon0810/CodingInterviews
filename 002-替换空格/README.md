# 替换空格

本文是[《剑指Offer》](https://www.nowcoder.com/ta/coding-interviews?page=1) 刷题笔记，记录刷题过程中的体会与收获。

## 题目描述

请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。

## 解题思路

显然一个可行的思路是从头开始扫描字符串，遇到空格字符就进行替换，但因为要替换成三个字符，所以每次替换操作需要将空格字符后面的字符依次向后移动。这种做法的复杂度将会是$O(n^2)$级别，这显然不是我们想要的结果。、

考虑从后向前扫描字符串，首先确定原始字符串的长度和空格字符数，然后可计算得到替换之后字符串的长度。那么设置双指针分别指向原始字符串和替换后的新字符串尾部，从后向前复制字符串：

- 遇到空格字符，新字符串指针向前移动三位并将相应位置字符赋值为“20%”
- 遇到非空格字符，新字符串指针向前移动一位并复制原始字符串相应位置字符
- 判决条件为新字符串指针所指位置大于原始字符串指针所指位置，此时说明字符串中仍存在空格；并且需要注意原始字符串指针所指位置的有效性

## 代码示例

```C++
class Solution {
public:
	void replaceSpace(char *str,int length) {
        if(str == NULL || length <= 0)
            return;
        int originalLength = 0;
        int numberOfSpace = 0;
        
        int i = 0;
        while(str[i] != '\0') {
            originalLength++;
            if(str[i] == ' ') {
                numberOfSpace++;
            }
            i++;
        }

        int newLength = originalLength + 2 * numberOfSpace;
        if(newLength > length) return;

        int p1 = originalLength, p2 = newLength;
        while(p1 < p2 && p1 >= 0) {
            if(str[p1] == ' ') {
                str[p2--] = '0';
                str[p2--] = '2';
                str[p2--] = '%';
            }
            else {
                str[p2--] = str[p1];
            }
            p1--;
        }
	}
};
```

