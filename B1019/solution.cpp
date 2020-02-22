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

    // 反思1：错误边界条件
    while(n != 6174){       
        v.clear();
        
        while(n > 0){
            v.push_back(n % 10);
            n /= 10;
        }

        // 反思2：题以固定为4为整数加减，可直接将判断条件写死，无需依据数组长度
        if(v.size() < 4)
            for(int i = 4 - v.size(); i > 0;i --)
                v.push_back(0);

        // 反思3：排除各位相同情况方法复杂，可通过判断相减为 0 判断，并归入边界条件
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
        
        sort(v.begin(), v.end());

        int min = 0;

        for(int i = 0; i < v.size(); i ++)
            min += v[i] * pow(10, 3 - i);

        reverse(v.begin(), v.end());

        int max = 0;
        for(int i = 0; i < v.size(); i ++)
            max += v[i] * pow(10, 3 - i);

        n = max - min;

        // 反思4：printf 格式输出更方便快速
        cout << setw(4) << setfill('0') << max;
        cout << " - ";
        cout << setw(4) << setfill('0') << min; 
        cout << " = ";
        cout << setw(4) << setfill('0')  << max - min << endl;
    }

    return 0;
}