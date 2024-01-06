#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<ll> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        ll x; cin >> x;
        if (i % 2) a[i] = x;
        else b[i] = x;
    }
    vector<ll> c(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] += a[i - 1];
        b[i] += b[i - 1];
        c[i] = a[i] - b[i];
    }
    set<ll> mem;
    for (int i = 0; i <= n; i++) {
        if (mem.count(c[i])) {
            cout << "YES" << '\n';
            return;
        }
        mem.insert(c[i]);
    }
    cout << "NO" << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T = 1; cin >> T;
    while (T--) solve();
}
