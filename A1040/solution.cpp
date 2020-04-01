# include <iostream>

using namespace std;

const int maxn = 100001;
const int N = 1000000007;
int P[maxn] = {};
int T[maxn] = {};


int main(){
    string s;
    cin >> s;

    P[0] = s[0] == 'P' ? 1 : 0;
    for(int i = 1; i < s.length(); i ++){
        P[i] = P[i-1];
        if(s[i] == 'P'){
            P[i] += 1;
        }
    }   

    T[s.length() - 1] = s[s.length() - 1] == 'T' ? 1 : 0;
    for(int i = s.length() - 2; i >= 0; i --){
        T[i] = T[i + 1];
        if(s[i] == 'T'){
            T[i] += 1;
        }
    }

    int res = 0;
    for(int i = 1; i <= s.length() - 2; i ++){
        if(s[i] == 'A'){
            res = (res + P[i] * T[i]) % N;
        }
    }
    cout << res << endl;
    return 0;
}