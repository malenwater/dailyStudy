#include <iostream>
#include <stack>
#include <string>
using namespace std;
string N, Boom;
stack<int> Stack;
int Top = 0, Size = 0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    cin >> N;
    cin >> Boom;
    Size = N.size();
    N += "aaa";
    cout << N;
    // for(int i = Size - 1 ; 0 < i + 1 ; i--){
    //     Stack.push(N[i]);
    // }
    return 0;
}