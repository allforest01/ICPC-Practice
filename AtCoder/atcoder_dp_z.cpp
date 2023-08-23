#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 200005;
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

ll sqr(ll x) {
  return x * x;
}

int n;
ll c, h[N], dp[N];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> c;
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
  }
  LCT lct;
  for (int i = 1; i <= n; i++) {
    if (i == 1) dp[i] = 0;
    else dp[i] = lct.get(h[i]) + sqr(h[i]) + c;
    lct.insert(Line(-2 * h[i], dp[i] + sqr(h[i])));
  }
  cout << dp[n] << '\n';
}
