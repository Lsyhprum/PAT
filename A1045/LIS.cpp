# include <iostream>
# include <algorithm>

using namespace std;

const int N = 100;
int A[N], dp[N];

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i ++)
        cin >> A[i];

    for (int i = 0; i < n; i ++){
        dp[i] = 1;                      // 假设自成一个子序列
        for(int j = 0; j < i; j ++){
            if(A[i] >= A[j] && (dp[i] < dp[j] + 1))
                dp[i] = dp[j] + 1;
        }
    }

    int max = 1;
    for(int i = 0; i < n;i ++)
        max = dp[i] > max ? dp[i] : max;

    cout << max << endl;

    return 0;
}