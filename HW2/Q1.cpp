#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        int op, x;
        stack<int> S;
        queue<int> Q;
        priority_queue<int> P;
        bool s = true, q = true, p = true;
        while (n--) {
            cin >> op >> x;
            if (op == 1) {
                if (s)
                    S.push(x);
                if (q)
                    Q.push(x);
                if (p)
                    P.push(x);
            } else if (op == 2) {
                if (s) {
                    if (!S.empty() && S.top() == x)
                        S.pop();
                    else 
                        s = false;
                } 
                if (q) {
                    if (!Q.empty() && Q.front() == x) 
                        Q.pop();
                    else 
                        q = false;
                } 
                if (p) {
                    if (!P.empty() && P.top() == x) 
                        P.pop();
                    else
                        p = false;
                } 
            }
        }

        if (s && p || p && q || q && s)
            cout << "not sure" << endl;
        else if (s && !q && !p) 
            cout << "stack" << endl;
        else if (!s && q && !p) 
            cout << "queue" << endl;
        else if (!s && !q && p)
            cout << "priority queue" << endl; 
        else if (!s && !q && !p)
            cout << "impossible" << endl;

    }

    return 0;
}