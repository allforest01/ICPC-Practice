#include <bits/stdc++.h>
using namespace std;

#define taskname "SREC"

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
  Line() { a = 0; b = -INF; }
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
    if (l > r || node == nullptr) return -INF;
    if (l == r) return node->line(x);
    ll m = (l + r) / 2;
    if (x < m) return max(node->line(x), query(node->lef, l, m, x));
    else return max(node->line(x), query(node->rig, m + 1, r, x));
  }
  void insert(Line line) {
    insert(node, 1, 1e9, line);
  }
  ll query(ll x) {
    return query(node, 1, 1e9, x);
  }
};

int n;
ll x[N], y[N], a[N], dp[N];

template<typename T>
void chmax(T &a, T b) {
  if (a < b) a = b;
}

void solve() {
  cin >> n;
  vector<array<ll,3>> vec(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> vec[i][1] >> vec[i][0] >> vec[i][2];
  }
  sort(vec.begin() + 1, vec.end(), greater<array<ll,3>>());
  for (int i = 1; i <= n; i++) {
    y[i] = vec[i][0];
    x[i] = vec[i][1];
    a[i] = vec[i][2];
  }
  ll ans = 0;
  LCT lct;
  for (int i = 1; i <= n; i++) {
    dp[i] = max(0ll, lct.query(y[i])) + x[i] * y[i] - a[i];
    lct.insert(Line(-x[i], dp[i]));
    chmax(ans, dp[i]);
  }
  cout << ans << '\n';
}

signed main() {
  ioset();
  solve();
}
