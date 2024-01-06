#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n; string s, t;
    cin >> n >> s; t = s;
    for (auto &i : s) {
        if ((int) string("ae").find(i) != -1) i = 'V';
        else i = 'C';
    }
    string res;
    for (int i = 0; i < (int) s.size(); i++) {
        if (i && s[i - 1] == 'C' && s[i] == 'C') res += '.';
        else if (i && i + 1 < (int) s.size() && s[i - 1] == 'V' && s[i + 1] == 'V') res += '.';
        res += t[i];
    }
    cout << res << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T = 1; cin >> T;
    while (T--) solve();
}
