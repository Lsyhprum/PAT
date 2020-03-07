# include <iostream>
# include <algorithm>

using namespace std;

const int maxn = 110;
int w[maxn];
int c[maxn];
int dp[maxn][maxn] = {};

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
        for(int v = w[i]; v <= V; v ++){
            dp[i][v] = max(dp[i - 1][v], dp[i - 1][v - w[i]] + c[i]); 
        }
    }

    int max = 0;
    for(int v = 0; v <= V; v ++){
        if(dp[n][v] > max)
            max = dp[n][v];
    }
    cout << max << endl;

    return 0;
}