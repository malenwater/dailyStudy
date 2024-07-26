#include <iostream>
#include <queue>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,x,max;
    cin >> N;
    priority_queue<int> q;
    while(N--){
        cin >> x;
        if(x != 0){
            q.push(x);
        }else{
            if(q.size() == 0){
                cout << "0\n";
            }
            else{
                max = q.top();
                cout << max << "\n";
                q.pop();
            }
        }
    }
    return 0;
}