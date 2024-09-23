// 2024/09/20
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector <long long> v;
const long long int MOD = 1000000007;
 long long int mod_reverse(long long int N){
    long long result = 1;
    long long exp = MOD - 2; 
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * N) % MOD;
        }
        N = (N * N) % MOD;
        exp /= 2;
    }
    return result;
}
void factor(long long N){
    v.resize(N + 1);
    v[0] = 1;
    for(long long i=1;i<=N;i++){
        v[i] = (v[i-1] * i) % MOD;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long N,K;
    cin >> N >> K;
    factor(N);
    long long result = (v[N] * mod_reverse(v[K]) % MOD * mod_reverse(v[N - K]) % MOD) % MOD;
    cout << result << "\n";
    return 0;
}