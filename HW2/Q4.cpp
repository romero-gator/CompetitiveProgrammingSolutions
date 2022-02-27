#include <iostream>
using namespace std;

int main () {
    long long int n, v[21] = {0};
    cin >> n;
    while (n--) {
        long long int temp;
        cin >> temp;
        v[temp + 10]++;
    }
    
   long long int count = (v[10]) * (v[10] - 1) / 2;
    for (int i = 0; i < 10; i++) {
        count += ((v[i]) * (v[20-i]));
    }
    cout << count << endl;

    return 0;
}