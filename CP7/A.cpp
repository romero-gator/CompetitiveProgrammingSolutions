#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;


int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        queue<int> q;
        vector<int> visited(n+1, -1);
        for (int i = 0; i < k; i++) {
            int temp;
            cin >> temp;
            visited[temp] = 0;
            q.push(temp);
        }

        map<int, vector<int> > corridors;
        for (int i = 0; i < n-1; i++) {
            int v, u;
            cin >> v >> u;
            corridors[v].push_back(u);
            corridors[u].push_back(v);
        }

        q.push(1);
        visited[1] = 1;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int i = 0; i < corridors[curr].size(); i++) {    
                if (visited[corridors[curr][i]] == -1) {
                    q.push(corridors[curr][i]);
                    visited[corridors[curr][i]] = visited[curr];
                }
            }
        }

        bool ans = false;
        for (map<int, vector<int> >::iterator iter = corridors.begin(); iter != corridors.end(); iter++) {
            if (iter->first == 1) {
                continue;
            }

            if (iter->second.size() == 1 && visited[iter->first] == 1) {
                ans = true;
                break;
            }
        }

        if (ans) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}