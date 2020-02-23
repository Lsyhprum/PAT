# include <iostream>
# include <algorithm>

using namespace std;

const int maxn = 201;
const int maxl = 10001;
int fav[maxn];
int stripe[maxl];
int dp[maxl] = {};
int n, m, l;

int find_pos(int value){
    int pos = -1;
    for(int i = 0; i < m; i ++)
        if(value == fav[i])
            return i;
}

int main(){
    cin >> n >>m;
    
    for(int i = 0; i < m; i ++)
        cin >> fav[i];

    cin >> l;

    for(int i = 0; i < l; i ++)
        cin >> stripe[i];

    int tmp = 0;
    for(int i = 0; i < l; i ++){
        int posi = find_pos(stripe[i]);
        dp[i] = posi == -1 ? 0 : 1;

        for(int j = 0; j < i; j ++){
            int posj = find_pos(stripe[j]);

            if(posi >= posj && dp[i] < dp[j] + 1){
                dp[i] = dp[j] + 1;
            }
        }
        tmp = max(dp[i], tmp);
    }

    cout << tmp << endl;

    return 0;
}