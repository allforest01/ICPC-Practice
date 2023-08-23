#include <bits/stdc++.h>
using namespace std;

void Main() {
  string s;
  cin >> s;
  map<char,int> cnt;
  for (int i = 0; i < (int) s.size(); i++) {
    cnt[s[i]]++;
  }
  int tot = 0, rmn = 0;
  for (auto &i : cnt) {
    if (i.second >= 2) {
      tot++;
    }
    else rmn++;
  }
  cout << tot + rmn / 2 << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
