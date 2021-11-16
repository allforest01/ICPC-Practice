#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<pair<long long, int> > a(n);
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t >> a[i].first;
    a[i].second = i;
    sum += t;
  }
  sort(a.begin(), a.end(), greater<pair<long long, int> >());
  int cnt = 0;
  vector<long long> res(n);
  for (int i = 0; i < n; i++) {
    long long t = min(sum, a[i].first);
    sum -= t;
    if (!t) cnt++;
    res[a[i].second] = t;
  }
  cout << cnt << '\n';
  for (auto &i : res) cout << i << ' ';
  cout << '\n';
}
