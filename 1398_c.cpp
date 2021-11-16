#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n; cin >> n;
  string s;
  cin >> s;
  s = '#' + s;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    a[i] = s[i] - '0';
    a[i] += a[i - 1];
  }
  map<int,int> cnt; cnt[0] = 1;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += cnt[a[i] - i];
    cnt[a[i] - i]++;
  }
  cout << ans << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
