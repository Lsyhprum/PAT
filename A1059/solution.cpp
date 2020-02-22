# include <iostream>

using namespace std;

struct factor{
    int x, cnt;
}facs[10];

// 筛法常用变量
const int maxn = 100001;
int prime[maxn];
bool p[maxn] = {};
int pNum = 0;

void find_prime(){
    for(int i = 2;i < maxn;i ++){
        if(!p[i]){
            prime[pNum ++] = i;
            for(int j = i + i;j < maxn;j += i)
                p[j] = true;
        }
    }
}

int main(){
    find_prime();

    int n;
    cin >> n;

    // 特判
    if(n == 1){
        printf("1=1");
        return 0;
    }

    printf("%d=", n);

    int num = 0;  // 素数表
    int i = -1; // 质因数个数
    while(1){
        if(n % prime[num] == 0){
            facs[++ i].x = prime[num];
            facs[i].cnt = 0;
        }
        while(n % prime[num] == 0){
            facs[i].cnt += 1;
            n /= prime[num];

            // 全部分解完成
            if(n == 1){
                for(int j = 0; j <= i; j ++){
                    if(j != 0){
                        printf("*");
                    }
                    if(facs[j].cnt == 1){
                        printf("%d", facs[j].x);
                    }else{
                        printf("%d^%d", facs[j].x, facs[j].cnt);
                    }
                }
                return 0;
            }
        }
        num ++;
    }

    return 0;
}