#include <bits/stdc++.h>
using namespace std;

int query(int x, int y) {
  cout << "? " << x + 1 << ' ' << y + 1 << '\n';
  fflush(stdout);
  int t;
  cin >> t;
  return t;
}

int answer(vector<int> res) {
  cout << "! ";
  for (int i = 0; i < (int) res.size(); i++) {
    cout << res[i] << ' ';
  }
  cout << '\n';
  fflush(stdout);
  exit(0);
}

int main() {
  freopen("in", "r", stdin);
  int n; cin >> n;
  if (n == 1) {
    answer(vector<int>(1, 1));
  }
  vector<int> l(n), r(n), res(n);
  set<int> s;
  for (int i = 1; i <= n; i++) {
    s.insert(i);
  }
  for (int i = 0; i < n; i++) {
    r[i] = query(i, (i + 1) % n);
    l[(i + 1) % n] = query((i + 1) % n, i);
    if (r[i] < l[(i + 1) % n]) {
      res[(i + 1) % n] = l[(i + 1) % n];
      s.erase(res[(i + 1) % n]);
    }
    else {
      res[i] = r[i];
      s.erase(res[i]);
    }
  }
  vector<set<int>> pos(n);
  vector<vector<int>> val(n + 1);
  for (int i = 0; i < n; i++) {
    if (!res[i]) {
      for (int j = l[i]; j <= n; j += res[(i - 1 + n) % n]) {
        if (j && j % res[(i + 1) % n] == r[i] && s.count(j)) {
          pos[i].insert(j);
          val[j].push_back(i);
          // cout << i << ' ' << j << ' '  << pos[i].size() << '\n';
        }
      }
    }
  }
  queue<int> q;
  for (int i = 0; i < n; i++) {
    // cout << "size " << i << ' ' << pos[i].size() << '\n';
    if (pos[i].size() == 1) {
      res[i] = *pos[i].begin();
      // cout << "> " << i << ' ' << pos[i][0] << '\n';
      q.push(i);
    }
  }
  for (int i = 0; i < n; i++) {
    if (val[i].size() == 1) {
      res[val[i][0]] = i;
      q.push(val[i][0]);
    }
  }
  while (q.size()) {
    int i = q.front(); q.pop();
    for (auto &j : val[res[i]]) {
      pos[j].erase(res[i]);
      if (pos[j].size() == 1) {
        res[j] = *pos[j].begin();
        q.push(j);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (val[i].size()) {
      cout << "val[" << i << "]: ";
      for (auto &j : val[i]) cout << j << ' ';
      cout << '\n';
    }
  }
  for (int i = 1; i <= n; i++) {
    if (pos[i].size()) {
      cout << "pos[" << i << "]: ";
      for (auto &j : pos[i]) cout << j << ' ';
      cout << '\n';
    }
  }
  answer(res);
}