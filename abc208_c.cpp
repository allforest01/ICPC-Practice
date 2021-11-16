#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  long long k;
  cin >> n >> k;
  vector<pair<int,int>> a(n);
  vector<long long> res(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
    res[i] = k / n;
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < k % n; i++) {
    res[a[i].second]++;
  }
  for (auto &i : res) {
    cout << i << '\n';
  }
}
