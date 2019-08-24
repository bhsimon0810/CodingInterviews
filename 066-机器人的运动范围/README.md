# 机器人的运动范围

本文是[《剑指Offer》](https://www.nowcoder.com/ta/coding-interviews?page=1)刷题笔记，记录刷题过程中的体会与收获。

## 题目描述

地上有一个 m 行和 n 列的方格。一个机器人从坐标 (0,0) 的格子开始移动，每一次只能向左、右、上、下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于 k 的格子。 例如，当 k 为 18 时，机器人能够进入方格 (35,37)，因为 3+5+3+7 = 18。但是，它不能进入方格 (35,38)，因为 3+5+3+8 = 19。请问该机器人能够达到多少个格子？

## 解题思路

显然本题考察回溯算法。当机器人准备进入方格 `(i,j)` 时，需要根据坐标数位和来判断准入条件。若可以进入方格，下一步要再考虑上下左右共四个相邻的方格。注意为避免重复计数，需要为每个方格设置标志位表示是否已经访问过，若已经访问过，则不能再次计数。另外还要对输入作边界条件的检查。

## 代码示例

```C++
class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        if(threshold < 0 || rows < 1 || cols < 1)
            return 0;
        bool *visited = new bool[rows * cols];
        memset(visited, 0, rows * cols);
        int count = movingCountCore(threshold, rows, cols, 0, 0, visited);
        delete [] visited;
        return count;
    }

    int movingCountCore(int threshold, int rows, int cols, int row, int col, bool* visited)
    {
        int count = 0;
        if(check(threshold, rows, cols, row, col, visited))
        {
            visited[row * cols + col] = true;
            count = 1 + movingCountCore(threshold, rows, cols, row - 1, col, visited)
                      + movingCountCore(threshold, rows, cols, row + 1, col, visited)
                      + movingCountCore(threshold, rows, cols, row, col - 1, visited)
                      + movingCountCore(threshold, rows, cols, row, col + 1, visited);
        }
        return count;
    }

    bool check(int threshold, int rows, int cols, int row, int col, bool* visited)
    {
        if(row >= 0 && row < rows && col >= 0 && col < cols && getDigitSum(row, col) <= threshold && !visited[row * cols + col])
            return true;
        else
            return false;
    }

    int getDigitSum(int row, int col)
    {
        int sum = 0;
        while(row > 0 || col > 0)
        {
            sum += row % 10;
            sum += col % 10;
            row /= 10;
            col /= 10;
        }
        return sum;
    }
};
```

