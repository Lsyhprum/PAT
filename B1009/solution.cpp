# include <iostream>
# include <vector>
# include <string>
# include <sstream>

using namespace std;

int main(){
    vector<string> words;

    string s, word;
    getline(cin, s);

    istringstream is(s);
    while(is >> word){
        words.push_back(word);
    }

    for(int i = words.size() - 1; i >= 0; i --){
        if(i != words.size() - 1){
            cout << " ";
        }
        cout << words[i];
    }
    return 0;
}