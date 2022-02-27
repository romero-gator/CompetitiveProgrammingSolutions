#include <iostream>
using namespace std;

int main() {
    int coins[] = {1, 5, 10, 25, 50};
    long long arr[30001] = {0};
    arr[0] = 1;
    for (int i = 0; i < 5; i++) {
        for (int j = coins[i]; j <= 30000; j++) {
            arr[j] += arr[j - coins[i]];
        }
    }

    int num;
    while (cin >> num) {
        if (num < 5) {
            cout << "There is only 1 way to produce " << num << " cents change." << endl;
        } else {
            cout << "There are " << arr[num] << " ways to produce " << num << " cents change." << endl;
        }
    }

    return 0;
}