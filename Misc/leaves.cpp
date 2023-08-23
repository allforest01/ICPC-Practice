#include <bits/stdc++.h>
using namespace std;

#define taskname "nkleaves"

void ioset() {
  cin.tie(0)->sync_with_stdio(0);
  if (fopen(taskname".INP", "r")) {
    freopen(taskname".INP", "r", stdin );
    freopen(taskname".OUT", "w", stdout);
  }
}

typedef long long ll;

const int N = 100005;
const int M = 15;
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
    insert(node, 1, 1e8, line);
  }
  ll query(ll x) {
    return query(node, 1, 1e8, x);
  }
};

int n, m, a[N]; LCT lct[M];
ll sum1[N], sum2[N], dp[N][M];

template<typename T>
void chmin(T &a, T b) {
  if (a > b) a = b;
}

void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum1[i] = sum1[i - 1] + a[i];
    sum2[i] = sum2[i - 1] + a[i] * i;
  }
  memset(dp, 0x3f, sizeof(dp));
  for (int i = 1; i <= n; i++) {
    for (int k = 1; k <= min(i, m); k++) {
      if (k == 1) dp[i][k] = sum2[i] - sum1[i];
      else dp[i][k] = lct[k - 1].query(sum1[i]) + sum2[i];
      lct[k].insert(Line(-i, sum1[i - 1] * i - sum2[i - 1] + dp[i - 1][k]));
    }
  }
  cout << dp[n][m] << '\n';
}

signed main() {
  ioset();
  solve();
}
