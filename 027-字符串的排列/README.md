# 字符串的排列

本文是[《剑指Offer》](https://www.nowcoder.com/ta/coding-interviews?page=1)刷题笔记，记录刷题过程中的体会与收获。

## 题目描述

输入一个字符串，按字典序打印出该字符串中字符的所有排列。例如输入字符串 `abc`，则打印出由字符 `a`、`b`、`c` 所能排列出来的所有字符串 `abc`，`acb`，`bac`，`bca`，`cab` 和 `cba`。

## 输入描述

输入一个字符串，长度不超过 9（可能有字符重复），字符只包括大小写字母。

## 解题思路

本题实质上就是全排列问题，并且按照字典序打印输出。对于 n 个字符的全排列，首先考虑 n 字符均不相同的情况。此时求整个字符串的排列可以看成两步：首先求所有可能出现在第一个位置的字符，然后固定第一个字符，求 n-1 字符的全排列。具体操作方法是把第一个字符与后面所有字符交换，然后再递归求解 n-1 字符的排列。

需要注意的是，若输入的字符串中包含相同字符，则必须判断当前产生的排列（字符串）是否与已经统计过的排列相同，若不同则当前排列是有效的。然后还要注意要按照字典序打印输出所有的字符排列，对所有字符排列进行排序即可。

## 代码示例

```C++
class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> strlist;
        if(str.empty()) return strlist;
        Permutation(strlist, str, 0);
        // 按字典顺序排序
        sort(strlist.begin(), strlist.end());
        return strlist;
    }
    
    void Permutation(vector<string> & strlist, string str, int begin) {
        if(begin == str.size() - 1) {
            // 当前字符排列不重复
            if(find(strlist.begin(), strlist.end(), str) == strlist.end()) {
                strlist.push_back(str);
            }
        }
        else {
            for(int i = begin; i < str.size(); i++) {
                swap(str[begin], str[i]);
                Permutation(strlist, str, begin + 1);
                swap(str[begin], str[i]);
            }
        }
    }
    
    void swap(char & ch1, char & ch2) {
        char tmp = ch1;
        ch1 = ch2;
        ch2 = tmp;
    }
};
```

代码示例中对字符排列判重的处理方法是对 `strlist` 中查找当前字符排列，若查找不到则添加进列表中。当然还有其他判重方法，比如可以从字符串递归过程考虑如何不产生重复的字符排列；既然用到查找判重，也可以使用容器 `map` 用内存换时间实现 $\mathcal{O}(1)$ 范围下的查重。
