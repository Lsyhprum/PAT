# include <iostream>
# include <algorithm>

using namespace std;

const int N = 210;
const int M = 10010;
int fav[N];
int stripe[M];

int main(){
    int useless, m;   // n 没用
    cin >> useless >> m;

    for(int i = 1; i <= m; i ++)
        cin >> fav[i];

    int L;
    cin >> L;
    for(int i = 1; i <= m; i ++)
        cin >> stripe[i];

    int dp[m + 1][L + 1];

    for(int i = 0; i <= m; i ++)
        dp[i][0] = 0;

    for(int i = 0; i <= L; i ++)
        dp[0][i] = 0;

    for(int i = 1; i <= m; i ++){
        for(int j = 1; j <= L; j ++){
            int MAX = max(dp[i - 1][j], dp[i][j - 1]);
            if(fav[i] == stripe[j]){
                dp[i][j] = MAX + 1;
            }else{
                dp[i][j] = MAX;
            }
        }
    }

    cout << dp[m][L] << endl;

    return 0;
}