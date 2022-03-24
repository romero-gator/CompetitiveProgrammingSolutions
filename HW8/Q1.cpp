#include <iostream>
#include <vector>
using namespace std;

int main() {
    int nodes, edges;
    cin >> nodes >> edges;

    vector<int> v(nodes + 1);

    for (int i = 0; i < edges; i++) {
        int a, b;
        cin >> a >> b;
        v[a]++;
        v[b]++;
    }

    int numEnds = 0;
    for (int i = 1; i < v.size(); i++) {
        if (v[i] == nodes - 1 && edges == nodes - 1) {
            cout << "star topology" << endl;
            return 0;
        } else if (v[i] == 1) {
            numEnds++;
        } else if (v[i] == 2) {
            continue;
        } else {
            cout << "unknown topology" << endl;
            return 0;
        }
    }
    
    if (numEnds == 0) {
        cout << "ring topology" << endl;
    } else if (numEnds == 2) {
        cout << "bus topology" << endl;
    } else {
        cout << "unknown topology" << endl;
    }

    return 0;
}