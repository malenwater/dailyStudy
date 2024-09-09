 #include <iostream>
using namespace std;
int ARR[9];
bool fill_ARR(){
    for(int i = 0; i < 9;i++){
        cin >> ARR[i];
    }
    return true;
}
int find_MAX(){
    int MAX = -1, NUM = 0;
    for(int i = 0; i < 9;i++){
        if(MAX < ARR[i]){
            MAX = ARR[i];
            NUM = i;
        }
    }
    cout << MAX << "\n";
    return NUM + 1;
}
 int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    fill_ARR();
    cout << find_MAX() << "\n";
    return 0;
 }