#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("notlast.in" , "r", stdin );
  freopen("notlast.out", "w", stdout);
  int n; cin >> n;
  map<string,int> m;
  for (int i = 0; i < n; i++) {
    string s; int x;
    cin >> s >> x;
    m[s] += x;
  }
  vector<pair<int,string>> v;
  for (auto &i : m) {
    v.push_back(make_pair(i.second, i.first));
  }
  if (n == 1) {
    cout << v[0].second << '\n';
    return 0;
  }
  sort(v.begin(), v.end());
  for (int i = 1; i < (int) v.size(); i++) {
    if (v[i].first > v[i - 1].first) {
      if (i + 1 < n && v[i].first == v[i + 1].first) {
        cout << "Tie" << '\n';
        return 0;
      }
      cout << v[i].second << '\n';
      return 0;
    }
  }
  cout << "Tie" << '\n';
}
