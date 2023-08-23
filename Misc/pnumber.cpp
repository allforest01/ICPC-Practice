#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int N = 200000;

int prime[N + 1];

signed main() {
  // freopen("in" , "r", stdin );
  cin.tie(0)->sync_with_stdio(0);
  prime[0] = prime[1] = 1;
  for (int i = 0; i <= N; i++) if (!prime[i]) {
    for (int j = i * 2; j <= N; j += i) prime[j] = 1;
  }
  int l, r;
  cin >> l >> r;
  for (int i = l; i <= r; i++) {
    if (!prime[i]) cout << i << endl;
  }
}
