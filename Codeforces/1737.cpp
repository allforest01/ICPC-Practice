#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 200005;

int n, q, a[N];

struct Node {
  ll val; Node *pl, *pr;
  // Node() { pl = new Node; pr = new Node; }
  Node(ll val): val(val), pl(NULL), pr(NULL) {}
  Node(Node *pl, Node *pr): pl(pl), pr(pr) {
    val = pl->val + pr->val;
  }
};

struct PSeg {
  int n, k = 1, c = 0, time[N]; Node* root[N];
  Node* build(int l, int r) {
    if (l == r) return new Node(a[l]);
    int m = (l + r) / 2;
    return new Node(build(l, m), build(m + 1, r));
  }
  PSeg(int n): n(n) {
    root[0] = build(1, n);
    time[1] = 0;
  }
  Node* update(Node* prev, int l, int r, int pos, ll val) {
    if (l == r) return new Node(val);
    int m = (l + r) / 2;
    if (pos <= m) {
      return new Node(update(prev->pl, l, m, pos, val), prev->pr);
    }
    else {
      return new Node(prev->pl, update(prev->pr, m + 1, r, pos, val));
    }
  }
  void update(int kth, int pos, ll val) {
    root[++c] = update(root[time[kth]], 1, n, pos, val);
    time[kth] = c;
  }
  ll get(Node* cur, int l, int r, int u, int v) {
    if (r < u || l > v) return 0;
    if (l >= u && r <= v) return cur->val;
    int m = (l + r) / 2;
    return get(cur->pl, l, m, u, v) + get(cur->pr, m + 1, r, u, v);
  }
  ll get(int kth, int u, int v) {
    return get(root[time[kth]], 1, n, u, v);
  }
  void new_copy(int kth) {
    time[++k] = time[kth];
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  PSeg ps(n);
  while (q--) {
    int t; cin >> t;
    if (t == 1) {
      int k, a, x;
      cin >> k >> a >> x;
      ps.update(k, a, x);
    }
    else if (t == 2) {
      int k, a, b;
      cin >> k >> a >> b;
      cout << ps.get(k, a, b) << '\n';
    }
    else if (t == 3) {
      int k;
      cin >> k;
      ps.new_copy(k);
    }
  }
}
