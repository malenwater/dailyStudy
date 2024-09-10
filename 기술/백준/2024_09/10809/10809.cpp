// 2024/09/10
#include <iostream>
#include <string>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int alphet[26],size = 0;
    fill(alphet,alphet + 26, -1);
    string str;
    char alphet_arr[26] = {'a','b','c','d','e','f','g',
                           'h','i','j','k','l','m','n',
                           'o','p','q','r','s','t','u',
                           'v','w','x','y','z'};
    cin >> str;
    size = str.size();
    for(int i = 0; i < size;i++){
        for(int j = 0 ; j < 26 ; j++){
            if(alphet_arr[j] == str[i] && alphet[j] == -1){
                alphet[j] = i;
            }
        }
    }
    for(int i = 0; i < 26;i++){
        cout << alphet[i] << " ";
    }
    cout << "\n";
    return 0;
}