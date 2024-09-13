#include <iostream>
#include <stack>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,tmp,N2,data,number,data_pick;
    stack<int> arr_forward, arr_reverse;
    cin >> N;
    for(int i = 0; i < N;i++){
        cin >> tmp;
        arr_forward.push(tmp);
    }
    for(int i = 0; i < N;i++){
        tmp = arr_forward.top();
        arr_forward.pop();
        arr_reverse.push(tmp);
    }

    for(int i = 0; i < N;i++){
        data = arr_reverse.top();
        arr_reverse.pop();
        number = 0;
        data_pick = -1;

        for(int j = 0; j < N - i - 1;j++){
            tmp = arr_reverse.top();
            arr_reverse.pop();
            arr_forward.push(tmp);
            number++;
            if(data < tmp){
                data_pick = tmp;
                break;
            }
        }

        for(int j = 0; j < number; j++){
            tmp = arr_forward.top();
            arr_forward.pop();
            arr_reverse.push(tmp);
        }
        arr_forward.push(data_pick);
    }

    for(int i = 0; i < N;i++){
        tmp = arr_forward.top();
        arr_forward.pop();
        arr_reverse.push(tmp);
    }

    for(int i = 0; i < N;i++){
        tmp = arr_reverse.top();
        arr_reverse.pop();
        if(i == N-1){
            cout << tmp;
        }else{
            cout << tmp << " ";
        }
    }
    cout << "\n";
    return 0;
}