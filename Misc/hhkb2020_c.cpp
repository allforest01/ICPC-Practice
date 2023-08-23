#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  set<int> s;
  int res = 0;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    s.insert(x);
    while (s.count(res)) res++;
    cout << res << '\n';
  }
}
