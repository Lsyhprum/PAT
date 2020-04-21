# include <iostream>

using namespace std;

const int MAXN = 510;
const int INF = 1000000000;

int N, M, S, D;
int dis[MAXN][MAXN];
int cost[MAXN][MAXN];
bool visit[MAXN] = {false};

int d[MAXN];
int path[MAXN];
int w[MAXN];

void Dijkstra(){

    for(int i = 0; i < N; i ++){
        int u = -1, MIN = INF;
        for(int j = 0; j < N; j ++){
            if(visit[j] == false && d[j] < MIN){
                u = j;
                MIN = d[j];
            }
        }

        if(u == -1) return ;
        visit[u] = true;
        //cout << "u:" << u << endl;

        for(int v = 0; v < N; v ++){
            if(visit[v] == false && dis[u][v] != INF){
                if(dis[u][v] + d[u] < d[v] || (dis[u][v] + d[u] == d[v] && w[v] > cost[u][v] + w[u])){
                    d[v] = dis[u][v] + d[u];
                    path[v] = u;
                    w[v] = cost[u][v] + w[u];
                    // cout << "v:" << v << endl;
                    // cout << "d[v]:" << d[v] << endl;
                    // cout << "w[v]:" << w[v] << endl;
                }
            }
        }
    }

}

void DFS(int s, int d){
    if(d == s){
        cout << s;
        return;
    } 

    DFS(s, path[d]);
    cout << " " << d;
}

int main(){
    fill(dis[0], dis[0] + MAXN * MAXN, INF);
    fill(cost[0], cost[0] + MAXN * MAXN, INF);
    

    cin >> N >> M >> S >> D;

    for(int i = 0; i < N; i ++){
        path[i] = i;
    }

    fill(d, d + MAXN, INF);
    d[S] = 0;
    fill(w, w + MAXN, INF);
    w[S] = 0;

    int a, b, c, e;
    for(int i = 0; i < M; i ++){
        cin >> a >> b >> c >> e;
        dis[a][b] = c; dis[b][a] = c;
        cost[a][b] = e; cost[b][a] = e;
    }

    Dijkstra();

    DFS(S, D);

    cout << " " << d[D] << " " << w[D];


    return 0;
}