#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, k;
    cin >> N;
    k = N / 4;
    while(k--){
        cout << "long ";
        if(k == 0){
            cout << "int\n";
        }
    }
    return 0;
}