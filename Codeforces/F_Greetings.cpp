#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct BIT {
    int n; vector<int> v;
    BIT(int n): n(n), v(n + 1) {}
    void update(int i, int val) {
        for (; i <= n; i += i & -i) {
            v[i] += val;
        }
    }
    int get(int i) {
        int val = 0;
        for (; i; i -= i & -i) {
            val += v[i];
        }
        return val;
    }
};

void solve() {
    int n; cin >> n;
    set<int> s;
    vector<pair<int,int>> a(n);
    for (auto &i : a) {
        cin >> i.first >> i.second;
        s.insert(i.first);
        s.insert(i.second);
    }
    vector<int> v(s.begin(), s.end());
    for (auto &i : a) {
        i.first = lower_bound(v.begin(), v.end(), i.first) - v.begin() + 1;
        i.second = lower_bound(v.begin(), v.end(), i.second) - v.begin() + 1;
    }
    sort(a.begin(), a.end(), [](pair<int,int> &a, pair<int,int> &b) {
        return a.first > b.first;
    });
    ll ans = 0;
    BIT bit(v.size());
    for (auto &i : a) {
        ans += bit.get(i.second);
        bit.update(i.second, 1);
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T = 1; cin >> T;
    while (T--) solve();
}
