#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int q; cin >> q;
  vector<int> vec;
  while (q--) {
    int t; cin >> t;
    if (t == 0) {
      int x; cin >> x;
      vec.push_back(x);
    }
    else if (t == 1) {
      int p; cin >> p;
      cout << vec[p] << '\n';
    }
    else {
      vec.pop_back();
    }
  }
}
