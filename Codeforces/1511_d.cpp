#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

int cnt[256];

signed main() {
  // freopen("in" , "r", stdin );
  cin.tie(0)->sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  vector<char> s(n);
  s[0] = 'a';
  for (int i = 1; i < n; i++) {
    s[i] = (s[i - 1] + cnt[s[i - 1]] - 'a') % k + 'a';
    cnt[s[i - 1]]++;
  }
  for (auto &i : s) cout << i;
  cout << endl;
}
