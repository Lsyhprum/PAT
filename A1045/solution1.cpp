# include <iostream>
# include <algorithm>
# include <cstring>

using namespace std;

const int maxc = 210;    // 最大颜色数
const int maxn = 10010;   // 最大条纹数
int HashTable[maxc];
int A[maxn], dp[maxn];

int main(){
    int n, m, x;
    cin >> n >> m;

    memset(HashTable, -1, sizeof(HashTable));
    for(int i = 0; i < m; i ++){
        cin >> x;
        HashTable[x] = i;              // 使用数组作为 HashTable
    }

    int L, num = 0;
    cin >> L;
    for(int i = 0; i < L; i ++){
        cin >> x;
        if(HashTable[x] >= 0)
            A[num ++] = HashTable[x];  // 转化为LIS
    }

    // LIS
    int ans = -1;
    for(int i = 0; i < num; i ++){
        dp[i] = 1;
        for(int j = 0; j < i; j ++){
            if(A[j] <= A[i] && dp[i] < dp[j] + 1) 
                dp[i] = dp[j] + 1;
        }
        ans = max(ans, dp[i]);
    }

    cout << ans << endl;
   

    return 0;
}