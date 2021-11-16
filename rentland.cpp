#include <bits/stdc++.h>
using namespace std;

#define taskname "RENTLAND"

void ioset() {
  if (fopen(taskname".INP", "r")) {
    freopen(taskname".INP", "r", stdin );
    freopen(taskname".OUT", "w", stdout);
  }
}

typedef long long ll;

const int N = 50005;
const ll INF = 1e18;

struct Line {
  ll a, b;
  Line() { a = 0; b = INF; }
  Line(ll a, ll b): a(a), b(b) {}
  ll operator()(ll x) { return a * x + b; }
};

struct Node {
  Line line;
  Node *lef, *rig;
  Node() { lef = rig = nullptr; }
};

struct LCT {
  Node *node;
  LCT() { node = new Node; }
  void insert(Node *&node, ll l, ll r, Line line) {
    if (l > r) return;
    if (node == nullptr) node = new Node;
    if (l == r) {
      if (line(l) < node->line(l)) node->line = line;
      return;
    }
    ll m = (l + r) / 2;
    if (line.a > node->line.a) swap(line, node->line);
    if (line(m) < node->line(m)) {
      swap(line, node->line);
      insert(node->lef, l, m, line);
    }
    else insert(node->rig, m + 1, r, line);
  }
  ll get(Node *&node, ll l, ll r, ll x) {
    if (l > r || node == nullptr) return INF;
    if (l == r) return node->line(x);
    ll m = (l + r) / 2;
    if (x < m) return min(node->line(x), get(node->lef, l, m, x));
    else return min(node->line(x), get(node->rig, m + 1, r, x));
  }
  void insert(Line line) {
    insert(node, 1, 1e6, line);
  }
  ll get(ll x) {
    return get(node, 1, 1e6, x);
  }
};

array<int,2> a[N];
ll c[N], d[N], dp[N];

void solve() {
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i][0] >> a[i][1];
  }
  sort(a + 1, a + n + 1);
  vector<int> pos;
  for (int i = 1; i <= n; i++) {
    while (pos.size() && a[i][1] >= a[pos.back()][1]) pos.pop_back();
    pos.push_back(i);
  }
  n = 0;
  for (auto &i : pos) {
    n++;
    c[n] = a[i][0];
    d[n] = a[i][1];
  }
  LCT lct;
  for (int i = 1; i <= n; i++) {
    lct.insert(Line(d[i], dp[i - 1]));
    dp[i] = lct.get(c[i]);
  }
  cout << dp[n] << '\n';
}

signed main() {
  ioset();
  solve();
}
