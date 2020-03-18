# 数据结构专题

### 栈的应用

1. 在使用 pop() 和 top() 之前必须先使用 empty() 判空


### 树

1. 树的定义：满足连通、边数等于顶点数减 1 的结构一定是一棵树。

2. 二叉树与度为 2 的树区别； 树不分左右顺序，二叉树左右严格区分

3. 二叉树存储结构与基本操作

```cpp
//二叉树定义
struct node{
    typename data;
    node* left;
    node* right;
};

// 根节点
node* root = NULL;

// 新建节点
node* newNode(int v){
    node* Node = new node;
    Node->data = v;
    Node->left = Node->right = NULL;
    return Node;
}

// 二叉树插入
void insert(node* &root, int x){
    if(root == NULL){
        root = newNode(x);
        return;
    }
    if(插在左子树){
        insert(root->left, x);
    }else{
        insert(root->right, x);
    }
}
```

**值得注意的是，实现插入过程中 root 使用了引用 &**


### 并查集

并查集是一种维护集合的数据结构，名字分别取自 Union, Find, Set。 并查集产生的每一个集合都是一颗树。

```cpp
// 初始化
for(int i = 1; i <= N; i ++>){
    father[i] = i;
}

// 查找根结点
int find(int x){
    int a = x;
    while(x != father[x]){    // 寻找根结点
        x = father[x];
    }

    while(a != father[a]){
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}

// 合并
void Union(int a, int b){
    int faA = findFather(a);
    int faB = findFather(b);

    if(faA != faB){
        father[faA] = faB;
    }
}
```

### 图

