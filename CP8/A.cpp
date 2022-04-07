#include <iostream>
#include <map>
using namespace std;

int main() {
    int t;  
    cin >> t;

    while (t--) {
        int n;  
        cin >> n;

        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            // Preprocess input array by summing the subarrays
            if (i > 0) {   
                arr[i] += arr[i-1];
            }
        }

        map<int, int> m;  
        m[0] = 1;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += m[arr[i] - 47];
            m[arr[i]]++;
        }

        cout << ans << endl;
    }

    return 0;
}