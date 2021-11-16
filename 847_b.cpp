#include <bits/stdc++.h>
using namespace std;

void compress(vector<int> &a, int n) {
  vector<pair<int,int>> vec(n);
  for (int i = 0; i < n; i++) {
    vec[i] = {a[i], i};
  }
  sort(vec.begin(), vec.end());
  for (int i = 0; i < n; i++) {
    a[vec[i].second] = i + 1;
  }
}

struct Bit {
  int n;
  vector<multiset<int>> bit;
  Bit(int n): n(n), bit(n + 1) {}
  void update(int i, int v, bool b) {
    for (; i <= n; i += i & -i) {
      if (b) bit[i].insert(v);
      else {
        auto it = bit[i].find(v);
        if (it != bit[i].end()) {
          bit[i].erase(it);
        }
      }
    }
  }
  int get(int i) {
    int v = INT_MAX;
    for (; i; i -= i & -i) {
      if (bit[i].size()) {
        v = min(v, *bit[i].begin());
      }
    }
    return v;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  compress(a, n);
  Bit bit(n);
  map<int,vector<int>> ans;
  for (int i = 0; i < n; i++) {
    int t = bit.get(a[i]);
    if (t != INT_MAX) {
      bit.update(a[*ans[t].rbegin()] + 1, t, 0);
      ans[t].push_back(i);
      bit.update(a[i] + 1, t, 1);
    }
    else {
      ans[i].push_back(i);
      bit.update(a[i] + 1, i, 1);
    }
  }
  for (auto &i : ans) {
    for (auto &j : i.second) cout << b[j] << ' ';
    cout << '\n';
  }
}
