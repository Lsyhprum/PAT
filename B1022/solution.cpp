# include <iostream>
# include <vector>

using namespace std;

int main(){

    long long a, b, d;
    vector<int> va;
    vector<int> vb;
    vector<int> vc;

    cin >> a >> b >>d;

    do{
        va.push_back(a % d);
        a /= d;
    }while(a);

    do{
        vb.push_back(b % d);
        b /= d;
    }while(b);

    int i = 0;
    int j = 0;
    int tmp = 0, vala, valb;

    while(i < va.size() || j < vb.size()){
        if(i < va.size()){
            vala = va[i];
        }else{
            vala = 0;
        }

        if(j < va.size()){
            valb = vb[j];
        }else{
            valb = 0;
        }

        vc.push_back((vala + valb + tmp) % d);
        tmp = (vala + valb + tmp) / d;
        i ++;
        j ++;
    }

    while(tmp){
        vc.push_back(tmp % d);
        tmp /= d;
    }

    for(int n = vc.size() - 1; n >= 0; n --){
        cout << vc[n];
    }

    return 0;
}