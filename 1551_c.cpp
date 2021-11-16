#include <bits/stdc++.h>
using namespace std;

int solve(vector<string> &v, char c) {
  int n = v.size();
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    for (auto &j : v[i]) {
      if (j == c) a[i]++;
      else a[i]--;
    }
  }
  int sum = 0;
  sort(a.begin(), a.end(), greater<int>());
  for (int i = 0; i <= n; i++) {
    if (sum + a[i] <= 0 || i == n) return i;
    sum += a[i];
  }
}

void Main() {
  int n; cin >> n;
  vector<string> v(n);
  for (auto &i : v) cin >> i;
  int ans = 0;
  for (char c = 'a'; c <= 'z'; c++) {
    ans = max(ans, solve(v, c));
  }
  cout << ans << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
