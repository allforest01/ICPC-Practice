#include <bits/stdc++.h>
using namespace std;

void chmax(int &a, int b) {
  if (a < b) a = b;
}

signed main() {
  int n; cin >> n;
  if (n == 0) {
    cout << "impossible" << '\n';
    return 0;
  }
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
    if (i == 0) {
      cout << "impossible" << '\n';
      return 0;
    }
  }
  map<int,int> sum, lcm;
  for (auto &i : a) {
    map<int,int> cur;
    int t = i;
    for (int j = 2; j * j <= t; j++) {
      while (t % j == 0) {
        t /= j;
        cur[j]++;
      }
    }
    if (t > 1) cur[t]++;
    for (auto &j : cur) {
      sum[j.first] += j.second;
      chmax(lcm[j.first], j.second);
    }
  }
  for (auto &i : lcm) {
    sum[i.first] -= i.second;
  }
  long long ans = 1;
  for (auto &i : sum) {
    for (int j = 1; j <= i.second; j++) {
      ans *= i.first;
    }
  }
  cout << ans << '\n';
}