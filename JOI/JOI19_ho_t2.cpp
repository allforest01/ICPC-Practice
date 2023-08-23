#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<pair<int,int>> a(n);
  for (auto &i : a) {
    cin >> i.second >> i.first;
  }
  vector<int> b(m);
  for (auto &i : b) {
    cin >> i;
  }
  sort(a.begin(), a.end(), greater<pair<int,int>>());
  sort(b.begin(), b.end(), greater<int>());
  int ans = 0;
  for (int i = 0, j = 0; i < (int) b.size(); i++) {
    while (j < (int) a.size() && a[j].second > b[i]) j++;
    if (j < (int) a.size() && a[j].second <= b[i]) {
      ans++;
      j++;
    }
  }
  cout << ans << '\n';
}
