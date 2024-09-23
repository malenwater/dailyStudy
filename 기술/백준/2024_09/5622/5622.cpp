// 2024/09/23
#include <iostream>
#include <string>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    int sum = 0;
    cin >> str;
    for(int i = 0; i < str.size();i++){
        if(0 <= (str[i]-'A') && (str[i]-'A') < 3){
            sum += 3;
        }
        else if(3 <= (str[i]-'A') && (str[i]-'A') < 6){
            sum += 4;
        }
        else if(6 <= (str[i]-'A') && (str[i]-'A') < 9){
            sum += 5;
        }
        else if(9 <= (str[i]-'A') && (str[i]-'A') < 12){
            sum += 6;
        }
        else if(12 <= (str[i]-'A') && (str[i]-'A') < 15){
            sum += 7;
        }
        else if(15 <= (str[i]-'A') && (str[i]-'A') < 19){
            sum += 8;
        }
        else if(19 <= (str[i]-'A') && (str[i]-'A') < 22){
            sum += 9;
        }
        else if(21 <= (str[i]-'A') && (str[i]-'A') < 26){
            sum += 10;
        }
    }
    cout << sum << "\n";
    return 0;
}