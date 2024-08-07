#include <iostream>
#include <vector>
using namespace std;
int N[100];
int N_INDEX, Tem, V, Count = 0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N_INDEX;
    for(int i =0 ; i < N_INDEX ; i++){
        cin >> Tem;
        N[i] = Tem;
    }
    cin >> V;
    for(int i =0 ; i < N_INDEX ; i++){
        if(V == N[i]){
            Count++;
        }
    }
    cout << Count << "\n";
    return 0;
}