//2024/09/11
#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,tmp;
    string str,command, num;
    queue<int> q;
    cin >> N;
    cin.ignore();
    while(N--){
        getline(cin,str);
        command = str.substr(0,str.find(" "));
        if(command.compare("push") == 0){
            tmp = stoi(str.substr(4,str.find("\n")));
            q.push(tmp);
        }else if(command.compare("pop") == 0){
            if(q.size() == 0){
                cout << "-1" << "\n";
            }else{
                tmp = q.front();
                cout << tmp << "\n";
                q.pop();
            }
        }else if(command.compare("size") == 0){
            cout << q.size() << "\n";
        }else if(command.compare("empty") == 0){
            cout << q.empty() << "\n";
        }else if(command.compare("front") == 0){
            if(q.size() == 0){
                cout << "-1" << "\n";
            }else{
                tmp = q.front();
                cout << tmp << "\n";
            }
        }else if(command.compare("back") == 0){
            if(q.size() == 0){
                cout << "-1" << "\n";
            }else{
                tmp = q.back();
                cout << tmp << "\n";
            }
        }
    }
    return 0;
}