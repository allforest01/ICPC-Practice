#include <bits/stdc++.h>
using namespace std;

#define int long long
#define Bit(x) (1ll << (x))
#define Get(x, k) (((x) >> (k)) & 1ll)
#define Xor(x, k) ((x) ^ (1ll << (k)))

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  vector<int> cnt(41);
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    for (int j = 0; j < 41; j++) {
      if (Get(x, j)) cnt[j]++;
    }
  }
  int sumb = 0, sumn = LLONG_MIN;
  for (int j = 40; j >= 0; j--) {
    if (Bit(j) > k) {
      sumb += cnt[j] * Bit(j);
      continue;
    }
    int w = n - cnt[j];
    if (Get(k, j)) {
      sumn = max(sumn + max(w, cnt[j]) * Bit(j), sumb + cnt[j] * Bit(j));
      sumb += max(w, cnt[j]) * Bit(j);
    }
    else {
      sumn += max(w, cnt[j]) * Bit(j);
      sumb += cnt[j] * Bit(j);
    }
  }
  cout << max(sumb, sumn) << '\n';
}
