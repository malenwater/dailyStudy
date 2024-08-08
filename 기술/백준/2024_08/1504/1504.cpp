#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<pair<int,int>>> EDGE;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int MIN[801];
int visited[801];
int Three_visited[2][3] = {0,};
int sum1, sum2, middle,pop_dist,pop_V,pop_neighbor_size,neighbor_dist,neighbor_V,neighbor_sum_dist;
void Dijkstra(int K){
    fill_n(MIN,801,999999);
    fill_n(visited,801,0);
    pq.push(make_pair(0,K));
    MIN[K] = 0;
    while(!pq.empty()){
        pop_dist = pq.top().first;
        pop_V = pq.top().second;
        pq.pop();
        if(visited[pop_V]) continue;
        MIN[pop_V] = pop_dist;
        visited[pop_V] = 1;
        pop_neighbor_size = EDGE[pop_V].size();
        for(int i = 0; i < pop_neighbor_size;i++){
            neighbor_dist = EDGE[pop_V][i].first;
            neighbor_V = EDGE[pop_V][i].second;
            neighbor_sum_dist = pop_dist + neighbor_dist;
            if(neighbor_sum_dist < MIN[neighbor_V]){
                pq.push(make_pair(neighbor_sum_dist,neighbor_V));
                MIN[neighbor_V] = neighbor_sum_dist;
            }
        }
    }
}

bool checkCanGo(){
    for(int i = 0; i < 2;i++){
        for(int j = 0; j < 3 ;j++){
            if(Three_visited[i][j] >= 999999)return true;
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, E, a, b, c, V1, V2;
    cin >> N >> E;
    EDGE.resize(N+1);
    for(int i =0; i < E;i++){
        cin >> a >> b >> c;
        EDGE[a].push_back(make_pair(c,b));
        EDGE[b].push_back(make_pair(c,a));
    }
    cin >> V1 >> V2;

    for(int i = 0; i < 2;i++){
        if(i == 0){
            Dijkstra(V1);
        }
        else {
            Dijkstra(V2);
        }
        Three_visited[i][0] = MIN[1];
        if(i == 0){
            Three_visited[i][1] = MIN[V2];
        }else{
            Three_visited[i][1] = MIN[V1];
        }
        Three_visited[i][2] = MIN[N];
    }
    sum1 = Three_visited[0][0] + Three_visited[1][2];
    sum2 = Three_visited[0][2] + Three_visited[1][0];
    middle = Three_visited[0][1];
    if(checkCanGo()) {
        cout << "-1\n";
    }
    else if(sum1 < sum2){
        cout << sum1 + middle <<"\n";
    }
    else{
        cout << sum2 + middle <<"\n";
    }
    return 0;
}