# include <iostream>

using namespace std;

int main(){
    int a;
    char c;

    cin >> a >> c;
    int col = a % 2 == 0 ?  (a / 2) : ((a+1) / 2);
    for(int i = 0; i < col; i ++){
        if(i == 0 || i == col - 1){
            for(int j = 0; j < a; j ++){
                cout << c;
            }
        }else{
            for(int j = 0; j < a; j ++){
                if(j == 0 || j == a - 1){
                    cout << c;
                }else{
                    cout << " ";
                }
            }
        }
        cout << endl;
    }
    return 0;
}