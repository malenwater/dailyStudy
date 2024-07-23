#include <iostream>
#include <cmath>
using namespace std;

void kan(double N){
    if(N == 0){
        cout << "-";
        return;
    }
    kan(N - 1);
    int k = pow(3,N-1);
    for(int i =0;i<k;i++){
        cout << " ";
    }
    kan(N - 1);
}

int main(){
    double N;
    while(!(cin >> N).eof()){
        kan(N);
        cout << endl;
    }
    return 0;
}