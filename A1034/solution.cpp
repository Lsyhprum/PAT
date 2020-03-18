# include <iostream>
# include <algorithm>
# include <vector>
# include <map>
# include <string>

using namespace std;

// 如何将string 转化为 对应 int

const int maxn = 1010;
map<string, int> m;          // 名字与id的对应
map<int, string> m2;        // id 与名字的对应
int person[maxn][maxn] = {};    // 电话表
bool flag[maxn] = {false};
int N = 0;

bool cmp(pair<string,int> a, pair<string,int> b){
    return a.first < b.first;
}

void dfs(int node, int &gang_num, int max_num, string &head, int &total_weight){
    flag[node] = true;

    int sum = 0;
    for(int i = 0; i < N; i ++){
        sum += person[node][i];
    }

    total_weight += sum;

    if(max_num < sum){     // 成员影响力
        max_num = sum;
        head =  m2.find(node)->second;
    }

    for(int i = 0; i < N; i ++){
        if(!flag[i] && person[node][i]){
            gang_num += 1;
            dfs(i, gang_num, max_num, head, total_weight);
        }
    }
}

int main(){
    int n, k;
    cin >> n >> k;

    string name1, name2;
    int time;
    while(n --){
        cin >> name1 >> name2 >> time;
        
        if(m.find(name1) == m.end()){
            m.insert(pair<string, int>(name1, N));
            m2.insert(pair<int, string>(N ++, name1));
        }
        if(m.find(name2) == m.end()){
            m.insert(pair<string, int>(name2, N));
            m2.insert(pair<int, string>(N ++, name2));
        }

        person[m.find(name1)->second][m.find(name2)->second] += time; 
        person[m.find(name2)->second][m.find(name1)->second] += time; 
    }

    vector<pair<string, int>> heads;
    for(int i = 0; i < N; i ++){
        if(!flag[i]){
            int gang_num = 1;
            string head;
            int total_weight = 0;
            dfs(i, gang_num, 0, head, total_weight);

           
            if(gang_num > 2 && total_weight > k * 2){
                 cout << gang_num << head << total_weight << endl;
                heads.push_back(pair<string, int>(head, gang_num));
            }
        }
    }

    sort(heads.begin(), heads.end(), cmp);

    cout << heads.size() << endl;
    for(int i = 0; i < heads.size(); i ++){
        cout << heads[i].first << " " << heads[i].second;
        if(i < heads.size() - 1){
            cout << "\n";
        }
    }

    return 0;
}