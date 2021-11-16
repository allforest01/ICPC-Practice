#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int succ[N], vst[N], deg[N];
int ans = 0;
vector<int> s;

void dfs(int i) {
  vst[i] = 1;
  s.push_back(i);
  int j = succ[i];
  if (!vst[j]) dfs(j);
  else {
    int cnt = 1;
    while (s.size() && s.back() != j) {
      s.pop_back();
      cnt++;
    }
    if (s.size() && s.back() == j) ans += cnt;
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("shuffle.in" , "r", stdin );
  freopen("shuffle.out", "w", stdout);
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> succ[i];
    deg[succ[i]]++;
  }
  vector<pair<int,int>> a;
  for (int i = 1; i <= n; i++) {
    a.push_back(make_pair(deg[i], i));
  }
  sort(a.begin(), a.end());
  for (auto &i : a) {
    if (!vst[i.second]) {
      dfs(i.second);
      s.clear();
    }
  }
  cout << ans << '\n';
}
