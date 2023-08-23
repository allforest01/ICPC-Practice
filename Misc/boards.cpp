#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(),(x).end()

void chmin(int &a, int b) {
  if (a > b) a = b;
}

struct FW {
  int n; vector<int> bit, comp;
  void update(int i, int v) {
    i = lower_bound(all(comp), i) - comp.begin() + 1;
    for (; i <= n; i += i & -i) {
      chmin(bit[i], v);
    }
  }
  int get(int i) {
    i = lower_bound(all(comp), i) - comp.begin() + 1;
    int v = 3e9;
    for (; i; i -= i & -i) {
      chmin(v, bit[i]);
    }
    return v;
  }
  void compress() {
    sort(all(comp));
    comp.resize(unique(all(comp)) - comp.begin());
    n = comp.size();
    bit.resize(n + 1, 3e9);
  }
};

FW fw;
set<array<int,3>> q;

void update() {
  auto t = *q.begin();
  q.erase(q.begin());
  fw.update(t[1], t[2]);
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("boards.in" , "r", stdin );
  freopen("boards.out", "w", stdout);
  int n, p;
  cin >> n >> p;
  vector<array<int,4>> a(p);
  for (int i = 0; i < p; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    a[i] = {x1, y1, x2, y2};
    fw.comp.push_back(y1);
    fw.comp.push_back(y2);
  }
  fw.compress();
  sort(a.begin(), a.end());
  for (int i = 0; i < p; i++) {
    while (q.size() && (*q.begin())[0] <= a[i][0]) update();
    int cost = min(fw.get(a[i][1]), 0ll) + a[i][0] + a[i][1];
    q.insert({a[i][2], a[i][3], cost - a[i][2] - a[i][3]});
  }
  while (q.size()) update();
  cout << 2 * n + min(fw.get(n), 0ll) << '\n';
}
