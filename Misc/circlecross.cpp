#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("circlecross.in" , "r", stdin );
  freopen("circlecross.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  string s;
  cin >> s;
  map<char,vector<int>> m;
  for (int i = 0; i < s.size(); i++) {
    m[s[i]].push_back(i);
  }
  int ans = 0;
  for (char c = 'A'; c <= 'Z'; c++) {
    map<int,int> cnt;
    for (int i = m[c][0] + 1; i <= m[c][1] - 1; i++) {
      cnt[s[i]]++;
    }
    for (auto &i : cnt) {
      if (i.second == 1) ans++;
    }
  }
  cout << ans / 2 << '\n';
}
