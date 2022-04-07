#include <iostream>
#include <cmath>
#include <vector>
#include <climits>
using namespace std;

vector<int> st, v;

int query(int start, int end, int qstart, int qend, int curr) {
    if (qstart <= start && qend >= end) {
        return st[curr];
    } else if (qstart > end || start > qend) {  
        return INT_MIN;
    } else {
        int mid = start + (end - start) / 2;
        return max(query(start, mid, qstart, qend, (2 * curr + 1)), query(mid+1, end, qstart, qend, (2 * curr + 2)));
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    int max_size = 2 * (int)pow(2, (int)(ceil(log2(n+1)))) - 1;
    st.resize(max_size, -1);
    v.resize(n+1);
    for (int i = 1; i <= n; i++) {
        int temp;
        cin >> temp;
        v[i] = temp;
        st[n+i] = temp;
    }

    for (int i = n; i > 0; --i) {
        st[i] = max(st[i<<1], st[i<<1 | 1]);
    }

    st.erase(st.begin());
    
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        if (v[a] >= query(0, n-1, a-1, b-2, 0)) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}