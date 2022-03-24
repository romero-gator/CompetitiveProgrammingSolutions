#include <iostream>
#include <vector>
using namespace std;

int arr[1010];
vector<int> v[1010];
bool check;

void dfs(int x) {
    if (check) {
        return;
    }

    arr[x] = 1;
    for (int i = 0; i < v[x].size(); i++) {
        if (arr[v[x][i]] == 0) {
            dfs(v[x][i]);
        } else {
            cout << v[x][i] << " ";
            check = true;
            return;
        }
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int temp;
        cin >> temp;
        v[i].push_back(temp);
    }

    for (int i = 1; i <= n; i++) {
        check = false;
        fill(arr, arr + n + 1, 0);
        dfs(i);
    }

    cout << endl;

    return 0;
}