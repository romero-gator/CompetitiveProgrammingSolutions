#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        float length;
        float width;
        cin >> length >> width;

        vector<pair<float, float> > v;
        for (int i = 0; i < n; i++) {
            float xpos, radius;
            cin >> xpos >> radius;

            if ((width / 2) < radius) {
                float temp = (sqrt(pow(radius,2) - pow(width/2,2)));
                if (temp > 0) {
                    float left = xpos - temp, right = xpos + temp;
                    if (left < 0) {
                        left = 0.0;
                    }
                    v.push_back(pair<float, float> (left, right));
                }
            }
        }

        if (v.empty()) {
            cout << -1 << endl;
        } else {
            sort(v.begin(), v.end());

            int count = 1;
            pair<float, float> curr = v[0], temp = v[0];
            for (int i = 1; i < v.size(); i++) {
                if (curr.second >= length) {
                    break;
                }

                if (v[i].first == curr.first && v[i].second > curr.second) { 
                    curr = v[i];
                    temp = curr;
                } else if (v[i].first <= curr.second && v[i].second > temp.second) { 
                    temp = v[i];
                } else if (v[i].first > curr.second && curr != temp) {
                    curr = temp;
                    count++;
                    i--;
                } 
            }

            if (curr != temp) {
                count++;
                curr = temp;
            }

            if (v[0].first != 0.0 || curr.second < length) {
                cout << -1 << endl;
            } else {
                cout << count << endl;
            }
        }

    }

    return 0;
}