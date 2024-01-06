#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

void solve() {
    vector<int> a(3);
    cin >> a[0] >> a[1] >> a[2];
    sort(a.begin(), a.end());
    if (a[0] != a[1]) cout << a[0];
    else cout << a[2];
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T = 1; cin >> T;
    while (T--) solve();
}
