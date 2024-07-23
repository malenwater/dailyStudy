#include <iostream>
using namespace std;

int N_index[20];

unsigned long long factory(unsigned long long  N){
    if (N == 0)
        return 1;
    return N * factory(N-1);
}

int main(){
    unsigned long long  N;
    cin >> N;
    cout << factory(N) << endl;
    return 0;
}