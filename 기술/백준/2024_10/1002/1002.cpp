// 2024/10/16
#include <iostream>
#include <cmath>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T,x1,y1,r1,x2,y2,r2;
    cin >> T;
    while (T){
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        double d = sqrt(pow(x2-x1,2) + pow(y2-y1,2));
        if(d == 0 && r1 == r2){
            cout << "-1\n";
        }
        else if (d == r1+r2){
            cout << "1\n";
        }
        else if (d > r1+r2){
            cout << "0\n";
        }
        else if (d == abs(r1-r2)){
            cout << "1\n";
        }
        else if (d < abs(r1-r2)){
            cout << "0\n";
        }

        else{
            cout << "2\n";
        }
        T--;
    }
    return 0;
}