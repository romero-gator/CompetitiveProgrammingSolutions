#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int gcf(int a, int b) {
    return b == 0 ? a : gcf(b, a%b);
}

void dijkstra(map<int, vector<pair<int, int> > >& nodes, int src) {
    int dist[nodes.size()];
    bool path[nodes.size()];

    for (int i = 0; i < nodes.size(); i++) {
        dist[i] = INT_MAX;
        path[i] = false;
    }

    dist[0] = 0;

    //uncomplete
}

int main() {
    int n;
    cin >> n;

    map<int, vector<pair<int, int> > > rooms;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        rooms.insert(pair<int, vector<pair<int, int> > >(temp, vector<pair<int, int> >()));
    }

    for (map<int, vector<pair<int, int> > > ::iterator iter1 = rooms.begin(); iter1 != rooms.end(); iter1++) {
        for (map<int, vector<pair<int, int> > > ::iterator iter2 = iter1; iter2 != rooms.end(); iter2++) {
            if (iter1 == iter2) {
                continue;
            }
            int f = gcf(iter1->first, iter2->first);
            if (f > 1) {
                iter1->second.push_back(pair<int, int>(iter2->first, f));
                iter2->second.push_back(pair<int, int>(iter1->first, f));
            }
        }
    }

    //uncomplete

    return 0;
}