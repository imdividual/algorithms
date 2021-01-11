#include <bits/stdc++.h>

using namespace std;

// uses dp approach

string longest_palindromic_substr(string str) {
    if (str == "") return "";

    int len = str.length();
    bool dp[len][len];
    memset(dp, false, sizeof(dp));

    string longest = "";

    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            if (j + i >= len) continue;
            int a = j;
            int b = j + i;
            int l = b - a + 1;
            bool palindrome = false;
            if (a == b) {
                palindrome = true;
            } else if (a + 1 == b) {
                palindrome = str[a] == str[b];
            } else {
                palindrome = str[a] == str[b] && dp[a + 1][b - 1];
            }
            dp[a][b] = palindrome;
            if (palindrome && l > longest.length()) {
                longest = str.substr(a, l);
            }
        }
    }

    return longest;
}

int main() {
    cout << longest_palindromic_substr("aabbabbaaaabccd") << endl;
    return 0;
}
