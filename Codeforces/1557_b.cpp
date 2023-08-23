#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  auto b = a;
  sort(b.begin(), b.end());
  map<int,int> mem;
  for (int i = 0; i < n; i++) {
    mem[b[i]] = i;
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (i == 0 || mem[a[i]] != mem[a[i - 1]] + 1) cnt++;
  }
  // cout << cnt << '\n';
  cout << ((cnt == 1 || cnt <= k) ? "Yes" : "No") << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
