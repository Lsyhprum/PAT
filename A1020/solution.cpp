# include <iostream>
# include <stack>
# include <queue>

using namespace std;

struct node{
   int data;
   node *left;
   node *right; 
};

const int maxn = 31;
stack<int> post;
int mid[maxn];

node* newNode(int data){
    node* n = new node;
    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n;
}

void recursion(node* &parent, int first, int last){
    if(first > last)
        return;

    int data = post.top();
    post.pop();
    
    parent = newNode(data);

    int mid_post = 0;
    for(int i = last; i >= first; i --){
        if(mid[i] == data){
            mid_post = i;
            break;
        }
    }

    recursion(parent->right, mid_post + 1, last);   

    recursion(parent->left, first, mid_post - 1);
}

void level_order(node *root){
    queue<node *> s;
    bool flag = false;
    if(root)
        s.push(root);

    while(!s.empty()){
        node *tmp = s.front();
        s.pop();

        if(!flag){
            flag = true;
        }else{
            cout << " ";
        }

        cout << tmp->data;

        if(tmp->left)
            s.push(tmp->left);
        if(tmp->right)
            s.push(tmp->right);
    }
    cout << "\n";
}

int main(){
    node* root = NULL;

    int n, t;

    cin >> n;
    for(int i = 1; i <= n; i ++){
        cin >> t;
        post.push(t);
    }

    for(int i = 1; i <= n; i ++){
        cin >> t;
        mid[i] = t;
    }

    recursion(root, 1, n);
    level_order(root);

    return 0;
}