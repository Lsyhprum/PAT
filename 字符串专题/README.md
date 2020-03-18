# 字符串 hash

# KMP 算法

## next 算法

next[i] 就是子串 s[0..i] 的最长相等前后缀最后一位的下标

步骤：

1. 初始化 next 数组，令 j = next[0] = -1
2. 让 i 在 1 —— len-1 遍历，对每个 i, 执行 3，4，求解 next[i]
3. 令 j = next[j]，直到 j 回退到 -1，或 s[i] = s[j+1] 成立
4. 若 s[i] = s[j+1]，则 next[i] = j + 1，否则 next[i] = j

```cpp
void getNext(char s[], int len){
    int j = -1;
    next[0] = -1;

    for(int i = 1; i < len; i ++){
        while(j != - 1 && s[i] != s[j+1]){
            j = next[j];
        }

        if(s[i] == s[j+1]){
            j ++
        }

        next[i] = j;
    }
}

```

## KMP 算法

步骤：
1. 初始化 j = -1, 表示 pattern 当前已被匹配的最后位
2. 让 i 遍历文本串 text, 对每个 i, 执行 3,4 来试图匹配 text[i] 和 pattern[j + 1]
3. 令 j = next[j], 直到 j 回退为 -1，或是 text[i] == pattern[j + 1] 成立
4. 如果 text[i] == pattern[j + 1]，则令 j ++，如果 j 达到 m-1, 说明 pattern 是 text 的子串，返回 true

```cpp
bool KMP(char text[], char pattern[]){
    int n = strlen(text), m = strlen(pattern);

    getNext(pattern, m);

    int j = -1;
    for(int i = 0; i < n; i++){
        while(j != -1 && text[i] != pattern[j + 1]){
            j = next[j];
        }
        if(text[i] == pattern[j+1]){
            j ++;
        }
        if(j == m - 1){
            return true;
        }
    }

    return false;
}

```