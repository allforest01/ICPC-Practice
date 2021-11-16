#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  map<int,int> mem;
  for (int i = 0; i < n; i++) {
    int l, r; int v;
    cin >> l >> r >> v;
    mem[l] += v;
    mem[r] -= v;
  }
  vector<pair<int,int>> qry;
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    l--; r--;
    qry.push_back(make_pair(l, r));
    mem[l] += 0;
    mem[r] += 0;
  }
  vector<pair<int,int>> vec0(mem.begin(), mem.end());
  for (int i = 1; i < (int) vec0.size(); i++) {
    vec0[i].second += vec0[i - 1].second;
  }
  auto vec = vec0;
  for (int i = 1; i < (int) vec.size(); i++) {
    vec[i].second += vec0[i - 1].second * (vec0[i].first - vec0[i - 1].first - 1) + vec[i - 1].second;
  }
  for (auto &i : qry) {
    int pl = lower_bound(vec.begin(), vec.end(), make_pair(i.first , LLONG_MIN)) - vec.begin();
    int pr = lower_bound(vec.begin(), vec.end(), make_pair(i.second, LLONG_MIN)) - vec.begin();
    cout << vec[pr].second - vec[pl].second << '\n';
  }
}
