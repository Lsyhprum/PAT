# include <iostream>
# include <algorithm>

using namespace std;

const int maxn = 110;
int w[maxn];
int c[maxn];
int dp[maxn] = {};           // 滚动数组

int main(){
    int n, V;

    cin >> n >> V;
    for(int i = 0; i < n; i ++){
        cin >> w[i];
    }
    for(int i = 0; i < n; i ++){
        cin >> c[i];
    }

    for(int i = 1; i <= n; i ++){
        for(int v = V; v >= w[i]; v --){          // 只能从右向左
            dp[v] = max(dp[v], dp[v - w[i]] + c[i]);
        }
    }

    int max = 0;
    for(int v = 0; v <= V; v ++){
        if(dp[v] > max)
            max = dp[v];
    }

    cout << max << endl;

    return 0;
}