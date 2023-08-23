#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
const int blockSize = sqrt(N);

vector<int> vadj[N];
unordered_set<int> sadj[N], ladj[N];
bool isLarge[N];

void addEdge(int u, int v) {
  if (!sadj[u].count(v)) {
    vadj[u].push_back(v);
    vadj[v].push_back(u);
    sadj[u].insert(v);
    sadj[v].insert(u);
  }
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    addEdge(u, v);
  }
  for (int i = 1; i <= n; i++) {
    if ((int) vadj[i].size() > blockSize) {
      isLarge[i] = 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    vector<int> v;
    for (auto &j : vadj[i]) {
      if (isLarge[j]) v.push_back(j);
    }
    for (int j = 0; j + 1 < (int) v.size(); j++)
    for (int k = j + 1; k < (int) v.size(); k++) {
      ladj[v[j]].insert(v[k]);
      ladj[v[k]].insert(v[j]);
    }
  }
  int q; scanf("%d", &q);
  while (q--) {
    int t, x, y;
    scanf("%d%d%d", &t, &x, &y);
    if (t == 1) {
      addEdge(x, y);
    }
    else {
      if (sadj[x].count(y)) {
        printf("YES\n");
        continue;
      }
      if (!isLarge[x] && !isLarge[y]) {
        if (vadj[x].size() > vadj[y].size()) {
          swap(x, y);
        }
        bool flag = 0;
        for (auto &i : vadj[x]) {
          if (sadj[i].count(y)) {
            flag = 1;
            break;
          }
        }
        printf(flag ? "YES" : "NO");
        putchar('\n');
      }
      else if ((!isLarge[x] && isLarge[y]) || (isLarge[x] && !isLarge[y])) {
        if (isLarge[x]) swap(x, y);
        bool flag = 0;
        for (auto &i : vadj[x]) {
          if (sadj[i].count(y)) {
            flag = 1;
            break;
          }
        }
        printf(flag ? "YES" : "NO");
        putchar('\n');
      }
      else {
        printf(ladj[x].count(y) ? "YES" : "NO");
        putchar('\n');
      }
    }
  }
}
