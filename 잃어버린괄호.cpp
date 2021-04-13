#include <iostream>
#include <string>
using namespace std;

int main(){
    int result=0;
    bool minus = false;
    string str , tmp;
    cin >> str;

    for(int i=0; i<=str.size(); i++){
        if(str[i] == '+' || str[i]=='-' || str[i]=='\0'){
            if(minus){
                result-= stoi(tmp);
            }
            else result+= stoi(tmp);

            if(str[i]=='-') minus = true;

            tmp = "";
            continue;
        }

        tmp += str[i];
    }

    cout << result << '\n';
}