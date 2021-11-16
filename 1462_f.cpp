#include <bits/stdc++.h>
using namespace std;

#define ar array

struct Bit {
  int n; vector<int> bit;
  Bit(int n): n(n), bit(n + 1) {}
  void update(int i, int v) {
    for (; i <= n; i += i & -i) {
      bit[i] += v;
    }
  }
  int get(int i) {
    int v = 0;
    for (; i; i -= i & -i) {
      v += bit[i];
    }
    return v;
  }
};

void Main() {
  int n; cin >> n;
  vector<ar<int,3>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i][0] >> a[i][1];
    a[i][2] = i;
  }
  vector<int> l(n), r(n);
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    auto p = upper_bound(a.begin(), a.end(), ar<int,3>({a[i][1], INT_MAX, 0})) - a.begin();
    r[a[i][2]] = n - p;
  }
  for (int i = 0; i < n; i++) {
    swap(a[i][0], a[i][1]);
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    auto p = lower_bound(a.begin(), a.end(), ar<int,3>({a[i][1], INT_MIN, 0})) - a.begin();
    l[a[i][2]] = p;
  }
  int ans = INT_MAX;
  for (int i = 0; i < n; i++) {
    ans = min(ans, l[i] + r[i]);
  }
  cout << ans << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
