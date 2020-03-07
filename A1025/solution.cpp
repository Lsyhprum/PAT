# include <iostream>
# include <algorithm>
# include <cstring>

using namespace std;

const int maxn = 30010;

struct testee{
    char id[13];
    int score;
    int fr;
    int location;
    int lr;
}ranks[maxn];   

bool cmp(testee A, testee B){
    if(A.score == B.score) return strcmp(A.id, B.id) < 0;
    else return A.score > B.score;
}

int main(){
    int n, k;
    cin >> n;

    int num = 0;
    for(int i = 1; i <= n ; i ++){
        cin >> k;
        for(int j = 0; j < k; j ++){
            cin >> ranks[num].id;
            cin >> ranks[num].score;
            ranks[num].location = i;

            num ++;
        }
        sort(ranks + num - k, ranks + num, cmp);

        int prior_score = ranks[num - k].score;
        int lr = 1;

        ranks[num - k].lr = lr;
        for(int i = 1; i < k; i ++){
            if(ranks[num - k + i].score == prior_score){
                ranks[num - k + i].lr = lr;
            }else{
                ranks[num - k + i].lr = i + 1;
                prior_score = ranks[num - k + i].score;
                lr = i + 1;
            }
        }
    }

    sort(ranks, ranks + num, cmp);

    ranks[0].fr = 1;
    int prior = ranks[0].score; // 存放前一名总分
    int fr = 1; // 存放前一名排名

    for(int i = 1; i < num; i ++){
        // 总排名
        if(ranks[i].score == prior){
            ranks[i].fr = fr;
        }else{
            ranks[i].fr = i + 1;
            prior = ranks[i].score;
            fr = i + 1;
        }
    }

    cout << num << endl;
    for(int i = 0; i < num; i ++){
        cout << ranks[i].id << " "
             << ranks[i].fr << " "
             << ranks[i].location << " "
             << ranks[i].lr << endl;
    }

    return 0;
}