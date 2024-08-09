#include <iostream>
using namespace std;
int Index[1001], MAX, Index_left[1001],Index_right[1001],tmp;
int N;

int Top_Down_left(int k){
    if(Index_left[k] != 0) return Index_left[k];
    int max = 0,tmp_1;
    for(int i = 1;i < k;i++){
        if(Index[i] >= Index[k]) continue;
        tmp_1 = Top_Down_left(i) + 1;
        if(max < tmp_1)max = tmp_1;
    }
    Index_left[k] = max;
    return Index_left[k];
}

int Top_Down_right(int k){
    if(Index_right[k] != 0) return Index_right[k];
    int max = 0,tmp_1;
    for(int i = N; k < i ;i--){
        if(Index[i] >= Index[k]) continue;
        tmp_1 = Top_Down_right(i) + 1;
        if(max < tmp_1)max = tmp_1;
    }
    Index_right[k] = max;
    return Index_right[k];
}

int Top_Down(int k){
    return 1 + Top_Down_left(k)+ Top_Down_right(k);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 1; i < N + 1; i++){
        cin >> Index[i];
    }
    MAX = -1;
    for(int i = 1; i < N + 1; i++){
        tmp = Top_Down(i);
        if (MAX < tmp){
            MAX = tmp;
        }
    }
    cout << MAX << "\n";
    return 0;
}