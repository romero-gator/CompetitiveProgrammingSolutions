#include <iostream>
using namespace std;

int main() {
    int n, qx, qy, kx, ky, tx, ty;
    cin >> n >> qx >> qy >> kx >> ky >> tx >> ty;

    if ((qx > kx && qx > tx) || (qx < kx && qx < tx)) {
        if ((qy > ky && qy > ty) || (qy < ky && qy < ty)) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;

    return 0;
}