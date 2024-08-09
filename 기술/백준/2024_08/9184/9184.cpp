#include <iostream>
using namespace std;
int Index[101][101][101];
int w(int a, int b, int c){
    int alpa = a + 50;
    int beta = b + 50;
    int ceta = c + 50;
    if(Index[alpa][beta][ceta] != -1){
        return Index[alpa][beta][ceta];
    }

    if(a <= 0 || b <= 0 || c <=0){
        Index[alpa][beta][ceta] = 1;
    }
    else if(a > 20 || b > 20 || c > 20){
        Index[alpa][beta][ceta] = w(20,20,20);
    }
    else if(a < b && b < c){
        Index[alpa][beta][ceta] = w(a,b,c-1) + w(a,b-1,c-1) - w(a,b-1,c);
    }else{
        Index[alpa][beta][ceta] = w(a-1,b,c) + w(a-1,b-1,c) + w(a-1,b,c-1) - w(a-1,b-1,c-1);
    }
    return Index[alpa][beta][ceta];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a = 0,b = 0,c = 0, result = 0;
    fill(&Index[0][0][0],&Index[100][100][101],-1);
    while(true){
        cin >> a >> b >> c;
        if(a == -1 && b == -1 && c == -1)
            break;
        result = w(a,b,c);
        cout << "w(" << a << ", " << b << ", " << c << ") = " << result << "\n";
    }
    return 0;
}