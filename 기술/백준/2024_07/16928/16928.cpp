#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> ladder(101, 0);
    vector<int> snake(101, 0);

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        ladder[x] = y;
    }

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        snake[u] = v;
    }

    queue<int> q;
    vector<int> dist(101, -1); 

    dist[1] = 0;
    q.push(1);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int dice = 1; dice <= 6; dice++) {
            int next = curr + dice;
            if (next > 100) continue; 

            if (ladder[next] != 0) {
                next = ladder[next];
            } else if (snake[next] != 0) {
                next = snake[next];
            }

            if (dist[next] == -1) {
                dist[next] = dist[curr] + 1;
                q.push(next);
            }
        }
    }

    cout << dist[100] << endl;

    return 0;
}
