#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int c, n;
    while (cin >> c) {
        cin >> n;

        vector<pair<int, int> > items;
        for (int i = 0; i < n; i++) {
            int val, weight;
            cin >> val >> weight;
            items.push_back(pair<int, int>(val, weight));
        }

        int dp[n+1][c+1];
        for (int i = 0; i <= c; i++) {
            dp[0][i] = 0;
        }
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= c; j++) {
                if (items[i-1].second <= j) {
                    if ((items[i-1].first + dp[i-1][j-items[i-1].second]) > dp[i-1][j]) {
                        dp[i][j] = items[i-1].first + dp[i-1][j-items[i-1].second];
                    } else {
                        dp[i][j] = dp[i-1][j];
                    }
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        int runningVal = dp[n][c], lastChosenIndex = n, runningWeight = c, numItemsChosen = 0;
        vector<int> itemsChosen;
        while (runningVal > 0) {
            for (int i = lastChosenIndex; i >= 0; i--) {
                if (dp[i][runningWeight] != dp[lastChosenIndex][runningWeight]) {
                    lastChosenIndex = i;
                    numItemsChosen++;
                    itemsChosen.push_back(i);
                    break;
                }
            }
            runningWeight -= items[lastChosenIndex].second;
            runningVal -= items[lastChosenIndex].first;
        }
        
        cout << numItemsChosen << endl;
        sort(itemsChosen.begin(), itemsChosen.end());
        for (int i = 0; i < itemsChosen.size(); i++) {
            cout << itemsChosen[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}