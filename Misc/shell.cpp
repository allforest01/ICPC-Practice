#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("shell.in" , "r", stdin );
  freopen("shell.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<int> v(4);
  for (int i = 0; i < n; i++) {
    int a, b, g;
    cin >> a >> b >> g;
    swap(v[a], v[b]);
    v[g]++;
  }
  cout << max(v[1], max(v[2], v[3])) << '\n';
}
