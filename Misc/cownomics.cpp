#include <bits/stdc++.h>
using namespace std;

const int N = 205;

string a[N];

int main() {
  // freopen("cownomics.in" , "r", stdin );
  // freopen("cownomics.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n * 2; i++) {
    cin >> a[i];
  }
  int ans = 0;
  for (int j = 0; j < m; j++) {
    set<int> s;
    for (int i = 0; i < n; i++) {
      s.insert(a[i][j]);
    }
    bool flag = 0;
    for (int i = n; i < n * 2; i++) {
      if (s.count(a[i][j])) {
        flag = 1;
        break;
      }
    }
    if (!flag) ans++;
  }
  cout << ans << '\n';
}
