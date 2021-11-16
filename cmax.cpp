#include <bits/stdc++.h>
using namespace std;

#define taskname "CMAX"

void ioset() {
  cin.tie(0)->sync_with_stdio(0);
  if (fopen(taskname".INP", "r")) {
    freopen(taskname".INP", "r", stdin );
    freopen(taskname".OUT", "w", stdout);
  }
}

typedef long long ll;

const int N = 100005;

struct Line {
  ll a, b;
  Line() { a = 0; b = -1e18; }
  Line(ll a, ll b): a(a), b(b) {}
  ll operator()(ll x) { return a * x + b; }
};

struct Node {
  Line line; Node *lef, *rig;
  Node() { lef = NULL; rig = NULL; }
};

struct LCT {
  Node *node;
  LCT() { node = new Node; }
  void insert(Node *&node, ll l, ll r, Line line) {
    if (l > r) return;
    if (node == NULL) node = new Node;
    if (l == r) {
      if (line(l) > node->line(l)) node->line = line;
      return;
    }
    ll m = (l + r) / 2;
    if (line.a < node->line.a) swap(line, node->line);
    if (line(m) > node->line(m)) {
      swap(line, node->line);
      insert(node->lef, l, m, line);
    }
    else insert(node->rig, m + 1, r, line);
  }
  ll query(Node *&node, ll l, ll r, ll x) {
    if (l > r || node == NULL) return -1e18;
    if (l == r) return node->line(x);
    ll m = (l + r) / 2;
    if (x < m) return max(node->line(x), query(node->lef, l, m, x));
    else return max(node->line(x), query(node->rig, m + 1, r, x));
  }
  void insert(Line line) {
    insert(node, -1e9, 1e9, line);
  }
  ll query(ll x) {
    return query(node, -1e9, 1e9, x);
  }
};

void solve() {
  int n; cin >> n;
  LCT lct;
  for (int i = 0; i < n; i++) {
    ll a, b;
    cin >> a >> b;
    Line line = Line(a, b);
    lct.insert(line);
  }
  int q; cin >> q;
  while (q--) {
    ll x; cin >> x;
    cout << lct.query(x) << '\n';
  }
}

signed main() {
  ioset();
  solve();
}
