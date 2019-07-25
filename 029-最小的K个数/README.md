# 最小的K个数

本文是[《剑指Offer》](https://www.nowcoder.com/ta/coding-interviews?page=1)刷题笔记，记录刷题过程中的体会与收获。

## 题目描述

输入 n 个整数，找出其中最小的 k 个数。例如输入 4, 5, 1, 6, 2, 7, 3, 8这 8 个数字，则最小的 4 个数字是 1, 2, 3, 4。

## 解题思路

类似于前一题[数组中出现次数超过一半的数字]([https://github.com/bhsimon0810/CodingInterviews/tree/master/028-%E6%95%B0%E7%BB%84%E4%B8%AD%E5%87%BA%E7%8E%B0%E6%AC%A1%E6%95%B0%E8%B6%85%E8%BF%87%E4%B8%80%E5%8D%8A%E7%9A%84%E6%95%B0%E5%AD%97](https://github.com/bhsimon0810/CodingInterviews/tree/master/028-数组中出现次数超过一半的数字))，可行的思路是对输入的所有整数按升序排序，然后依次返回前 k 数字即可。当然学习过快速排序，其中配分函数的作用是将随机选中锚点 `pivot`，然后将小于锚点的元素移到左边，大于锚点的元素移到右边，然后返回锚点的索引值。因此可利用此配分函数，输入数组记为`input`，若返回的索引值为 k，则说明元素 `input[0:k-1]` 均小于 `input[k]`，而元素 `input[k+1:]` 均大于 `input[k]`，题目没有要求有序返回的最小的 k 个数，因此这种方法也是可行的。

上述两种方法的相同点是通过排序改变了输入的数组，因此若要求不能改变原始数组，则需要考虑下面的方法。首先定义大小为 k 的数据容器，然后从输入数组中读取数据到容器中。若容器未满则直接读入，若容器已满则每次读取新的数据，需要比较容器中的最大值，若新读入数据小于容器已有数据的最大值，则删除已有数据最大值并将新读入数据插入容器中。这样保证容器中存储的数据始终是当前已读入数据中最小的 k 个数字。因为涉及容器最大值问题，因此考虑使用 `heap` 或 `set` 等结构来实现我们所需要的数据容器。

`multiset` 是基于红黑树实现的有序容器并允许有重复元素，可以通过指定排序方式实现类似最大堆、最小堆的功能，其中默认排序为升序排序。具体示例如下

```C++
multiset<int, greater<int>> greadterSet;
    multiset<int, less<int>> lessSet;
    multiset<int> defaultSet;

    for (int i = 0; i < 10; i++) {
        // arc4random_uniform 生成 0~9 的32为随机整数
        int v = int(arc4random_uniform(10));
        greadterSet.insert(v);
        lessSet.insert(v);
        defaultSet.insert(v);
    }

    for (auto v: greadterSet) {
        printf("%d ", v);
    }
    printf("\n");
    for (auto v: lessSet) {
        printf("%d ", v);
    }
    printf("\n");
    for (auto v: defaultSet) {
        printf("%d ", v);
    }
    printf("\n");
```

输出结果为

```C++
9 9 8 7 7 5 4 1 0 0 
0 0 1 4 5 7 7 8 9 9 
0 0 1 4 5 7 7 8 9 9 
```

## 代码示例

```C++
/*
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if(input.size() <= 0 || input.size() < k || k < 0)
            return vector<int> ();
        if(input.size() == k)
            return input;
        
        int start = 0, end = input.size() - 1;
        int index = Partition(input, start, end);
        while(index != k - 1) {
            if(index > k - 1) {
                end = index - 1;
                index = Partition(input, start, end);
            }
            else {
                start = index + 1;
                index = Partition(input, start, end);
            }
        }

        vector<int> result(input.begin(), input.begin() + k);
        
        return result;
    }

    int Partition(vector<int> & input, int start, int end) {

        int index = (rand() % (end - start + 1)) + start;
        Swap(input[index], input[end]);
        
        int small = start - 1;
        for(index = start; index < end; index++) {
            if(input[index] < input[end]) {
                small++;
                if(small != index)
                    Swap(input[small], input[index]);
            }
        }
        small++;
        Swap(input[small], input[end]);
        return small;
    }

    void Swap(int & a, int & b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
}; */

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if(input.size() <= 0 || input.size() < k) 
            return vector<int> ();
        
        multiset<int, greater<int> > leastNums;
        vector<int>::iterator iter = input.begin();
        for(; iter != input.end(); iter++) {
            if(leastNums.size() < k)
                leastNums.insert(*iter);
            else {
                multiset<int, greater<int> >::iterator iterGreatest = leastNums.begin();
                if(*iter < *(leastNums.begin())) {
                    leastNums.erase(iterGreatest);
                    leastNums.insert(*iter);
                }
            }
        }

        return vector<int> (leastNums.begin(), leastNums.end());
    }
};
```

基于配分函数的方法在实际测试中由于内存限制没有通过，另外直接基于全排序使用 `sort` 函数是相对来说简单但复杂度稍微高一点的解法。
