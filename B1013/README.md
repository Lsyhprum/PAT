# B1013. 数素数

https://pintia.cn/problem-sets/994805260223102976/problems/994805309963354112

**Note**:

PE: 最后一个无空格，错误写成第 10 个无空格

1. **特判：1 既不是素数，也不是合数**

2. 素数判断：判定 n 能否被 2，3，..., (int)sqrt(n) 整除即可(易错：包含(int)sqrt(n))

3. 素数表获取(prime.cpp)：
    1. 枚举：O(n*sqrt(n)), 范围小于 10^5
    2. 筛法：O(nloglogn), 范围更大，但需要确定大致范围（机试可先测试一遍）