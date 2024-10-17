// 2024/10/17
#include <iostream>
#include <algorithm>
using namespace std;
int zero[50],one[50],dy_data[50];
int fibonacci(int n) {
    if (n == 0) {
        zero[n] = 1;
        one[n] = 0;
        dy_data[n] = 0;
        return 0;  // 0일 경우 0을 반환
    } else if (n == 1) {
        zero[n] = 0;
        one[n] = 1;
        dy_data[n] = 1;
        return 1;  // 1일 경우 1을 반환
    }else if (dy_data[n] != -1){
        zero[n] = zero[n-1] + zero[n-2];
        one[n] = one[n-1] + one[n-2];
        return dy_data[n];
    } else {
        dy_data[n] = fibonacci(n - 1) + fibonacci(n - 2);
        return dy_data[n];  // 재귀 호출
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T,N;
    cin >> T;
    fill(zero, zero + 50, -1);
    fill(one, one + 50, -1);
    fill(dy_data, dy_data + 50, -1);
    fibonacci(42);

    while (T--){
        cin >> N;
        cout << zero[N] << " " << one[N] << "\n";
    }
    return 0;
}