// atoi.cpp
#include<iostream>
#include<algorithm>
using namespace std ;
int myAtoi(string s) {
        int n = s.length();
        int i = 0;

        // Step 1: Ignore leading whitespaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // Step 2: Check for '+' or '-'
        int sign = 1;
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Step 3: Read digits until the next non-digit character or end of input
        long long result = 0; // Use long long to handle potential overflow
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');

            // Step 4: Check if result is within 32-bit signed integer range
            if (result * sign < INT_MIN) {
                return INT_MIN;
            } else if (result * sign > INT_MAX) {
                return INT_MAX;
            }

            i++;
        }

        // Apply sign to the result
        return static_cast<int>(result * sign);
    }

int myAtoi(string s,int n) {
    if (n == 0) {
        return 0 ;
    }

    char lastChar = s[n - 1];

    if (!isdigit(lastChar)) {
        return myAtoi(s,n - 1);
    }

    int lastDigit = lastChar - '0';
    int chotaNum = myAtoi(s, n - 1);
    return chotaNum * 10 + lastDigit;
}
int main(){
	string s ="words and 987";
	bool signNegOrNot = false;
    int n = s.length();
    int ans = myAtoi(s,n);
    for (int i = 0; i < n; i++) {
    if (s[i] == '-') {
        signNegOrNot = true;
        break;
    }
}
    if(signNegOrNot == true)ans = ans * -1;
    cout << ans;
    
}