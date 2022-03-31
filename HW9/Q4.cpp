#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int> > adj(500005);
vector<int> nodes(500005, -1);

bool bfs(int curr) {
    queue<int> q;
    q.push(curr);
    nodes[curr] = 0;
    bool check = false;
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        for (int i = 0; i < adj[front].size(); i++) {
            if (nodes[adj[front][i]] == -1) {
                if (nodes[front] == 0) {
                    nodes[adj[front][i]] = 1;
                } else {
                    nodes[adj[front][i]] = 0;
                }
                q.push(adj[front][i]);
            } else if (nodes[adj[front][i]] == nodes[front]) {
                check = true;
            }
        }
    }
    return check;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    int ans = 0;
    bool check = false;
    for (int i = 0; i < n; i++) {
        if (nodes[i] == -1) {
            ans++;
            if (bfs(i)) {
                check = true;
            }
        }
    }

    if (check) {
        cout << (ans-1) << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}