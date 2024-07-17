#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int A[1000000][2];
#define arr 0
#define lis 1

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, mid, A_i, min, max;
    int length = 1;
    cin >> N;
    for(int i =0; i < N;i++){
        cin >> A[i][arr];
    }

    A[0][lis] = A[0][arr];

    for(int i = 1; i < N;i++){
        A_i = A[i][arr];
        if(A_i > A[length - 1][lis]){
            A[length][lis] = A_i;
            length++;
        }else{
            min = 0;
            max = length - 1;
            while(min < max){
                mid = min + (max - min) / 2;
                if(A_i <= A[mid][lis]){
                    max = mid;
                }
                else{
                    min = mid + 1;
                }
            }
            A[min][lis] = A_i;
        }
    }
    cout << length << endl;
    return 0;
}