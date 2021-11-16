#include <bits/stdc++.h>
using namespace std;

const int maxVal = 100000;

int cnt[maxVal + 1][2];

int Main() {
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]][i % 2]++;
  }
  sort(a.begin(), a.end());
  int pos = 0, flag = 0;
  for (auto &i : a) {
    while (cnt[i][0] + cnt[i][1] > 0) {
      if (cnt[i][pos % 2]) {
        cnt[i][pos % 2]--;
        pos++;
      }
      else {
        flag = 1;
        break;
      }
    }
    if (flag) break;
  }
  cout << (flag ? "NO" : "YES") << '\n';
  for (auto &i : a) {
    cnt[i][0] = cnt[i][1] = 0;
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
