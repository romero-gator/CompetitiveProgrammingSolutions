#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int coins[n];
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    bool valid = false;
    
    // implement greedy and then check it with dp approach and go until the sum of the last two coins
       
    if (valid) {
        cout << "canonical" << endl;
    } else {
        cout << "non-canonical" << endl;
    }

    return 0;
}