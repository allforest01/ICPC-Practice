#include <bits/stdc++.h>
using namespace std;

int g(int x, bool b) {
  string s = to_string(x);
  sort(s.begin(), s.end());
  if (b) reverse(s.begin(), s.end());
  return stoi(s);
}

int f(int x) {
  return g(x, 1) - g(x, 0);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  if (k == 0) {
    cout << n << '\n';
    return 0;
  }
  map<int,int> s, m;
  s[n] = k;
  m[k] = n;
  while (k > 0) {
    n = f(n);
    k--;
    if (k == 0) {
      cout << n << '\n';
      return 0;
    }
    if (s.count(n)) {
      cout << m[s[n] - k % (s[n] - k)] << '\n';
      return 0;
    }
    s[n] = k;
    m[k] = n;
  }
}
