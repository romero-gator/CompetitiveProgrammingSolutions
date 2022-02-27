#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int arr[n], possibleChoices[n];
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            possibleChoices[i] = arr[i];
        }

        int maxChoice = 0;
        for (int i = 1; i <= n; i++) {
            if (arr[i] + i <= n) {
                possibleChoices[arr[i] + i] = max(possibleChoices[arr[i] + i], possibleChoices[i] + arr[arr[i] + i]);
            }
            maxChoice = max(maxChoice, possibleChoices[i]);
        }

        cout << maxChoice << endl;
    }




    return 0;
}