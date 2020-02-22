# include <iostream>
# include <algorithm>

using namespace std;

const int maxn = 10000;
int value[maxn];

int main(){
    int k;
    cin >> k;

    int origin = k;
    int dp[origin];

    int a = 0;
    while(k --){
        cin >> value[a ++];
    }

    dp[0] = value[0];

    int i = 0, j = origin - 1, result = 0, flag = 1; 
    for(int m = 1; m < origin; m ++){
        dp[m] = max(value[m], dp[m - 1] + value[m]);

        if(result == dp[m] && result == 0 && flag){
            i = m;
            j = m;
            flag = 0;
        }
        if(result < dp[m]){
            result = dp[m];
            if(value[m] == dp[m]){
                i = m;
            }
            j = m;
        }
    }
    if(result == 0 && value[0] >= 0){
        result = value[0];
        i = 0;
        j = 0;
    }

    printf("%d %d %d", result, i, j);

    return 0;
}