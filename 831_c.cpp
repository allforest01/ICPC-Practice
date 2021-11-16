#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, k;
  cin >> k >> n;
  vector<int> a(k), b(n), sum(k);
  for (int i = 0; i < k; i++) {
    cin >> a[i];
    sum[i] = a[i];
    if (i > 0) sum[i] += sum[i - 1];
  }
  for (auto &i : b) {
    cin >> i;
  }
  set<int> cnt;
  for (int j = 0; j < k; j++) {
    cnt.insert(b[0] - sum[j]);
  }
  for (int i = 1; i < n; i++) {
    set<int> tmp;
    for (int j = 0; j < k; j++) {
      if (cnt.count(b[i] - sum[j])) {
        tmp.insert(b[i] - sum[j]);
      }
    }
    cnt = tmp;
  }
  cout << cnt.size() << '\n';
}
