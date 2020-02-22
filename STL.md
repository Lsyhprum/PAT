# STL

1. vector(变长数组)
    1. 二维数组定义：vector<type> name[size]
    2. 访问
        1. 下标访问
        2. 迭代器访问：vector<type>::iterator it; it 可通过类似下标和指针访问数组的方式访问容器内元素
    3. push_back(): 添加元素
    4. pop_back(): 删除尾元素
    5. size(): 获取容器内元素个数
    6. clear(): 清空容器
    7. insert(): 指定位置插入一个元素
    8. erase(): 删除单个元素、删除一个区间内所有元素

2. set
    1. 访问：STL 容器除了 vector 和 string 都不支持 *(it + i)，只能通过 begin/end 迭代
    2. set 内元素自动递增，且自动去重
    3. find(value): 查找元素并返回迭代器

3. string
    1. substr(pos, len): 返回从 pos 号位开始、长度为 len 的子串
    2. string::npos: find() 失配时的返回值
    3. find(): 返回子串第一次出现的位置

4. map

5. queue

6. priority_queue

7. stack

8. pair

9. algorithm
    1. max，min, abs
    2. swap()
    3. reverse()
    4. next_permutation()
    5. fill(): 将容器区间内赋为某个相同的值
    6. sort(首地址，尾地址+1，cmp)
    7. lower_bound()/ upper_bound()