# include <iostream>

using namespace std;

string week[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main(){
    string w;
    int h, m;

    string s1, s2;

    cin >> s1 >> s2;
    int flag = 0;
    for(int i = 0; i < (s1.length() < s2.length() ? s1.length() : s2.length()); i ++){
        if(s1[i] == s2[i]){
            if(flag == 1 && ((s1[i] >= '0' && s1[i] <= '9') || (s1[i] >= 'A' && s1[i] <= 'N'))){
                if(isdigit(s1[i])){
                    h = s1[i] - '0';
                }else{
                    h = s1[i] - 'A' + 10;
                }
                break;
            }
            if(flag == 0 && s1[i] >= 'A' && s1[i] <= 'G'){
                w = week[s1[i] - 'A'];
                flag ++;
            }
        }
    }

    cin >> s1 >> s2;
    for(int i = 0; i < (s1.length() < s2.length() ? s1.length() : s2.length()); i ++){
        if(s1[i] == s2[i] && isalpha(s1[i])){
            m = i;
            break;
        }
    }

    printf("%s %02d:%02d", w.c_str(), h, m);

    return 0;
}