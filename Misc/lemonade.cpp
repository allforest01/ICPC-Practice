#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("lemonade.in" , "r", stdin );
  freopen("lemonade.out", "w", stdout);
  int n; cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  sort(a.begin(), a.end(), greater<int>());
  int cnt = 0;
  for (auto &i : a) {
    if (cnt <= i) cnt++;
  }
  cout << cnt << '\n';
}
