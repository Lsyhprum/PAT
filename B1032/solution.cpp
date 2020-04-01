# include <iostream>
# include <unordered_map>

using namespace std;

int main(){
    int n;
    cin >> n;

    int a, b;
    unordered_map<int, int> mp;
    int max_index = -1, max_val = -1;
    while(n --){
        cin >> a >> b;
        mp[a] += b;
        if(mp[a] > max_val){
            max_index = a;
            max_val = mp[a];
        }
    }

    cout << max_index << " " << max_val;
    return 0;
}