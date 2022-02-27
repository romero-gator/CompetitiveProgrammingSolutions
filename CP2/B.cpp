#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int> > v;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        v.push_back(pair<int, int> (l, r));
    }

    int conflicts[5001] = {0}, totalConflicts = 0;
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (v[j].first < v[i].second && v[i].first < v[j].second) {
                conflicts[i]++;
                conflicts[j]++;
                totalConflicts++;
            }
        }
    }

    vector<int> res;
    for (int i = 0; i < v.size(); i++) {
        if (conflicts[i] == totalConflicts) {
            res.push_back(i+1);
        }
    }

    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}