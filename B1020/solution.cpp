# include <iostream>

using namespace std;

int main(){
    int n;
    double d;
    cin >> n >> d;

    double cap[n];
    double val[n];
    double tmp[n];        // 平均价格

    for(int i = 0; i < n; i ++)
        cin >> cap[i];

    for(int i = 0; i < n; i ++){
        cin >> val[i];
        tmp[i] = val[i] / cap[i];
    }

    double ans = 0;
    bool flag[n] = {};  // true 访问过
    while(d){
        double max = tmp[0];
        int pos = 0;
        for(int i = 1; i < n; i ++){
            if(max < tmp[i] && !flag[i]){
                max = tmp[i];
                pos = i;
            }
        }
        flag[pos] = true;

        if(d >= cap[pos]){
            d -= cap[pos];
            ans += val[pos];
        }else{
            ans += (d * tmp[pos]);
            d = 0;
        }
    }

    printf("%.2f", ans);

    return 0;
}