# include <iostream>
# define NUM 1000001

using namespace std;

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    int prime[m + 1];
    bool P[NUM] = {0};

    int num = 1;
    for(int i = 2; i < NUM; i ++){
        if(!P[i]){
            prime[num ++] = i;
            for(int j = i + i; j < NUM; j += i){
                P[j] = true;
            }
        }

        if(num == m + 1){
            int line = 0;
            for(int k = n; k <= m; k ++){
                if(line == 9 || k == m){
                    cout << prime[k] << endl;
                    line = 0;
                }else{
                    cout << prime[k] << " ";
                    line ++;
                }
            }
            return 0;
        }
    }

    return 0;
}