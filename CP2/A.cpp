#include <iostream>
#include <map>
#include <iterator>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int a[n];
        multimap<int, int> m;
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            a[i] = temp;
        }
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            m.insert(pair<int, int> (a[i], temp));
        }

        map<int, int>::iterator iter;
        for (iter = m.begin(); iter != m.end(); iter++) {
            if (iter->first <= k) {
                k += iter->second;
            }
        }

        cout << k << endl;

    }

    return 0;
}