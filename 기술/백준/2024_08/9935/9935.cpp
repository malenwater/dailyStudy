#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;
string N, Boom;
stack<char> Stack;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    cin >> Boom;
    int N_Size = N.size();
    int Boom_Size = Boom.size();

    for(int i =0; i < N_Size;i++){
        Stack.push(N[i]);

        if(N[i] == Boom[Boom_Size - 1] && Stack.size() >= Boom_Size){
            bool match = true;
            string temp = "";

            for(int j = 0; j < Boom_Size;j++){
                temp += Stack.top();
                Stack.pop();
            }

            for(int j =0; j < Boom_Size;j++){
                if (temp[Boom_Size - 1 - j] != Boom[j]) {
                    match = false;
                    break;
                }
            }

            if (!match) {
                for (int j = Boom_Size - 1; j >= 0; j--) {
                    Stack.push(temp[j]);
                }
            }

        }
    }

    if (Stack.empty()) {
        cout << "FRULA\n";
    } else {
        string result = "";
        while (!Stack.empty()) {
            result += Stack.top();
            Stack.pop();
        }
        reverse(result.begin(), result.end());
        cout << result << '\n';
    }
    
    return 0;
}