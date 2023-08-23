#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<array<int,2>> vec(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> vec[i][0] >> vec[i][1];
  }
  vector<bool> vst(n + 1);
  vector<array<int,2>> li;
  for (int i = 1; i <= n; i++) {
    if (vst[i]) continue;
    vst[i] = 1;
    int l = i;
    while (vec[l][0] != 0) {
      l = vec[l][0];
      vst[l] = 1;
    }
    int r = i;
    while (vec[r][1] != 0) {
      r = vec[r][1];
      vst[r] = 1;
    }
    li.push_back({l, r});
  }
  for (int i = 1; i < (int) li.size(); i++) {
    vec[li[i - 1][1]][1] = li[i][0];
    vec[li[i][0]][0] = li[i - 1][1];
  }
  for (int i = 1; i <= n; i++) {
    cout << vec[i][0] << ' ' << vec[i][1] << '\n';
  }
}
