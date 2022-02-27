#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int numHotels, numEuros, max = 0, runningSum = 0, startIndex = 0;
    vector<int> hotels;
    cin >> numHotels;
    cin >> numEuros;
    
    for (int i = 0; i < numHotels; i++) {
        int temp;
        cin >> temp;
        hotels.push_back(temp);
        runningSum += hotels[i];
        if (runningSum > numEuros) {     
            while (runningSum > numEuros && startIndex < i) {
                runningSum -= hotels[startIndex];
                startIndex++;
            }
        } 

        if (runningSum > max && runningSum <= numEuros) {
            max = runningSum;
        }

        if (max == numEuros) {
            break;
        }
    }
    cout << max << endl;

    return 0;
}