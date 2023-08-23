#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  string s; cin >> s;
  bool flip = 0;
  int q; cin >> q;
  while (q --> 0) {
    int t, a, b;
    cin >> t >> a >> b;
    a--; b--;
    if (t == 1) {
      if (flip) {
        if (a < n) a += n;
        else a -= n;
        if (b < n) b += n;
        else b -= n;
      }
      swap(s[a], s[b]);
    }
    else flip ^= 1;
  }
  if (flip) {
    for (int i = n; i < s.size(); i++) {
      cout << s[i];
    }
    for (int i = 0; i < n; i++) {
      cout << s[i];
    }
    cout << '\n';
  }
  else cout << s << '\n';
}
