#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<pair<int,int>>> EDGE;
int MIN[20001];
int visited[20001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int V,E,K, u,v,w, current,current_dist, tmp_v,tmp_w, tmp_e;
    cin >> V >> E >> K;
    EDGE.resize(V + 1);
    
    for(int i = 0 ; i < E;i++){
        cin >> u >> v >> w;
        EDGE[u].push_back(make_pair(v,w));
    }

    for (int i = 0; i < 20001; ++i) {
        MIN[i] = 300000;
        visited[i] = 0;
    }
    pq.push(make_pair(0,K));
    while(!pq.empty()){
        current_dist = pq.top().first;
        current = pq.top().second;
        pq.pop();
        if(visited[current]) continue;
        MIN[current] = current_dist;
        visited[current] = 1;
        tmp_e = EDGE[current].size();

        for(int i = 0; i < tmp_e;i++){
            tmp_v = EDGE[current][i].first;
            tmp_w = EDGE[current][i].second;
            if(current_dist + tmp_w < MIN[tmp_v]){
                pq.push(make_pair(current_dist + tmp_w,tmp_v));
            }
        }
    }
    for(int i = 1; i < V + 1;i++){
        if(visited[i] == 0){
            cout << "INF\n";
        }
        else{
            cout << MIN[i] << "\n";
        }
    }
}