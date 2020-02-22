# include <iostream>
# include <math.h>
# define NUM 100

using namespace std;

// O(n*sqrt(n))
bool is_prime(int n){
    // sqr = (int)sqrt(1.0 * n)
    // i * i
    for(int i = 2; i <= (int)sqrt(n); i ++){
        if(n % i == 0)
            return false;
    }
    return true;
}

void find_prime(int prime[]){
    int n = 0;
    for(int i = 2; i < NUM; i ++){
        if(is_prime(i)){
            prime[n ++] = i;
            cout << prime[n -1] << endl;;
        }
    }
}

//O(nloglogn)
void eratosthenes(int prime[]){
    int pNum = 0;
    bool p[NUM + 1] = {0};   // ? // Num + 1 更方便
    for(int i = 2; i <= NUM; i ++){
        if(!p[i]){
            prime[pNum ++] = i;
            cout << i << endl;
            for(int j = i + i; j <= NUM;j += i){
                p[j] = true;
            }
        }
    }
        
}

int main(){
    // 求解一百内素数表
    int prime[NUM];

    //find_prime(prime);

    eratosthenes(prime);

    return 0;
}