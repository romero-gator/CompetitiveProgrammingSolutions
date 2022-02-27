#include <iostream>
using namespace std;

int merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left, j = mid, k = left, count = 0;
    while ((mid - 1) >= i && right >= j) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            count += (mid - i);
        }
    }

    while (i <= (mid - 1)) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return count;
}

int msort(int arr[], int temp[], int left, int right) {
    int mid, count = 0;
    if (right > left) {
        mid = (right + left) / 2;
        count += msort(arr, temp, left, mid);
        count += msort(arr, temp, mid + 1, right);
        count += merge(arr, temp, left, mid + 1, right);
    }
    return count;
}

int mergesort(int arr[], int size) {
    int temp[size];
    return msort(arr, temp, 0, size - 1);
}


int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            int temp; 
            cin >> temp;
            arr[i] = temp;
        }

        int invs = mergesort(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl << invs << endl;
    }

    return 0;
}