#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, k, a[N];

int check(int x) {
  multiset<int> s;
  for (int i = 1; i <= n; i++) {
    s.insert(a[i]);
  }
  for (int i = 1; i <= k / 2; i++) {
    auto it = s.lower_bound(x);
    if (it == s.end()) return 0;
    if (*it - x > 0) s.insert(*it - x);
    s.erase(it);
  }
  int sum = 0;
  for (int i = 1; i <= k / 2; i++) {
    if (!s.size()) return sum;
    auto it = prev(s.end());
    int t = min(*it, x);
    sum += t;
    if (*it - t > 0) s.insert(*it - t);
    s.erase(it);
  }
  return sum;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("berries.in" , "r", stdin );
  freopen("berries.out", "w", stdout);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  for (int i = 1; i <= 1000; i++) {
    int t = check(i);
    ans = max(ans, t);
  }
  cout << ans << '\n';
}
