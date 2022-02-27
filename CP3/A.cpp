#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    int plots[n];
    for (int i = 0; i < n; i++) {
        cin >> plots[i];
    }

    float houses[m + k];
    for (int i = 0; i < m; i++) {
        cin >> houses[i];
    }
    for (int i = m; i < k + m; i++) {
        float temp;
        cin >> temp;
        houses[i] = (temp / 2) * sqrt(2);
    }

    sort(plots, plots + n);
    sort(houses, houses + k + m);

    int i = 0, j = 0, count = 0;
    while (i < n && j < m+k) {
        if (plots[i] > houses[j]) {
            count++;
            i++;
            j++;
        } else {
            i++;
        }
    }

    cout << count << endl;

    return 0;
}