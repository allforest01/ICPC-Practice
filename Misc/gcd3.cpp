#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

struct node {
  int val, cnt; node *pl, *pr;
  node(): val(0), cnt(0), pl(nullptr), pr(nullptr) {}
};

struct PSeg {
  int n; node *root;
  PSeg(int n): n(n) {
    root = new node;
  }
  void update(node *&cur, int l, int r, int val, int cnt) {
    if (cur == nullptr) {
      cur = new node;
    }
    if (r < val || l > val) {
      return;
    }
    if (l == r) {
      cur->cnt += cnt;
      cur->val = (cur->cnt ? val : 0);
      return;
    }
    int m = (l + r) / 2;
    update(cur->pl, l, m, val, cnt);
    update(cur->pr, m + 1, r, val, cnt);
    cur->val = gcd(cur->pl->val, cur->pr->val);
  }
  void update(int val, int cnt) {
    update(root, 1, n, val, cnt);
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  PSeg ps(1000000000);
  int q; cin >> q;
  while (q--) {
    int t, x;
    cin >> t >> x;
    ps.update(x, (t == 1 ? 1 : -1));
    int res = ps.root->val;
    cout << (res ? res : 1) << '\n';
  }
}
