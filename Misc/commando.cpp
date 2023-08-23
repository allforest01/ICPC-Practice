#include <bits/stdc++.h>
using namespace std;

#define taskname "COMMANDO"

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
    insert(node, 1, 1e8, line);
  }
  ll query(ll x) {
    return query(node, 1, 1e8, x);
  }
};

int n;
ll a, b, c;
ll x[N], sum[N], dp[N];

ll sqr(ll x) {
  return x * x;
}

template<typename T>
void chmax(T &a, T b) {
  if (a < b) a = b;
}

void solve() {
  cin >> n >> a >> b >> c;
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
    sum[i] = sum[i - 1] + x[i];
  }
  memset(dp, 0x9f, sizeof(dp));
  LCT lct;
  for (int i = 1; i <= n; i++) {
    chmax(dp[i], max(0ll, lct.query(sum[i])) + a * sqr(sum[i]) + b * sum[i] + c);
    lct.insert(Line(-2 * a * sum[i], a * sqr(sum[i]) - b * sum[i] + dp[i]));
  }
  cout << dp[n] << '\n';
}

signed main() {
  ioset();
  solve();
}
