#include <iostream>
#include <math.h>
using namespace std;

typedef long long ll;

void solve() {
    int n; cin >> n;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        sum += x;
    }
    ll t = sqrt(sum);
    for (ll i = t - 2; i <= t + 2; i++) {
        if (i * i == sum) {
            cout << "YES" << '\n';
            return;
        }
    }
    cout << "NO" << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T = 1; cin >> T;
    while (T--) solve();
}
