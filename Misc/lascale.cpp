#include <bits/stdc++.h>
using namespace std;

const int N = 25;

int a[N];

int pow3(int n) {
  int ret = 1;
  for (int i = 1; i <= n; i++) {
    ret *= 3;
  }
  return ret;
}

int main() {
  int m; cin >> m;
  int n = 0;
  while (m) {
    a[n++] = m % 3;
    m /= 3;
  }
  vector<int> l, r;
  for (int i = 0; i < n; i++) {
    if (a[i] == 2) {
      l.push_back(pow3(i));
      a[i] = 0;
      a[i + 1]++;
    }
    else if (a[i] == 3) {
      a[i] = 0;
      a[i + 1]++;
    }
  }
  for (int i = 0; i <= n; i++) {
    if (a[i] == 1) {
      r.push_back(pow3(i));
    }
  }
  cout << l.size() << ' ';
  for (auto &i : l) cout << i << ' ';
  cout << '\n';
  cout << r.size() << ' ';
  for (auto &i : r) cout << i << ' ';
  cout << '\n';
}
