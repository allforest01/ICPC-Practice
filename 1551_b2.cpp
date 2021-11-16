#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  map<int,int> cnt;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  map<int,vector<int>> res;
  vector<int> rmn;
  for (auto &i : cnt) {
    if (i.second >= k) {
      for (int j = 1; j <= k; j++) {
        res[i.first].push_back(j);
      }
    }
    else {
      for (int j = 1; j <= i.second; j++) {
        rmn.push_back(i.first);
      }
    }
  }
  for (int i = 0; i < rmn.size() / k * k; i++) {
    res[rmn[i]].push_back(i % k + 1);
  }               
  for (int i = 0; i < n; i++) {
    if (!res[a[i]].size()) {
      cout << 0 << ' ';
    }
    else {
      cout << res[a[i]].back() << ' ';
      res[a[i]].pop_back();
    }
  }
  cout << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
