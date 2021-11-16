#include <bits/stdc++.h>
using namespace std;

int lcm(int a, int b) {
  return a / __gcd(a, b) * b;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t, n;
  cin >> t >> n;
  n--;
  int l = lcm(100 + t, 100);
  // cout << "l = " << l << '\n';
  set<int> s;
  for (int i = 1; i <= l * 2; i++) {
    int c = i * (100 + t);
    s.insert(c - c % 100);
    if (i <= 50) cout << i << ' ' << (c - c % 100) / 100 << '\n';
  }
  vector<int> v;
  for (int i = 1; i <= l * 2; i++) {
    if (!s.count(i * 100)) {
      v.push_back(i * 100);
    }
  }
  cout << v[n] / 100 << '\n';
}
