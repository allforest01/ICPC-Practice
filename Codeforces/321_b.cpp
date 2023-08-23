#include <bits/stdc++.h>
using namespace std;

// kill all case
int case1(vector<int> atk, vector<int> def, multiset<int> s) {
  sort(def.begin(), def.end());
  for (auto &i : def) {
    auto it = s.upper_bound(i);
    if (it == s.end()) return 0;
    s.erase(it);
  }
  sort(atk.begin(), atk.end());
  int ans = 0;
  for (auto &i : atk) {
    auto it = s.lower_bound(i);
    if (it == s.end()) return 0;
    ans += *it - i;
    s.erase(it);
  }
  for (auto &i : s) ans += i;
  return ans;
}

// remaining case
int case2(vector<int> atk, vector<int> def, multiset<int> s) {
  sort(atk.begin(), atk.end());
  int ans = 0;
  for (auto &i : atk) {
    if (!s.size()) return ans;
    auto it = prev(s.end());
    if (*it <= i) break;
    ans += *it - i;
    s.erase(it);
  }
  return ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<int> atk, def;
  for (int i = 0; i < n; i++) {
    string s; int x;
    cin >> s >> x;
    if (s == "ATK") atk.push_back(x);
    else def.push_back(x);
  }
  multiset<int> s;
  for (int i = 0; i < m; i++) {
    int x; cin >> x;
    s.insert(x);
  }
  cout << max(case1(atk, def, s), case2(atk, def, s)) << '\n';
}
