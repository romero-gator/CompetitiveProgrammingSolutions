#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int nodes[n+5];
    for (int i = 1; i <= n; i++) {
        cin >> nodes[i];
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int count = 0;
        int parent = nodes[i];
        while (parent > 0) {
            parent = nodes[parent];
            count++;
        }
        
        if (count > ans) {
            ans = count;
        }
    }

    cout << (ans+1) << endl;

    return 0;
}