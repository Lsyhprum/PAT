# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

struct Mooncake{                      // 结构体使用
    double cap;
    double val;
    double ave;
}M[1010];                             // 最大数组要 + 10

bool cmp(Mooncake a, Mooncake b){
    return a.ave > b.ave;
}

int main(){
    int n;
    double d, ans = 0;
    cin >> n >> d;

    for(int i = 0; i < n; i ++)
        cin >> M[i].cap;
    for(int i = 0; i < n; i ++){
        cin >> M[i].val;
        M[i].ave = M[i].val / M[i].cap;
    }

    sort(M, M + n, cmp);               // sort 使用 指针， 遍历使用 iterator

    int cnt = 0;
    while(d && cnt < n){               // 可能所有库存也无法满足需求 段错误
        if(d >= M[cnt].cap){
            ans += M[cnt].val;
            d -= M[cnt].cap;
        }else{
            ans += (M[cnt].ave * d);
            d = 0;
        }
        cnt ++;
    }

    printf("%.2f", ans);

    return 0;
}