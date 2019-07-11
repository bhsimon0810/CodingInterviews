# 数值的整数次方

本文是[《剑指Offer》](https://www.nowcoder.com/ta/coding-interviews?page=1) 刷题笔记，记录刷题过程中的体会与收获。

## 题目描述

给定一个 `double` 类型的浮点数 `base` 和 `int` 类型的整数 `exponent`。求 `base` 的`exponent` 次方。

## 解题思路

本题初看很简单，求解输入浮点数的幂次，很直观地通过递归或迭代就可以写出对应的代码，示例如下

```C++
double Power(double base, int exponent) {
    double result = 1.0;
    for(int i = 0; i <= exponent; i++) {
        result *= base;
    }
    return result;
}
```

但显然此时解题思路并不全面，没有考虑到幂次为负数的情况，以及幂次为负数时输入浮点数为零的非法情况。因此需要有判断输入浮点数是否为零的条件语句。需要注意的是，整数判等可以直接使用 `==` 运算符，但浮点数因为内存精度的影响，直接使用该运算符可能不会得到想要的结果，因此浮点数判等一般需要自定义函数。

将以上提及的情况都考虑在内之后，不妨再回过头来看一下计算幂次的过程，循环次数即为幂值。考虑到

$$
a^n=
\begin{cases}
a^{\frac{n}{2}}\cdot a^{\frac{n}{2}} & n为偶数\\
a^{\frac{n}{2}}\cdot a^{\frac{n}{2}}\cdot a & n为奇数\\
\end{cases}
$$

所以可以根据此原理采用递归方式求解幂次。常规方法的递归受限于内存不能通过测试。

## 代码示例

```C++
class Solution {
public:
    double Power(double base, int exponent) {
        if(equal(base, 0.0) && exponent < 0) {
            throw "invalid input";
        }
        double result = PowerWithUnsignedExponent(base, exponent < 0 ? - exponent : exponent);
        if(exponent < 0) {
            result = 1.0 / result;
        }
        return result;
    }

    double PowerWithUnsignedExponent(double base, int exponent) {
        if(exponent == 0) {
            return 1.0;
        }
        if(exponent == 1) {
            return base;
        }
        double result = PowerWithUnsignedExponent(base, exponent >> 1);
        result *= result;
        // exponent % 2 == 1
        if((exponent & 1) == 1) {
            result *= base;
        }
        return result;
    }

    bool equal(double d1, double d2) {
        if(d1 - d2 < 0.00001 && d1 - d2 > -0.00001)
            return true;
        else
            return false;
    }
};

/*
    double PowerWithUnsignedExponent(double base, int exponent) {
        double result = 1.0;
        for(int i = 1; i <= exponent; i++) {
            result *= base;
        }
        return result;
    }
*/
```

当然还有更简洁的写法如下

```C++
class Solution {
public:
    double Power(double base, int exponent) {
        // 首先需要对 base 与 0.0 判等，方法同上
        if(exponent > 0) {
            if(exponent == 1) {
                return base;
            }
            else if(exponent % 2 == 0) {
                // Power(base, exponent >> 1)
                return Power(base, exponent / 2) * Power(base, exponent / 2);
            }
            else {
                // Power(base, (exponent >> 1) + 1) 优先级不同
                return Power(base, exponent / 2) * Power(base, exponent / 2 + 1);
            }
        }
        else if(exponent == 0) {
            return 1.0;
        }
        else {
            return 1.0 / Power(base, - exponent);
        }
    }
};
```

