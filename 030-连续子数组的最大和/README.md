# 连续子数组的最大和

本文是[《剑指Offer》](https://www.nowcoder.com/ta/coding-interviews?page=1)刷题笔记，记录刷题过程中的体会与收获。

## 题目描述

HZ 偶尔会拿些专业问题来忽悠那些非计算机专业的同学。今天测试组开完会后，他又发话了：在古老的一维模式识别中，常常需要计算连续子向量的最大和，当向量全为正数的时候，问题很好解决。但是，如果向量中包含负数，是否应该包含某个负数，并期望旁边的正数会弥补它呢？例如：{6, -3, -2, 7, -15, 1, 2, 2} 连续子向量的最大和为8（从第 0 个开始，到第 3 个为止）。给一个数组，返回它的最大连续子序列的和，你会不会被他忽悠住？（子向量的长度至少是1）

## 解题思路

求解连续子数组的最大和，最直接的解法是找出输入数组的所有子数组，然后分别求和作比较，这种方法的复杂度是 $\mathcal{O}(n^2)$，显然不是我们想要的结果。因为要求连续子数组的最大和，假如输入数组 `array` 的前 k 数字之和为负，则显然此时的最大和应直接设为 `array[k]` ，显然继续叠加下去的和并不如当前元素值大。然后设置全局的子数组最大和，每次当前元素求和计算结果与全局最大和作比较决定是否更新即可。

再继续思考，本道题目实质上递推关系式如下

```
F(0) = array[0]
nGreatestSum = array[0]
......
F(k) = max(F(k-1)+array[k], array[k])
nGreatestSum  = max(F(k),nGreatestSum)
```

因此也可以按这种思路求解，相应的代码均给出了示例并通过了所有测试用例。

## 代码示例

```C++
/*

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.size() <= 0) return 0;

        int nCurSum = array[0];
        int nGreatestSum = array[0];
        for(int i = 1; i < array.size(); i++) {
            if(nCurSum < 0)
                nCurSum = array[i];
            else 
                nCurSum += array[i];
            
            if(nCurSum > nGreatestSum)
                nGreatestSum = nCurSum;
        }
        return nGreatestSum;
    }
}; */

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.size() <= 0) return 0;

        int nCurSum = array[0];
        int nGreatestSum = array[0];

        for(int i = 1; i < array.size(); i++) {
            nCurSum = max(nCurSum + array[i], array[i]);
            nGreatestSum = max(nCurSum, nGreatestSum);
        }
        return nGreatestSum;
    }
};
```

