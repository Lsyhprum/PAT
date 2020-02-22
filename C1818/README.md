# C1818. 最大公约数

http://codeup.cn/problem.php?id=1818

**Note**:

1. 递归的两个关键：**递归式**、**递归边界**

2. gcd（Greatest Common Divisor） : 欧几里得算法（辗转相除法）
    1. 递归式：gcd(a, b) == gcd(b, a % b)
    2. 边界条件：gcd(a, 0) = a

3. lcm (Least Common Multiple) : a / db（ab 可能溢出）