#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    long long dorms[n];
    for (int i = 0; i < n; i++) {
        long long temp;
        cin >> temp;
        dorms[i] = temp;
    }

    long long curr = 0, total = 0;
    for (int i = 0; i < m; i++) {
        long long temp; 
        cin >> temp;

        while ((temp - total) > dorms[curr]) {
            total += dorms[curr];
            curr++;
        }
        cout << (curr + 1) << " " << (temp - total) << endl;
    }

    return 0;
}