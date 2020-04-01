# include <iostream>

using namespace std;

const int maxn = 100010;

struct Node{
    char c;
    int next;
    bool flag;
}node[maxn];

int main(){
    for(int i = 0; i < maxn; i ++){
        node[i].flag = false;
    }

    int head_a, head_b, n;
    cin >> head_a >> head_b >> n;

    int a, b;
    char c;
    while(n --){
        cin >> a >> c >> b;

        node[a].c = c;
        node[a].next = b; 
    }

    int p;
    for(p = head_a; p != -1; p = node[p].next){
        node[p].flag = true;
    }

    for(p = head_b; p != -1; p = node[p].next){
        if(node[p].flag == true) break;
    }

    if(p != -1){
        printf("%05d\n", p);
    }else{
        printf("-1\n");
    }

    return 0;
}