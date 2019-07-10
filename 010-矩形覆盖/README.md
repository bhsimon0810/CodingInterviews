# 矩形覆盖

本文是[《剑指Offer》](https://www.nowcoder.com/ta/coding-interviews?page=1) 刷题笔记，记录刷题过程中的体会与收获。

## 题目描述

我们可以用 $2\times1$ 的小矩形横着或者竖着去覆盖更大的矩形。请问用 $n$ 个 $2\times1$ 的小矩形无重叠地覆盖一个 $2\times n$ 的大矩形，总共有多少种方法？

## 解题思路

仍然将问题拆解开来处理。题目示意图如下所示，可以用小矩形横向覆盖或竖向覆盖。以下图 $n = 8$ 为例，覆盖方法记为 $f(8)$。若采用最左侧竖向覆盖，则剩余覆盖方法为 $f(7)$；若采用最左侧上方横向覆盖，最左侧下方同样也能且只能横向覆盖，则剩余覆盖方法为 $f(6)$。显然这又是斐波那契数列的一种考查方式，采用迭代解法即可完成。当然也给出递归解法以供参考，不过在实际提交过程中由于内存受限，递归解法并未通过测试。

![RectCover](http://wx3.sinaimg.cn/mw690/a9d96161ly1g4ukh6lr3ij20fw04ydfz.jpg)

## 代码示例

```C++
/*
class Solution {
public:
    int rectCover(int number) {
        if(number == 1)
            return 1;
        else if(number == 2)
            return 2;
        else
            return rectCover(number - 1) + rectCover(number - 2);
    }
};
 */

class Solution {
public:
    int rectCover(int number) {
        int result[2] = {1, 2};
        if(number <= 2) return result[number - 1];
        int fibNMinusTwo = 1;
        int fibNMinusOne = 2;
        int fibN = 0;
        for(int i = 3; i <= number; i++) {
            fibN = fibNMinusTwo + fibNMinusOne;
            fibNMinusTwo = fibNMinusOne;
            fibNMinusOne = fibN;
        }
        return fibN;
    }
};
```

