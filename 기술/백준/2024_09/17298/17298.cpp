#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N,arr[1000000][2], tmp,size; // arr[1000000][2],
    stack<pair<int,int>> Stack;
    pair<int,int> p,p_before;
    cin >> N;
    for(int i = 0; i < N;i++){
        cin >> arr[i][0];
    }

    for(int i = 0; i < N;i++){
        tmp = arr[i][0];
        p = make_pair(i,tmp);
        if(Stack.empty()){
            Stack.push(p);
        }
        else{
            p_before = Stack.top();
            if(p.second > p_before.second){
                size = Stack.size();
                for(int j = 0;j < size;j++){
                    p_before = Stack.top();
                    if(p.second <= p_before.second){
                        break;
                    }
                    arr[p_before.first][1] = p.second;
                    Stack.pop();
                }
            }
            Stack.push(p);
        }
    }

    size = Stack.size();
    for(int i = 0;i < size; i++){
        p_before = Stack.top();
        arr[p_before.first][1] = -1;
        Stack.pop();
    }

    for(int i =0; i < N;i++){
        if(i != N-1){
            cout << arr[i][1] << " ";
        }else{
            cout << arr[i][1] << "\n";
        }
    }

    return 0;
}