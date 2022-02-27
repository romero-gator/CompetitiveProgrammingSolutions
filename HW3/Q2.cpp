#include <iostream>
#include <map>
#include <iterator>
using namespace std;

int main() {
    unsigned int n;
    cin >> n;
    
    map<int, int> m; 
    while (n--) {
        int a,b;
        cin >> a >> b;
        m[a] = b;
    }

    bool alex = false;
    int prev = m.begin()->second;
    for (map<int,int>::iterator iter = m.begin(); iter != m.end(); iter++) {
        if (iter->second < prev) {
            alex = true;
            break;
        }
        prev = iter->second;
    }

    if (alex) {
        cout << "Happy Alex" << endl;
    } else {
        cout << "Poor Alex" << endl;
    }

    return 0;
}