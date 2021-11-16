#include <bits/stdc++.h>
using namespace std;

#define int long long

void chmin(int &a, int b) {
  if (a > b) a = b;
}

namespace sub1 {
  void Main(int n, vector<int> x, vector<int> v) {
    int ans = 0;
    for (int i = 0; i + 1 < n; i++)
    for (int j = i + 1; j < n; j++) {
      int cal = x[i] == x[j] ? 0 : abs(x[i] - x[j]);
      if (v[i] != v[j]) {
        int t = (x[i] - x[j]) / (v[j] - v[i]);
        int lwb = t >= 0 ? abs((x[i] + v[i] * t) - (x[j] + v[j] * t)) : LLONG_MAX;
        int upb = t + 1 >= 0 ? abs((x[i] + v[i] * (t + 1)) - (x[j] + v[j] * (t + 1))) : LLONG_MAX;
        chmin(cal, min(lwb, upb));
      }
      ans += cal;
    }
    cout << ans << '\n';
  }
};

namespace sub2 {
  void Main(int n, vector<int> x, vector<int> v) {
    
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<int> x(n), v(n);
  for (auto &i : x) cin >> i;
  for (auto &i : v) cin >> i;
  if (n <= 1000) sub1::Main(n, x, v);
  else sub2::Main(n, x, v);
}
