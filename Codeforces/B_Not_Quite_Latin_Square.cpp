#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

typedef long long ll;

void solve() {
    vector<string> a(3);
    cin >> a[0] >> a[1] >> a[2];
    map<char, int> cnt;
    for (auto &i : a) {
        for (auto &j : i) {
            cnt[j]++;
        }
    }
    for (auto &i : cnt) {
        if (i.second == 2) {
            cout << i.first << '\n';
            return;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T = 1; cin >> T;
    while (T--) solve();
}
