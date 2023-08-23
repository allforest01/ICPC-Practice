#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("blocks.in" , "r", stdin );
  freopen("blocks.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<int> res(26);
  for (int i = 0; i < n; i++) {
    string a, b;
    cin >> a >> b;
    vector<int> ca(26), cb(26);
    for (auto &c : a) ca[c - 'a']++;
    for (auto &c : b) cb[c - 'a']++;
    for (int j = 0; j < 26; j++) {
      res[j] += max(ca[j], cb[j]);
    }
  }
  for (int j = 0; j < 26; j++) {
    cout << res[j] << '\n';
  }
}
