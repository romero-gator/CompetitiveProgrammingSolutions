#include <iostream>
using namespace std;

const int max_size = 2e5 + 5;
int nodes[max_size], ans[max_size];
int c = 1;

void countExchanges(int index, int start) {
    if (index == start) {
        ans[index] = c;
        return;
    }
    c++;
    countExchanges(nodes[index], start);
    ans[index] = c;
    return;
}

int main() {
    int q;
    cin >> q;

    while (q--) {
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) {
            cin >> nodes[i];
        }

        fill(ans, ans+n+1, 0);
        for (int i = 1; i <= n; i++) {
            if (ans[i] == 0) {
                c = 1;
                countExchanges(nodes[i], i);
            }
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}