# include <iostream>

using namespace std;

// 筛选法求解 100 以内素数

const int maxn = 101;
int prime[maxn];  // 素数表
bool p[maxn] = {};   // 赋初值
int pNum = 0;

void find_prime(){
    for(int i = 2; i < maxn; i ++){
        if(!p[i]){
            prime[++ pNum] = i;
        }
        for(int j = i + i; j < maxn; j += i){   // 反思：j+=i 易错
            p[j] = true;
        }
    }
}

int main(){
    find_prime();

    for(int i = 1; i <= pNum; i ++){
        cout << prime[i] << endl;
    }
    return 0;
}