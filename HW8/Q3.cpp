#include <iostream>
#include <vector>
using namespace std;

struct edge {
    int a, b;
    bool marked = false;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> deg(n+1);
    vector<edge> edges;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        deg[a]++;
        deg[b]++;
        edge temp;
        temp.a = a;
        temp.b = b;
        edges.push_back(temp);
    }

    int ans = 0;
    bool check = true;
    while (check) {
        vector<edge*> kickOut;
        check = false;
        for (int i = 0; i < edges.size(); i++) {
            if (!edges[i].marked && (deg[edges[i].a] == 1 || deg[edges[i].b] == 1)) {
                kickOut.push_back(&edges[i]);
                check = true;
            }
        }

        for (int i = 0; i < kickOut.size(); i++) {
            deg[kickOut[i]->a]--;
            deg[kickOut[i]->b]--;
            kickOut[i]->marked = true;
        }

        if (check) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}