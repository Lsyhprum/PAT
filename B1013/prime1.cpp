# include <iostream>
# include <cmath>

using namespace std;

// 暴力法求解 100 以内素数

const int maxn = 101;
int prime[maxn];  // 素数表
int pNum = 0;

bool is_prime(int n){
    for(int i = 2; i <= (int)sqrt(n); i ++){  // 反思：（int)sqrt() 边界易错
        if(n % i == 0)
            return false;
    }
    return true;
}

void find_prime(){
    for(int i = 2; i < maxn; i ++){
        if(is_prime(i))
            prime[++ pNum] = i;
    }
}

int main(){
    find_prime();

    for(int i = 1; i <= pNum; i ++){
        cout << prime[i] << endl;
    }
    return 0;
}