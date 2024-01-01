#include<iostream>
#include<vector>

using namespace std;

void combinationSum(int index, int k, int n, vector<int>& arr, vector<int>& ds, vector<vector<int>>& ans) {
    // base case
    if (ds.size() == k) {
        int sum = 0;
        for (int num : ds) {
            sum += num;
        }
        if (sum == n) {
            ans.push_back(ds);
        }
        return;
    }

    // recursive case 
    for (int i = index; i < arr.size(); ++i) {
        ds.push_back(arr[i]);
        combinationSum(i + 1, k, n, arr, ds, ans);
        ds.pop_back();
    }
    // why should we not pick simple that we need for loop is for every index if we return it will take another elment try to look in recursion tree

}

int main() {
    vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> ds;
    int sum = 0;
    vector<vector<int>> ans;
    int k = 3;
    int n = 7;
    combinationSum(0, k, n, arr, ds, ans);

    // Print the result
    for (const auto& combination : ans) {
        cout << "[ ";
        for (int num : combination) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
