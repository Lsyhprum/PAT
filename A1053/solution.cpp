# include <iostream>
# include <algorithm>
# include <stack>
# include <vector>

using namespace std;

const int maxn = 110;
int n, m, s;
int path[maxn] = {};

struct node{
    int data;
    vector<int> child;
}Node[maxn];

bool cmp(int a, int b){
    return Node[a].data > Node[b].data;
}

// 当前访问节点 index, 当前层数 numNode, 路径和 sum
void dfs(int index, int numNode, int sum){
    if(sum > s) return;
    if(sum == s){
        if(Node[index].child.size() != 0) return;

        for(int i = 0; i < numNode; i ++){
            cout << path[i];
            if(i < numNode-1){
                cout << " ";
            }else{
                cout << "\n";
            }
        }
        return;
    }

    for(int i = 0; i < Node[index].child.size(); i ++){
        int d = Node[Node[index].child[i]].data;
        path[numNode] = d;
        dfs(Node[index].child[i], numNode + 1, sum + d);
    }
}

int main(){

    cin >> n >> m >> s;

    for(int i = 0; i < n; i ++)
        cin >> Node[i].data;
    
    int id, num, tmp;
    for(int i = 0; i < m; i ++){
        cin >> id >> num;
        for(int j = 0; j < num; j ++){
            cin >> tmp;
            Node[id].child.push_back(tmp);
        }
        sort(Node[id].child.begin(), Node[id].child.end(), cmp);  // 可能出现同值父节点但子节点大小不同？
    }

    path[0] = Node[0].data;
    dfs(0, 1, Node[0].data);

    return 0;
}