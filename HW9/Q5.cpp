#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <climits>
using namespace std;

vector<long long> dist;
vector<int> visited;
vector<vector<pair<long long, long long> > > adj;
vector<vector<long long> > parents;
map<long long, map<long long, long long> > shortestTrails;
long long p, t;

void djikstra() {
    priority_queue<pair<long long, long long>, vector<pair<long long, long long> >, greater<pair<long long, long long> > > pq;
    pq.push(pair<long long, long long>(0,0));
    dist[0] = 0;

    while (!pq.empty()) {
        long long curr = pq.top().second;
        pq.pop();
        if (visited[curr]) {
            continue;
        }
        visited[curr] = 1;

        for (auto node : adj[curr]) {
            long long weight = node.first;
            long long next = node.second;
            if (dist[curr]+weight < dist[next]) {
                dist[next] = dist[curr]+weight;
                parents[next].clear();
                parents[next].push_back(curr);
                pq.push(pair<long long, long long>(dist[curr]+weight, next));
            } else if (dist[curr]+weight == dist[next]) {
                parents[next].push_back(curr);
            }
        }
    }
}

int main() {
    cin >> p >> t;

    dist.resize(p, INT_MAX);
    visited.resize(p, 0);
    parents.resize(p);
    adj.resize(p);

    for (long long i = 0; i < t; i++) {
        long long p1, p2, l;
        cin >> p1 >> p2 >> l;
        if (p1 == p2) {
            continue;
        }

        adj[p1].push_back(pair<long long, long long>(l, p2));
        adj[p2].push_back(pair<long long, long long>(l, p1));
        if (shortestTrails.count(p1) == 0 || shortestTrails[p1].count(p2) == 0) {
            shortestTrails[p1][p2] = l;
            shortestTrails[p2][p1] = l;
        } else {
            shortestTrails[p1][p2] = min(shortestTrails[p1][p2], l);
            shortestTrails[p2][p1] = min(shortestTrails[p2][p1], l);
        }
    }

    djikstra();

    visited.clear();
    visited.resize(p, false);
    queue<long long> q;
    q.push(p-1);
    long long flowers = 0;
    while (!q.empty()) {
        long long curr = q.front();
        q.pop();
        if (visited[curr]) {
            continue;
        }
        visited[curr] = 1;

        for (auto node : parents[curr]) {
            flowers += shortestTrails[curr][node];
            q.push(node);
        }
    }

    cout << (flowers * 2) << endl;

    return 0;
}