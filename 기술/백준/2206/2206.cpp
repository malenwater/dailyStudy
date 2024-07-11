#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
using namespace std;
int main(){
    int N,M;
    string tem1;
    cin >> N >> M;
    vector<vector<int>> adj(N + 1,vector<int>(M + 1));
    vector<vector<int>> dist(N + 1,vector<int>(M + 1,-1));
    queue<vector<int>> q;
    for(int i =1; i <= N ;i++){
        cin >> tem1;
        for(int j = 1; j <= M;j++){
            adj[i][j] = tem1[j - 1] - '0';
        }
    }

    dist[1][1] = 0;
    q.push({1,1});

    while(q.size() != 0){
        vector<int> cur = q.front();
        q.pop();
        // cout << cur[0] << " " << cur[1] << endl;
        if(cur[0] - 1 >= 1 && dist[cur[0] - 1][cur[1]] == -1 && adj[cur[0] - 1][cur[1]] != 1){
            dist[cur[0] - 1][cur[1]] = dist[cur[0]][cur[1]] + 1;
            q.push({cur[0] - 1 ,cur[1]});
        }
        if(cur[0] + 1 <= N && dist[cur[0] + 1][cur[1]] == -1 && adj[cur[0] + 1][cur[1]] != 1){
            dist[cur[0] + 1][cur[1]] = dist[cur[0]][cur[1]] + 1;
            q.push({cur[0] + 1 ,cur[1]});
        }
        if(cur[1] - 1 >= 1 && dist[cur[0]][cur[1] - 1] == -1 && adj[cur[0]][cur[1] - 1] != 1){
            dist[cur[0]][cur[1] - 1] = dist[cur[0]][cur[1]] + 1;
            q.push({cur[0] , cur[1] - 1});         
        }
        if(cur[1] + 1 <= M && dist[cur[0]][cur[1] + 1] == -1 && adj[cur[0]][cur[1] + 1] != 1){
            dist[cur[0]][cur[1] + 1] = dist[cur[0]][cur[1]] + 1;
            q.push({cur[0], cur[1] + 1});
        }
    }

    // for(int i =1; i < N + 1;i++){
    //     for(int j = 1; j < M + 1;j++){
    //         cout << dist[i][j];
    //     }
    //     cout << endl;
    // }

    vector<int> MAX_INDEX;
    int max = -1;
    for(int i =1; i <= N ;i++){
        for(int j = 1; j <= M;j++){
            if(adj[i][j] == 1){
                if(abs(dist[i - 1][j] - dist[i + 1][j]) > max && adj[i - 1][j] != 1 && adj[i + 1][j] != 1 && i -1 >= 1 && i + 1 <= M){
                    MAX_INDEX = {i,j};
                    max = abs(dist[i - 1][j] - dist[i + 1][j]);
                }
                // if(abs(dist[i + 1][j] - dist[i - 1][j]) > max && adj[i + 1][j] != 1 && adj[i - 1][j] != 1 && i -1 >= 1 && i + 1 <= M){
                //     MAX_INDEX = {i,j};
                // }
                if(abs(dist[i][j - 1] - dist[i][j + 1]) > max && adj[i][j - 1] != 1 && adj[i][j + 1] != 1 && j -1 >= 1 && j + 1 <= N){
                    MAX_INDEX = {i,j};
                    max = abs(dist[i - 1][j] - dist[i + 1][j]);
                }
                // if(abs(dist[i][j + 1] - dist[i][j - 1]) > max && adj[i][j + 1] != 1 && adj[i][j - 1] != 1 && j -1 >= 1 && j + 1 <= N){
                //     MAX_INDEX = {i,j};
                // }
            }
        }
    }
    if(max != -1){
        adj[MAX_INDEX[0]][MAX_INDEX[1]] = 0;
        for(int i = 0; i <= N; ++i) {
            fill(dist[i].begin(), dist[i].end(), -1);
        }
        dist[1][1] = 1;
        q.push({1,1});

        while(q.size() != 0){
            vector<int> cur = q.front();
            q.pop();
            // cout << cur[0] << " " << cur[1] << endl;
            if(cur[0] - 1 >= 1 && dist[cur[0] - 1][cur[1]] == -1 && adj[cur[0] - 1][cur[1]] != 1){
                dist[cur[0] - 1][cur[1]] = dist[cur[0]][cur[1]] + 1;
                q.push({cur[0] - 1 ,cur[1]});
            }
            if(cur[0] + 1 <= N && dist[cur[0] + 1][cur[1]] == -1 && adj[cur[0] + 1][cur[1]] != 1){
                dist[cur[0] + 1][cur[1]] = dist[cur[0]][cur[1]] + 1;
                q.push({cur[0] + 1 ,cur[1]});
            }
            if(cur[1] - 1 >= 1 && dist[cur[0]][cur[1] - 1] == -1 && adj[cur[0]][cur[1] - 1] != 1){
                dist[cur[0]][cur[1] - 1] = dist[cur[0]][cur[1]] + 1;
                q.push({cur[0] , cur[1] - 1});         
            }
            if(cur[1] + 1 <= M && dist[cur[0]][cur[1] + 1] == -1 && adj[cur[0]][cur[1] + 1] != 1){
                dist[cur[0]][cur[1] + 1] = dist[cur[0]][cur[1]] + 1;
                q.push({cur[0], cur[1] + 1});
            }
        }
    }

    cout << dist[N][M] << endl;

    // cout << max << endl;
    // for(int i =1; i < N + 1;i++){
    //     for(int j = 1; j < M + 1;j++){
    //         cout << dist[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}