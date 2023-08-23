#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

void chmax(int &a, int b) {
  if (a < b) a = b;
}

int main() {
  freopen("triangles.in" , "r", stdin );
  freopen("triangles.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<pair<int,int>> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].x >> v[i].y;
  }
  int ans = 0;
  for (int i = 0; i < n; i++)
  for (int j = 0; j < n; j++)
  for (int k = 0; k < n; k++) {
    if (i == j || j == k || k == i) continue;
    if (v[j].x != v[i].x || v[k].y != v[i].y) continue;
    chmax(ans, abs(v[j].y - v[i].y) * abs(v[k].x - v[i].x));
  }
  cout << ans << '\n';
}
