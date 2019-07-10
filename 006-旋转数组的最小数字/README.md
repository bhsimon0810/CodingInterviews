# 旋转数组的最小数字

本文是[《剑指Offer》](https://www.nowcoder.com/ta/coding-interviews?page=1) 刷题笔记，记录刷题过程中的体会与收获。

## 题目描述

把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。 例如数组 $\{3,4,5,1,2\}$ 为 $\{1,2,3,4,5\}$ 的一个旋转，该数组的最小值为 1。 NOTE：给出的所有元素都大于 0，若数组大小为 0，请返回 0。

## 解题思路

假设示例旋转数组为 $\{3,4,5,1,2\}$，即旋转数组中无重复元素出现，那么此时可以使用二分法，设置指针 `low` 和 `high`，令 `mid` 指向中间位置

- `rotateArray[mid] >= rotateArray[low]` ：`mid` 指向前半段有序数组，`low` 应向后移动
- `rotateArray[mid] <= rotateArray[high]`：`mid` 指向后半段有序数组，`high` 应向前移动
- 移动到 `high - low == 1` 时，此时 `rotateArray[high]` 即为最小元素

此时的解法对于数组所有元素相等的情况同样成立。但对本题目二分法设置 `mid` 指针来讲，实质上是想定位 `rotateArray[mid]` 位于前半段有序数组还是后半段有序数组，因此对于不能成功定位的情况需要予以特殊处理。

比如对于旋转数组 $\{1,0,1,1,1\}$ 和 $\{1,1,1,0,1\}$，`mid = 2` 时并不能成功定位在前半段还是后半段，此时可行的办法就是顺序查找。

另外还要注意，若输入的数组未经过旋转，即旋转的元素个数为零，此时应该直接返回数组首元素，不应经过复杂比较。因此需要有判断条件 `rotateArray[low] >= rotateArray[high]`，若不满足直接返回数组首元素。

## 代码示例

```C++
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.size() <= 0) {
            throw "invalid parameters!";
        }
        int low = 0, high = rotateArray.size() - 1;
        int mid = low;
        while(rotateArray[low] >= rotateArray[high]) {
            if(high - low == 1) {
                return rotateArray[high];
            }

            mid = low + (high - low) / 2;
            if(rotateArray[low] == rotateArray[high] && rotateArray[low] == rotateArray[mid]) {
                return minNumberInOrder(rotateArray, low, high);
            }
            else if(rotateArray[mid] >= rotateArray[low]) {
                low = mid;
            }
            else if(rotateArray[mid] <= rotateArray[high]) {
                high = mid;
            }
        }
        return rotateArray[mid];
    }
    
    int minNumberInOrder(vector<int> & Array, int low, int high) {
        int minNumber = Array[low];
        for(int i = low + 1; i <= high; i++) {
            if(minNumber > Array[i]) {
                minNumber = Array[i];
            }
        }
        return minNumber;
    }
};
```

