#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <iterator>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<int, priority_queue<int> > m;
    while (n--) {
        string s;
        cin >> s;

        if (s[0] == 'a') {
            int e, g;
            cin >> e >> g;
            m[e].push(g);
        } else if (s[0] == 'q') {
            int x, g = 0;
            cin >> x;
            
            map<int, priority_queue<int> >::iterator iter;
            while (!m.empty() && x > 0) {
                iter = m.lower_bound(x);

                if (iter == m.end()) {
                    iter--;
                }
                
                while (iter->first > x && iter != m.begin()) { 
                    iter--;
                }

                if (iter->first > x) { 
                    break;
                } else {                
                    g += iter->second.top();
                    x -= iter->first;
                    iter->second.pop();
                    if (iter->second.empty()) {
                        m.erase(iter->first);
                    }
                }
                
            }
            cout << g << endl;
        }
    }

    return 0;
}