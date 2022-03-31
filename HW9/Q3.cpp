#include <iostream>
using namespace std;

char nodes[110][110];

void traverseNodes(int a, int b) {
    if (nodes[a-1][b+1] == '#') {
        nodes[a-1][b+1] = '.';
        traverseNodes(a-1, b+1);
    }
    if (nodes[a][b+1] == '#') {
        nodes[a][b+1] = '.';
        traverseNodes(a, b+1);
    }
    if (nodes[a+1][b+1] == '#') {
        nodes[a+1][b+1] = '.';
        traverseNodes(a+1, b+1);
    }
    if (nodes[a-1][b] == '#') {
        nodes[a-1][b] = '.';
        traverseNodes(a-1, b);
    }
    if (nodes[a+1][b] == '#') {
        nodes[a+1][b] = '.';
        traverseNodes(a+1, b);
    }
    if (nodes[a-1][b-1] == '#') {
        nodes[a-1][b-1] = '.';
        traverseNodes(a-1, b-1);
    }
    if (nodes[a][b-1] == '#') {
        nodes[a][b-1] = '.';
        traverseNodes(a, b-1);
    }
    if (nodes[a+1][b-1] == '#') {
        nodes[a+1][b-1] = '.';
        traverseNodes(a+1, b-1);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> nodes[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (nodes[i][j] == '#') {
                ans++;
                nodes[i][j] = '.';
                traverseNodes(i,j);
            }
        }
    }

    cout << ans << endl;

    return 0;
}