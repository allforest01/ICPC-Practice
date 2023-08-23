#include <bits/stdc++.h>
using namespace std;

#define taskname "CWALKWAY"

void ioset() {
  cin.tie(0)->sync_with_stdio(0);
  if (fopen(taskname".INP", "r")) {
    freopen(taskname".INP", "r", stdin );
    freopen(taskname".OUT", "w", stdout);
  }
}

typedef long long ll;

const int N = 1000005;
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
  ll query(Node *&node, ll l, ll r, ll x) {
    if (l > r || node == nullptr) return INF;
    if (l == r) return node->line(x);
    ll m = (l + r) / 2;
    if (x < m) return min(node->line(x), query(node->lef, l, m, x));
    else return min(node->line(x), query(node->rig, m + 1, r, x));
  }
  void insert(Line line) {
    insert(node, 1, 1e9, line);
  }
  ll query(ll x) {
    return query(node, 1, 1e9, x);
  }
};

ll a[N], dp[N];

ll sqr(ll x) {
  return x * x;
}

template<typename T>
void chmin(T &a, T b) {
  if (a > b) a = b;
}

void solve() {
  int n, c;
  cin >> n >> c;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  LCT lct;
  memset(dp, 0x3f, sizeof(dp)); dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    lct.insert(Line(-2 * a[i], dp[i - 1] + sqr(a[i])));
    dp[i] = lct.query(a[i]) + sqr(a[i]) + c;
  }
  cout << dp[n] << '\n';
}

signed main() {
  ioset();
  solve();
}
