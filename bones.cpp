#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int a, b, c;
  cin >> a >> b >> c;
  map<int,int> cnt;
  for (int i = 1; i <= a; i++)
  for (int j = 1; j <= b; j++)
  for (int k = 1; k <= c; k++) {
    cnt[i + j + k]++;
  }
  int ans = cnt.begin()->first;
  for (auto &i : cnt) {
    if (i.second > cnt[ans]) ans = i.first;
  }
  cout << ans << '\n';
}
