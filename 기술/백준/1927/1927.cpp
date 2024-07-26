#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,x,min = 0;
    priority_queue<int,vector<int>,greater<int>> q;
    cin >> N;
    while(N--){
        cin >> x;
        if(x == 0){
            if(q.size() == 0){
                cout << "0\n";
            }else{
                min = q.top();
                cout << min << "\n";
                q.pop();
            }
        }else{
            q.push(x);
        }
    }
    return 0;
}