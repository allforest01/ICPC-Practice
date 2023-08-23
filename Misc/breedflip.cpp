#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("breedflip.in" , "r", stdin );
  freopen("breedflip.out", "w", stdout);
  int n; cin >> n;
  string s1, s2;
  cin >> s1 >> s2;
  s1 = '$' + s1;
  s2 = '$' + s2;
  int ans = 0;
  vector<int> mark(n + 1);
  for (int i = 1; i <= n; i++) {
    if (s1[i] != s2[i]) {
      if (!mark[i - 1]) ans++;
      mark[i] = 1;
    }
  }
  cout << ans << '\n';
}
