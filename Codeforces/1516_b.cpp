#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

void Main() {
  int n; cin >> n;
  vector<int> a(n + 1), s(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    s[i] = a[i] ^ s[i - 1];
  }
  for (int i = 1; i <= n - 1; i++) {
    if (s[i] == (s[n] ^ s[i])) {
      cout << "YES" << endl;
      return;
    }
  }
  for (int i = 1; i <= n - 2; i++)
  for (int j = i + 1; j <= n - 1; j++) {
    if (s[i] == (s[j] ^ s[i]) && s[i] == (s[n] ^ s[j])) {
      cout << "YES" << endl;
      return;
    }
  }
  cout << "NO" << endl;
}

signed main() {
  // freopen("in" , "r", stdin );
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
