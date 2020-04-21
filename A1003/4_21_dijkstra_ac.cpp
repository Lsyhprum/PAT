# include <iostream>

using namespace std;

const int MAXN = 510;
const int INF = 1000000000;

int N, M, C1, C2;  // N city num   M roads num   C1 start  C2 end
bool visit[MAXN] = {false};
int teams[MAXN];    
int people[MAXN];           // max num of rescur teams
int nums[MAXN] = {0};     // num of different path
int G[MAXN][MAXN]; 

void Dijkstra(){
    int d[MAXN];
    fill(d, d + MAXN, INF);
    d[C1] = 0;
    nums[C1] = 1;

    for(int i = 0; i < N; i ++){
        int u = -1, MIN = INF;
        for(int j = 0; j < N; j ++){
            if(!visit[j] && MIN > d[j]){
                u = j;
                MIN = d[j];
            }
        }

        if(u == -1) return;
        visit[u] = true;
        //cout << "u : " << u << endl;

        for(int v = 0; v < N; v ++){
            if(!visit[v] && G[u][v] != INF){
                if(d[u] + G[u][v] < d[v]){
                    d[v] = d[u] + G[u][v];
                    nums[v] = nums[u];
                    people[v] = people[u] + teams[v];
                }else if(d[u] + G[u][v] == d[v]){
                    if(people[v] < people[u] + teams[v]){
                        people[v] = people[u] + teams[v];
                    }
                    nums[v] += nums[u];
                }

                // cout << "v : " << v << endl;
                // cout << "nums[v] : " << nums[v] << endl;
                // cout << "teams[v] : " << teams[v] << endl;
            }
        }
    }
}

int main(){
    for(int i = 0; i < MAXN; i ++){
        for(int j = 0; j < MAXN; j ++){
            G[i][j] = INF;
        }
    }


    cin >> N >> M >> C1 >> C2;
    
    for(int i = 0; i < N; i ++){
        cin >> teams[i];
        people[i] = teams[i];
    }
       
    
    int a, b, c;
    for(int i = 0; i < M; i ++){
        cin >> a >> b >> c;

        // 无向边
        G[a][b] = c;
        G[b][a] = c;
    }

    Dijkstra();

    cout << nums[C2] << " " << people[C2] << endl;

    return 0;
}