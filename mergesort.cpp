#include<iostream>
#include<vector>
using namespace std;

void merGe(vector<int> &arr, int low, int high, int mid) {
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mS(vector<int> &arr, int low, int high) {
    if (low == high) {
        return;
    }

    int mid = (low + high) / 2;
    mS(arr, low, mid);
    mS(arr, mid + 1, high);
    merGe(arr, low, high, mid);
}

int main() {
    vector<int> arr{3, 2, 1, 40};
    mS(arr, 0, 3);  // Note: The third argument should be the last index of the array, which is 3 in this case.

    for (int i = 0; i < 4; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
