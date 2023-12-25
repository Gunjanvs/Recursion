#include <iostream>
#include <vector>

using namespace std;

bool isVowel(char ch) {
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

int subsequence(int index, vector<string>& ds, string s, int n) {
    if (index >= n) {
        int lastindex = ds.size() - 1;
        if (isVowel(ds[0][0]) && !isVowel(ds[lastindex][0])) {
            for (int i = 0; i < ds.size(); i++) {
                cout << ds[i];
            }
            cout << endl;
        }

        return 1;
    }

    // take elements from the index
    ds.push_back(string(1, s[index]));  // Append the character to the string in ds
    int countWE = subsequence(index + 1, ds, s, n);

    // not take elements from the index
    ds.pop_back();
    int countWOE = subsequence(index + 1, ds, s, n);

    return countWE + countWOE;
}

int main() {
    string s = "abc";
    int n = s.size();
    vector<string> ds;
    cout << subsequence(0, ds, s, n);
    return 0;
}
