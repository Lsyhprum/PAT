# 基本知识

1. 常见评测结果
    1. 答案正确（Accepted, AC）
    2. 编译错误（Compile Error, CE）
    3. 答案错误（Wrong Answer, WA）
    4. 运行超时（Time Limit Exceeded, TLE）
    5. 运行错误（Runtime Error, RE）
    6. 内存超限（Memory Limit Exceeded, MLE）
    7. 格式错误（Presentation Error, PE）
    8. 输出超限（Output Limit Exceeded, OLE）

2. C/C++
    1. <stdio.h> 与 <cstdio>, <math.h> 与 <cmath>, <string.h> 与 <cstring> 等价

    2. 变量类型
        1. int：占用 4 Byte, 10^9 范围内可定义
        2. long long: 占用 8 Byte, 10^9 ~ 10^18
        3. float/double: 浮点型均使用 double
    
    3. 输出格式
        1. %md: 不足 m 位 int 变量以 m 位进行右对齐输出，高位空格补齐。超过 m 位，保持原样
        2. %0md: 与 %md 类似，变量不足时补'0'
        3. %.mf: 让浮点数保留 m 位小数

    4. 常见 math 函数
        1. fabs(double): 取绝对值
        2. floor(double): 向下取整
        3. ceil(double): 向上取整
        4. pow(double r, double p): r^p
        5. sqrt(double): 算术平方根
        6. round(double): 四舍五入
    
    5. 数组
        1. memset(数组名，值, sizeof(数组名)): 对数组中每个元素赋以相同值
        2. 赋初值：数组中元素若未赋初值，将会是一个随机数，若想将整个数组都赋初值 0 ， 考虑如下写法：
        > int a[10] = {0};
        > int a[10] = {};

    6. 字符数组输入输出（易错）
        1. gets/puts: gets 识别 \n 作为结束标志，因此 scanf 完一个整数后，需要使用 getchar 吞掉换行符
        2. 字符数组存放方式：字符数组末尾有一个空字符 \0, 表示存放的字符串结尾，占用一个字符位
            1. 易错1：开字符数组要比实际存储字符串长度多 1
            2. 易错2：若非 scanf/gets 获取的字符串，需加入 \0

    7. string.h 头文件
        1. strlen(): 第一个 \0 前字符个数
        2. strcmp(): 比较字符串大小
        3. strcpy(s1, s2): 将 s2 复制给 s1
        4. strcat(s1, s2): 将 s2 连接到 s1 后 
        5. sscanf/sprintf(s, "%d", &n/n)：将 str 中内容以某种格式写入/表示

    8. 指针与数组
        1. 指针加减法，结果为两个地址偏移的距离。p+1 指 p 所指 int 变量下一个 int 型变量地址
        2. 数组名称可作为数组首地址使用，a+i 等价于 &a[i]

    9. 浮点数的比较
        1. 浮点数比较：浮点数在计算机中存储不精确，无法通过 == 比较，因此需要判断两浮点数差是否落入一个极小区间，极小数 eps 一般取 1e-8 
        2. 等于：fabs(a-b) < eps


