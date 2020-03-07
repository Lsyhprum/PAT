# include <iostream>
# include <sstream>
# include <cstring>
# include <stack>
# include <queue>

using namespace std;

int main(){
    string s;
    stack<string> val;
    stack<string> op;
    queue<string> post;
    while(getline(cin, s), s != "0"){
        istringstream is(s);
        string w;
        while(is >> w){
            if(w[0] <= '0' && w[0] >= '9'){
                val.push(w);
            }else{
                if(op.empty()){
                    op.push(w);
                }else{
                    if(w == "*" || w == "/"){
                        if(op.top() == "*" || op.top() == "/"){
                            op.push(w);
                        }else{
                            while(!op.empty()){
                                post.push(op.top());
                                op.pop();
                            }
                        }
                    }else{
                        while(op.top() != "*" && op.top() != "/"){
                            post.push(op.top());
                            op.pop();
                        }
                    }
                }
            }
        }
        while(!op.empty()){
            post.push(op.top());
            op.pop();
        }

        while(!post.empty()){
            cout << post.front() << endl;
            post.pop();
        }
    }

    return 0;
}