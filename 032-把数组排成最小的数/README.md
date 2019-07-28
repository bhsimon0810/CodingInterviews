# 把数组排成最小的数

本文是[《剑指Offer》](https://www.nowcoder.com/ta/coding-interviews?page=1)刷题笔记，记录刷题过程中的体会与收获。

## 题目描述

输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。例如输入数组 {3, 32, 321}，则打印出这三个数字能排成的最小数字为 321323。

## 解题思路

直接粗暴的方法是对输入正整数数组做全排列，然后将所有整数依次拼接成字符串，然后比较大小。关于全排列的实现方法在[字符串的排列]([https://github.com/bhsimon0810/CodingInterviews/tree/master/027-%E5%AD%97%E7%AC%A6%E4%B8%B2%E7%9A%84%E6%8E%92%E5%88%97](https://github.com/bhsimon0810/CodingInterviews/tree/master/027-字符串的排列))中已经提及，但显然这种方法较为复杂，因此需要考虑更简单的实现方法。

以数组 {12, 58, 34} 为例显然可以排成的最小的数是 123458，所以若按照排成数字最小的原则对数组排序，则排序后的结果应该是 {12, 34, 58}。所以可以考虑如何实现这种排序，排好序后则可以直接将数组所有元素按顺序添加到字符串，即可打印输出。C++ 中排序函数 `sort` 可以实现排序功能，排序规则需要自定义。这种方法的复杂度显然要小于前一种方法。

通常来讲排序规则就是比较数值大小，那么我们可以定义新的“大小”规则用来排序：对于字符串 '12' 和 '34'，由于 '1234' 在字符串意义下小于 '3412'，所以有 '12' 小于 '34'；同理有 '34' 小于 '58'。按照这种大小的定义，对示例数组的排序结果是 {12, 34, 58}，显然符合我们的要求。

那么这种新定义的大小规则是否符合数学上的完备呢？可以证明是符合作为数学定义的要求的。因此可以使用这种方法来比较大小从而实现对数组排序，达到排成最小数字的目的。

## 代码示例

```C++
class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        if(numbers.size() <= 0) return "";
        string ans = "";
        sort(numbers.begin(), numbers.end(), compare);
        for(int i = 0; i < numbers.size(); i++) {
            ans += to_string(numbers[i]);
        }
        return ans;
    }

    static bool compare(int a, int b) {
        string sa = "";
        string sb = "";
        sa += to_string(a);
        sa += to_string(b);
        sb += to_string(b);
        sb += to_string(a);
        return sa < sb;
    }
    
};
```

注意 `sort` 函数的参数 `compare` 排序函数类型要求是 `static bool` 类型。
