#include <bits/stdc++.h>
using namespace std;

#define taskname "DCVA"

void ioset() {
  cin.tie(0)->sync_with_stdio(0);
  if (fopen(taskname".INP", "r")) {
    freopen(taskname".INP", "r", stdin );
    freopen(taskname".OUT", "w", stdout);
  }
}

typedef long long ll;

const int N = 100005;

int n, c;
int a[N], b[N], dp[N];

struct Line {
  ll a, b;
  Line() { a = 0; b = 1e18; }
  Line(ll a, ll b): a(a), b(b) {}
  ll operator()(ll x) { return a * x + b; }
};

struct Node {
  Line line;
  Node *lef, *rig;
  Node() { lef = nullptr; rig = nullptr; }
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
    if (l > r || node == nullptr) return 1e18;
    if (l == r) return node->line(x);
    ll m = (l + r) / 2;
    if (x < m) return min(node->line(x), get(node->lef, l, m, x));
    else return min(node->line(x), get(node->rig, m + 1, r, x));
  }
  void insert(Line line) {
    insert(node, -100, 100, line);
  }
  ll get(ll x) {
    return get(node, -100, 100, x);
  }
};

void solve() {
  cin >> n >> c;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  LCT lct;
  dp[1] = c;
  lct.insert(Line(b[1], dp[1]));
  for (int i = 2; i <= n; i++) {
    dp[i] = lct.get(a[i]);
    lct.insert(Line(b[i], dp[i]));
  }
  cout << dp[n] << '\n';
}

signed main() {
  ioset();
  solve();
}
