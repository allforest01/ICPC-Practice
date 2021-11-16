#include <bits/stdc++.h>
using namespace std;

void Main() {
  string s;
  cin >> s;
  vector<int> cnt(256);
  for (auto &i : s) {
    cnt[i]++;
  }
  string t;
  for (char c = 'a'; c <= 'z'; c++) {
    if (cnt[c]) t += c;
  }
  if (t.size() == 1) {
    cout << s <<'\n';
    return;
  }
  int re = 0;
  if (cnt[t[0]] < cnt[t[1]]) re = 1;
  auto check = [&](int m) -> string {
    string ret = "";
    int mav = max(cnt[t[0]], cnt[t[1]]);
    int q = cnt[t[0]] + cnt[t[1]] - mav;
    int len = cnt[t[0]] + cnt[t[1]], flag = 1;
    while (len) {
      int tm = min(m + flag, mav);
      len -= tm;
      mav -= tm;
      for (int i = 0; i < tm; i++) {
        ret += t[re];
      }
      flag = 0;
      if (!len) return ret;
      if (q > 0) {
        len--, q--;
        ret += t[1 - re];
      }
      else if (mav) return "";
    }
    return ret;
  };
  int l = 1, r = (int) s.size() - 1;
  string ans = "";
  while (l <= r) {
    int m = (l + r) / 2;
    string chk = check(m);
    if (chk.size()) {
      ans = chk;
      r = m - 1;
      cout << "m = " << m << ' ' << chk << '\n';
    }
    else l = m + 1;
  }
  string rev = ans;
  reverse(rev.begin(), rev.end());
  if (rev < ans) ans = rev;
  for (char c = 'a'; c <= 'z'; c++) {
    if (c != t[0] && c != t[1]) {
      for (int i = 0; i < cnt[c]; i++) {
        ans += c;
      }
    }
  }
  cout << ans << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
