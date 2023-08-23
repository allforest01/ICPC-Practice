#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n; cin >> n;
  vector<int> a(n);
  set<int> s;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    s.insert(i + 1);
  }
  vector<int> b(n), r(n + 1);
  for (int i = 0; i < n; i++) {
    if (s.count(a[i])) {
      b[i] = a[i];
      r[b[i]] = i;
      s.erase(a[i]);
    }
  }
  deque<int> d(s.begin(), s.end());
  for (int i = 0; i < n; i++) {
    if (!b[i]) {
      if (i + 1 == d.front()) {
        if (d.size() == 1) {
          int t = r[a[i]];
          swap(b[t], d.front());
        }
        else {
          d.push_back(d.front());
          d.pop_front();
        }
      }
      b[i] = d[0];
      r[b[i]] = i;
      d.pop_front();
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == b[i]) ans++;
  }
  cout << ans << '\n';
  for (int i = 0; i < n; i++) {
    cout << b[i] << ' ';
  }
  cout << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
