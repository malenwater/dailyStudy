// 2024/10/04
#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M,i,j,k;
    int basket[101] = {0,};
    cin >> N >> M;
    for(int index = 0; index < M;index++){
        cin >> i >> j >> k;
        for(int index2 = i;index2 <= j;index2++){
            basket[index2] = k;
        }
    }
    for(int index = 1; index <= N;index++){
        if(index == N){
            cout << basket[index] << "\n";
        }
        else{
            cout << basket[index] << " ";
        }
    }
    return 0;
}