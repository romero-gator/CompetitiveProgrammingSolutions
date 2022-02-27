#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int s, p;
        cin >> s >> p;

        int xpos[p], ypos[p];
        for (int i = 0; i < p; i++) {
            int x, y;
            cin >> x >> y;
            xpos[i] = x;
            ypos[i] = y;
        }

        vector<pair<float, pair<int, int> > > edges;
        for (int i = 0; i < p; i++) {
            for (int j = i+1; j < p; j++) {
                float dist = sqrt(pow(xpos[j] - xpos[i], 2) + pow(ypos[j] - ypos[i], 2));
                edges.push_back(pair<float, pair<int, int> > (dist, pair<int, int> (i, j)));
            }
        }

        sort(edges.begin(), edges.end());

        int parent[p];
        for (int i = 0; i < p; i++) {
            parent[i] = i;
        }

        vector<pair<float, pair<int, int> > > mst;
        for (int i = 0; i < edges.size(); i++) {
            if (mst.size() == (p-1)) {
                break;
            }

            int x = edges[i].second.first;
            int y = edges[i].second.second;

            while (parent[x] != x) {
                parent[x] = parent[parent[x]];
                x = parent[x];
            }
            
            while (parent[y] != y) {
                parent[y] = parent[parent[y]];
                y = parent[y];
            }
            
            if (x != y) {
                parent[x] = parent[y];
                mst.push_back(edges[i]);
            }
        }

        int index = mst.size() - 1;

        if (s > 1) {
            s -= 2;
            index--;
            while (s > 0) {
                s--;
                index--;
            }
        } 

        cout << fixed;
        cout << setprecision(2);
        cout << mst[index].first << endl;
    }

    return 0;
}