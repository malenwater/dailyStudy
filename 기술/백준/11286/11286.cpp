#include <iostream>
#include <queue>
#include <utility>

using namespace std;
int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,x,MIN;
    pair<int,int> min;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    cin >> N;
    while(N--){
        cin >> x;
        if(x < 0){
            q.push(make_pair(x * (-1), 0));
        }else if(x > 0){
            q.push(make_pair(x, 1));
        }else{
            if(q.size() == 0){
                cout << "0\n";
            }else{
                min = q.top();
                MIN = min.first;
                if(min.second == 0){
                    MIN *= -1;
                }
                cout << MIN <<"\n";
                q.pop();
            }
        }
    }
    return 0;
}