#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

vector<int> prim;

void Init() {
  int n = 50000;
  vector<int> prime(n + 1);
  prime[0] = prime[1] = 1;
  for (int i = 2; i <= n; i++) if (!prime[i]) {
    prim.push_back(i);
    for (int j = i * 2; j <= n; j += i) prime[j] = 1;
  }
}

map<int, int> cal(int n) {
  map<int, int> res;
  for (int i = 0; i < prim.size(); i++) {
    while (n % prim[i] == 0) {
      res[prim[i]]++;
      n /= prim[i];
    }
  }
  if (n != 1) res[n]++;
  return res;
}

void Main() {
  int a, b, k;
  cin >> a >> b >> k;
  map<int, int> ma = cal(a), mb = cal(b);
  int s = 0;
  for (auto &i : ma) s += i.second;
  for (auto &i : mb) s += i.second;
  if (k == 0) {
    cout << ((a == b) ? "YES" : "NO") << endl;
  }
  else if (k == 1) {
    cout << ((a != b && (a % b == 0 || b % a == 0)) ? "YES" : "NO") << endl;
  }
  else {
    if (k <= s) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}

signed main() {
  // freopen("in" , "r", stdin );
  cin.tie(0)->sync_with_stdio(0);
  Init();
  int T; cin >> T;
  while (T--) Main();
}
