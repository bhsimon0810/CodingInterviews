# 顺时针打印矩阵

本文是[《剑指Offer》](https://www.nowcoder.com/ta/coding-interviews?page=1) 刷题笔记，记录刷题过程中的体会与收获。

## 题目描述

输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果输入如下 $4\times4$ 矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 则依次打印出数字1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10.

## 解题思路

顺时针打印矩阵的过程如下所示

![PrintMatrix](http://wx4.sinaimg.cn/mw690/a9d96161ly1g541vtdpboj20a9070jrl.jpg)

从最外圈开始首先从左到右打印一行，再在这个基础上从上到下打印一列，再继续从右到左打印一行，再从下到上打印一列。这道题目没有涉及复杂的数据结构和算法，重点在考察考虑问题是否全面。设矩阵行数为 `rows`，列数为 `columns`，每次顺时针打印一圈后，行数减少 2，列数减少 2；并且每新一轮次打印输出的起点 `[start, start]` 均为矩阵主对角线元素。经分析可知，可采用循环方法，每次循环顺时针打印一圈元素，然后循环停止的条件是 `rows > 2 * start && columns > 2 * start `。

再来分析如何实现每次顺时针打印一圈矩阵元素，输入矩阵形式为 `vector<vector<int> > matrix`，因此通过简单的循环可直接将元素逐行或逐列打印（题目要求是添加进新的容器）。不过需要注意的是可以打印的条件

![PrintMartixDegradation](http://wx1.sinaimg.cn/mw690/a9d96161ly1g541vpjlqmj20gj06ndg3.jpg)

从左到右的打印一行每次循环都会执行；从上到下的打印一列可以执行的条件是起始行号小于终止行号；从右到左的打印一行可执行的条件是起始行号小于终止行号且起始列号小于终止列号，并要注意打印元素的起点；从下到上的打印一列可执行的条件是前三步操作可以执行，因此要求起始列号小于终止列号，起始行号小于终止行号，但还要求有元素可以从下到上打印输出，因此要求起始行号比终止行号小 2 才行。通过以上分析可给出相应的代码。

## 代码示例

```C++
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> mat;
        int rows = matrix.size();
        int columns = matrix[0].size();
        if(rows <= 0 || columns <= 0) {
            return mat;
        }
        
        int start = 0;
        while(rows > 2 * start && columns > 2 * start) {
            vector<int> tmp = printMatrixInCircle(matrix, rows, columns, start);
            mat.insert(mat.end(), tmp.begin(), tmp.end());
            start++;
        }
        return mat;
    }

    vector<int> printMatrixInCircle(vector<vector<int> > & matrix, int rows, int columns, int start) {
        vector<int> mat;
        int endX = columns - 1 - start;
        int endY = rows - 1 - start;

        // 从左到右打印一行
        for(int i = start; i <= endX; i++) {
            mat.push_back(matrix[start][i]);
        }

        // 从上到下打印一列
        if(start < endY) {
            for(int i = start + 1; i <= endY; i++) {
                mat.push_back(matrix[i][endX]);
            }
        }

        // 从右到左打印一行
        if(start < endX && start < endY) {
            for(int i = endX - 1; i >= start; i--) {
                mat.push_back(matrix[endY][i]);
            }
        }

        // 从下到上打印一列
        if(start < endX && start < endY - 1) {
            for(int i = endY - 1; i > start; i--) {
                mat.push_back(matrix[i][start]);
            }
        }
        
        return mat;
    }
};
```

