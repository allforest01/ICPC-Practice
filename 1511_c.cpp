#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

int pos[55], cnt[55];

signed main() {
  // freopen("in" , "r", stdin );
  cin.tie(0)->sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    if (!pos[x]) pos[x] = i;
  }
  for (int i = 1; i <= q; i++) {
    int x; cin >> x;
    cout << pos[x] << ' ';
    for (int i = 1; i <= 50; i++) {
      if (pos[i] < pos[x]) pos[i]++;
    }
    pos[x] = 1;
  }
  cout << endl;
}
