#include <iostream>
#include <vector>
using namespace std;

int main() {
	int numOfElements;
	cin >> numOfElements;
	int numOfDividers;
	cin >> numOfDividers;
	vector<int> runningSum(numOfElements + 1, 0);
	int nextElement;
	for (int i = 1; i < numOfElements + 1; i++) {
		cin >> nextElement;
		runningSum[i] = runningSum[i - 1] + nextElement;
	}
	runningSum.erase(runningSum.begin());
	vector<int> runningRoundedSum(numOfElements, 0);
	for (int i = 0; i < numOfElements; i++) {
		int currentValue = runningSum[i];
		if (currentValue % 10 >= 5) {
			runningRoundedSum[i] = currentValue - (currentValue % 10) + 10;
		}
		else {
			runningRoundedSum[i] = currentValue - (currentValue % 10);
		}
	}
	vector<vector<int> > dpArr(numOfElements, vector<int>(numOfDividers + 1, 0));
	for (int i = 0; i < numOfElements; i++) {
		dpArr[i][0] = runningRoundedSum[i];
	}
	int div = 1;
	while(div <= numOfDividers){
		for (int elem = 0; elem < numOfElements; elem++) {
			dpArr[elem][div] = runningSum[numOfElements - 1] + runningSum[numOfElements - 1];
			for (int i = 0; i < elem + 1; i++) {
				int difference = runningSum[elem] - runningSum[i];
				if (difference % 10 >= 5) {
					difference = difference - (difference % 10) + 10;
				}
				else {
					difference = difference - (difference % 10);
				}
				if (dpArr[elem][div] > (dpArr[i][div - 1] + difference)) {
					dpArr[elem][div] = (dpArr[i][div - 1] + difference);
				}
			}
		}
		div += 1;
	}
	cout << dpArr[numOfElements - 1][numOfDividers] << "\n";
}