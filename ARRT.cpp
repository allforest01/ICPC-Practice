#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n; cin >> n;
  vector<int> a(n), b(n);
  for (auto &i : a) {
    cin >> i;
  }
  for (auto &i : b) {
    cin >> i;
  }
  int p = 0;
  for (int i = 1; i < n; i++) {
    int ti = (a[0] + b[i]) % n;
    int tp = (a[0] + b[p]) % n;
    if (ti < tp) {
      p = i;
    }
    else if (ti == tp) {
      int tni = (a[1] + b[(i + 1) % n]) % n;
      int tnp = (a[1] + b[(p + 1) % n]) % n;
      if (tni < tnp) {
        p = i;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << (a[i] + b[(p + i) % n]) % n << ' ';
  }
  cout << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
