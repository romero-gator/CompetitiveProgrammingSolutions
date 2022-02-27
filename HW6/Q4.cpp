#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        vector<int> vals, indices, seq(n, -1);
        for (int i = 0; i < n; i++) {
            if (vals.empty() || vals[vals.size() - 1] < arr[i]) {
                if (vals.empty()) {
                    seq[i] = -1;
                } else {
                    seq[i] = indices[vals.size() - 1];
                }
                vals.push_back(arr[i]);
                indices.push_back(i);
            } else {
                int index = lower_bound(vals.begin(), vals.end(), arr[i]) - vals.begin();
                if (index == 0) {
                    seq[i] = -1;
                } else {
                    seq[i] = indices[index - 1];
                }
                vals[index] = arr[i];
                indices[index] = i;
            }
        }
        cout << vals.size() << endl;
        
        vector<int> ans;
        int last = indices[indices.size() - 1];
        while (last != -1) {
            ans.push_back(last);
            last = seq[last];
        }

        for (int i = ans.size() - 1; i >= 0; i--) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}