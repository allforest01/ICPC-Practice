#include <bits/stdc++.h>
using namespace std;

int n, tempi;
string s, solve, tempsolve;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int q = 0; q < n; q++) {
        cin >> s;
        solve = "";
        tempsolve = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == s[s.length() - (i + 1)]) {
                tempsolve += s[i];  
            }
            else {
                if (tempsolve.length() > solve.length()) {
                    solve = tempsolve;
                }
                tempsolve = "";
            }
        }
        if (tempsolve.length() > solve.length()) {
            solve = tempsolve;
        }
        cout << solve << '\n';
    }
    return 0;
}