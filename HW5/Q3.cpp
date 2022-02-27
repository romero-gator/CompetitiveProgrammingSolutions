#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

bool compareDolls(pair<int, int> d1, pair<int, int> d2) {
    if (d1.first == d2.first) {
        return d1.second < d2.second;
    }
    return d1.first > d2.first;
}

int main() {
	int t;
	cin >> t;
	while(t--)
	{
		int m;
		cin >> m;

        vector<pair<int, int> > v;
		for (int i = 0; i < m; i++) {
            int w, h;
            cin >> w >> h;
            v.push_back(pair<int, int> (w, h));
		}

        sort(v.begin(), v.end(), compareDolls);

        int arr[100001];
        fill(arr, arr+m,INT_MAX);

        for (int i = 0; i < m; i++) {
            *upper_bound(arr, arr+m, v[i].second) = v[i].second;
        }

        int ans = (lower_bound(arr, arr+m, INT_MAX) - arr);
        cout << ans << endl;
    }

	return 0;
}