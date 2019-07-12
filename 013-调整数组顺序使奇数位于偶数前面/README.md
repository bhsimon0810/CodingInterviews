# 调整数组顺序使奇数位于偶数前面

本文是[《剑指Offer》](https://www.nowcoder.com/ta/coding-interviews?page=1) 刷题笔记，记录刷题过程中的体会与收获。

## 题目描述

输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。

## 解题思路

既然要调整数组中奇数和偶数之间的顺序，使得奇数位于前半部分，偶数位于后半部分，还要保持奇数和奇数、偶数和偶数之间的相对顺序保持不变，因此可以借鉴稳定的排序方法，比如冒泡或插入排序等。以插入排序为例，假设已排好部分的长度为 $k$，索引为从 $0$ 到 $k-1$；则需要找到包括索引 $k$ 在内之后的第一个奇数（索引为 $j$ ）并从后向前交换到位置 $k$ 完成一次交换。这种做法的复杂度为 $\mathcal{O}(n)$。

当然也可以采取空间换时间的做法，定义新的数组，对输入数组遍历两次。第一次插入所有奇数，第二次插入所有偶数即可。

## 代码示例

```C++
/*
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int k = 0;
        for(int i = 0; i < array.size(); i++) {
            if(array[i] % 2 == 1) {
                int j = i;
                while(j > k) {
                    int tmp = array[j];
                    array[j] = array[j - 1];
                    array[j - 1] = tmp;
                    j--;
                }
                k++;
            }
        }
    }
};
 */

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int> res;
        for(int i = 0; i < array.size(); i++) {
            if(array[i] % 2 == 1)
                res.push_back(array[i]);
        }
        for(int i = 0; i < array.size(); i++) {
            if(array[i] % 2 == 0)
                res.push_back(array[i]);
        }
        array = res;
    }
};
```



