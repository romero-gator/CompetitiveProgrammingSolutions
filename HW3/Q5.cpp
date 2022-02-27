#include <iostream>
#include <algorithm>
using namespace std;

int main ()
{
    int n, moves = 0, x[10001], y[10001]; 
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int tempX, tempY;
        cin >> tempX >> tempY;
        x[i] = tempX;
        y[i] = tempY;
    }

    // sort arrays
    sort(x+1, x+n+1);
    sort (y+1, y+n+1);

    // calc how far off each x is from where it should be
    for(int i=1;i<=n;i++) {
        x[i] = x[i] - i + 1;
    }
    
    // sort x[] again
    sort(x+1, x+n+1);

    // calc how many moves required to get in position
    int midx = x[(n/2) + 1], midy = y[(n/2) + 1];
    for (int i = 1; i <= n; i ++)
    {
        moves += abs(x[i] - midx);
        moves += abs(y[i] - midy);
    }

    cout << moves << endl;

    return 0;
}