#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, X, tmp, tmp_num = 0;
    int Arr[10000];
    cin >> N >> X;
    for(int i = 0; i < N; i++){
        cin >> tmp;
        if(tmp < X){
            Arr[tmp_num] = tmp;
            tmp_num++;
        }
    }
    for(int i = 0; i < tmp_num;i++){
        cout << Arr[i];
        if(i != tmp_num - 1){
            cout << " ";
        }
        else{
            cout << "\n";
        }
    }
    return 0;
}