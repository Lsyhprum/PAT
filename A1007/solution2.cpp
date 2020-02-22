# include <iostream>
# include <algorithm>

using namespace std;

const int maxn = 10000;
int value[maxn];

int main(){
    int k;
    cin >> k;
    int tmp = k;

    int a = 0;
    bool flag = true;            // 特例额外处理
    while(tmp --){
        cin >> value[a];
        if(value[a++] >= 0)
            flag = false;
    }

    if(flag){
        printf("0 %d %d", value[0], value[k-1]);
        return 0;
    }
        

    int dp[k], begin[k];
    dp[0] = value[0];
    begin[0] = 0;

    for(int i = 1; i < k; i ++){
        dp[i] = max(value[i], dp[i - 1] + value[i]);
        
        if(value[i] >= dp[i - 1] + value[i]){ // 反思：应该从状态转移方程右侧入手
            begin[i] = i;
        }else{
            begin[i] = begin[i - 1];
        }
    }

    int j = 0; // 初始值设为全负情况
    for(int i = 1; i < k; i ++){
        if(dp[i] > dp[j])
            j = i;
    }
    
    printf("%d %d %d", dp[j], value[begin[j]], value[j]);

    return 0;
}