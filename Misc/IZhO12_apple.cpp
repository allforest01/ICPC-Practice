#include <bits/stdc++.h>
using namespace std;

struct node {
  int val = 0, laz = 0;
  node *lf = NULL, *ri = NULL;
};

void chNode(node *&curNode) {
  if (curNode == NULL) {
    curNode = new node();
  }
}

struct SPT {
  int n; node rootNode;
  SPT(int n): n(n) {}
  void down(node* curNode, int l, int m, int r) {
    if (!curNode->laz) return;
    curNode->lf->val = m - l + 1;
    curNode->lf->laz = 1;
    curNode->ri->val = r - m;
    curNode->ri->laz = 1;
    curNode->laz = 0;
  }
  void update(node* curNode, int l, int r, int u, int v) {
    if (r < u || l > v) return;
    if (l >= u && r <= v) {
      curNode->val = r - l + 1;
      curNode->laz = 1;
      return;
    }
    int m = (l + r) / 2;
    chNode(curNode->lf);
    chNode(curNode->ri);
    down(curNode, l, m, r);
    update(curNode->lf, l, m, u, v);
    update(curNode->ri, m + 1, r, u, v);
    curNode->val = curNode->lf->val + curNode->ri->val;
  }
  int get(node* curNode, int l, int r, int u, int v) {
    if (r < u || l > v) return 0;
    if (l >= u && r <= v) {
      return curNode->val;
    }
    int m = (l + r) / 2;
    chNode(curNode->lf);
    chNode(curNode->ri);
    down(curNode, l, m, r);
    return get(curNode->lf, l, m, u, v) + get(curNode->ri, m + 1, r, u, v);
  }
  void update(int u, int v) {
    update(&rootNode, -n, n, u, v);
  }
  int get(int u, int v) {
    return get(&rootNode, -n, n, u, v);
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int q; cin >> q;
  SPT spt(1e9);
  int c = 0;
  while (q--) {
    int d, x, y;
    cin >> d >> x >> y;
    if (d == 1) {
      cout << (c = spt.get(x + c, y + c)) << '\n';
    }
    else {
      spt.update(x + c, y + c);
    }
  }
}