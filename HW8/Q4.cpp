#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, dist[2020];
char str[1010];
vector<int> v[2020];

void bfs(int start) {
    for (int i = 1; i <= n+m; i++) {
        dist[i] = 100000;
    }

    dist[start] = 0;
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int first = q.front();
        q.pop();
        for (int i = 0; i < v[first].size(); i++) {
            if (dist[first] + 1 < dist[v[first][i]]) {
                dist[v[first][i]] = dist[first] + 1;
                q.push(v[first][i]);
            }
        }
    }

    return;
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        scanf("%s", str+1);
        for (int j = 1; j <= m; j++) {
            if (str[j] == '#') {
                v[i].push_back(n+j);
                v[n+j].push_back(i);
            }
        }
    }

    bfs(n);

    if (dist[1] >= 100000) {
        dist[1] = -1;
    }
    cout << dist[1] << endl;

    return 0;
}