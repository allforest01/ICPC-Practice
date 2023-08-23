#include <bits/stdc++.h>
using namespace std;

int d[1000];

int main() {
  freopen("lifeguards.in" , "r", stdin );
  freopen("lifeguards.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<pair<int,int>> v(n);
  for (auto &i : v) {
    cin >> i.first >> i.second;
    for (int j = i.first; j < i.second; j++) {
      d[j]++;
    }
  }
  int ans = 0;
  for (auto &i : v) {
    for (int j = i.first; j < i.second; j++) {
      d[j]--;
    }
    int cal = 0;
    for (int j = 0; j < 1000; j++) {
      if (d[j]) cal++;
    }
    ans = max(ans, cal);
    for (int j = i.first; j < i.second; j++) {
      d[j]++;
    }
  }
  cout << ans << '\n';
}
