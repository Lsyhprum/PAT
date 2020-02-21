# include <iostream>
# include <vector>
# include <algorithm>
# include <math.h>
# include <iomanip>

using namespace std;


int main(){
    int n;
    cin >> n;
    int origin = n;

    vector<int> v;

    while(n != 6174){         // 错误边界条件
        v.clear();
        
        while(n > 0){
            v.push_back(n % 10);
            n /= 10;
        }

        // 小于4位补0
        if(v.size() < 4)
            for(int i = 4 - v.size(); i > 0;i --)
                v.push_back(0);

        // 排除各位相同情况
        int times = 0;
        int num = v[0];
        for(int i = 1; i < v.size(); i ++){
            if(v[i] == num){
                times ++;
                if(times == 3){
                    cout << setw(4) << setfill('0') << origin << " - " << setw(4) << setfill('0') << origin << " = 0000" << endl;
                    return 0;
                }
            }else{
                break;
            }
        }
        
        //4 位不完全相同
        sort(v.begin(), v.end());

        int min = 0;

        for(int i = 0; i < v.size(); i ++)
            min += v[i] * pow(10, 3 - i);

        reverse(v.begin(), v.end());

        int max = 0;
        for(int i = 0; i < v.size(); i ++)
            max += v[i] * pow(10, 3 - i);

        n = max - min;
        cout << setw(4) << setfill('0') << max;
        cout << " - ";
        cout << setw(4) << setfill('0') << min; 
        cout << " = ";
        cout << setw(4) << setfill('0')  << max - min << endl;
    }

    return 0;
}