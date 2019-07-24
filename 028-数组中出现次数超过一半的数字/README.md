# 数组中出现次数超过一半的数字

本文是[《剑指Offer》](https://www.nowcoder.com/ta/coding-interviews?page=1)刷题笔记，记录刷题过程中的体会与收获。

## 题目描述

数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为 9 的数组 {1, 2, 3, 2, 2, 2, 5, 4, 2}。由于数字2在数组中出现了 5 次，超过数组长度的一半，因此输出 2。如果不存在则输出 0。

## 解题思路

若数组中某一数字出现的次数超过一半，显然一个可行的思路是对数组排序，则位于中间位置的数字一定是要找的数字，可以通过快速排序查找到。

另外，既然要找的数字出现次数超过一半，则意味着期望数字的次数超过其余数字的总和。因此可以设置结果变量 `result` 和次数变量 `times`，每遇到相同数字加一，每遇到不同数字减一，次数为零时再重新设置结果变量和次数变量。这样遍历数组之后次数变量不为零而且此时的结果变量即为要找的数字。

还要注意判断是否有效输入，以及**通过上述方法找出的结果变量出现次数是否超过数组长度的一半**。

## 代码示例

```C++
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.size() <= 0) return 0;
        
        int result = numbers[0];
        int times = 1;
        for(int i = 1; i < numbers.size(); i++) {
            if(times == 0) {
                result = numbers[i];
                times = 1;
            }
            else if(numbers[i] == result)
                times++;
            else
                times--;
        }
        if(!CheckMoreThanHalf(numbers, result))
            result = 0;
        return result;
    }
    
    bool CheckMoreThanHalf(vector<int> & numbers, int number) {
        int times = 0;
        for(int i = 0; i < numbers.size(); i++) {
            if(numbers[i] == number) {
                times++;
            }
        }
        if(2 * times <= numbers.size())
            return false;
        else
            return true;
    }
};
```

