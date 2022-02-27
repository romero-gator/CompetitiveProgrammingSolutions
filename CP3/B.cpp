#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    long long s, c, k;
    cin >> s >> c >> k;

    vector<long long> v;
    for (int i = 0; i < s; i++) {
        long long temp;
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    long long currMin = v[0], currMachine = 1, count = 1;
    for (int i = 1; i < s; i++) {
        if (currMachine == c) { 
            currMin = v[i];
            currMachine = 0;
            count++;
        }

        if (abs(v[i] - currMin) <= k) {  
            currMachine++;
        } else {
            currMin = v[i];
            currMachine = 0;
            count++;
        }
    }

    cout << count << endl;

    return 0;
}